#include "virtual_memory.h"
#include <iostream>

using namespace std;

// Constructor
virtualMemory::virtualMemory(int virtualMemorySize, int physicalMemorySize, int pageSize)
    : virtualMemorySize(virtualMemorySize), physicalMemorySize(physicalMemorySize), pageSize(pageSize) {
    numPages = virtualMemorySize / pageSize;  // Calculates number of virtual pages
    numFrames = physicalMemorySize / pageSize; // Calculates number of physical frames
}

// Initialize page table for a process
void virtualMemory::initializePageTable(int pid) {
    vector<pageTableAddress> pageTable;

    // Initialize page table entries
    for (int i = 0; i < numPages; ++i) {
        bool valid = (i < numFrames);  // Mark pages within physical memory as valid
        int frameNumber = valid ? i : -1; // Assign frame numbers for valid pages
        bool dirty = false;           // Initialize dirty bit to false
        AccessMode accessMode = (i % 2 == 0) ? READ : WRITE;
        pageTable.emplace_back(valid, frameNumber, dirty, accessMode);
    }

    processPageTables[pid] = pageTable;  // Associate page table with the process ID
    processTLBs[pid] = unordered_map<int, int>();
    cout << "Page table initialized for Process ID: " << pid << endl;
}

// Simulate address translation
int virtualMemory::translateAddress(int pid, int virtualAddress, AccessMode mode) {
    if (processPageTables.find(pid) == processPageTables.end()) {
        cerr << "Error: Process ID not found!" << endl;
        return -1;
    }

    int pageNumber = virtualAddress / pageSize; // Calculate page number
    int offset = virtualAddress % pageSize;    // Calculate offset

    if (pageNumber >= numPages) {
        cerr << "Error: Invalid virtual address" << endl;
        return -1;
    }

    // Checks for TLBs
    auto& tlb = processTLBs[pid];
    if (tlb.find(pageNumber) != tlb.end()) {
        cout << "TLB hit: Page " << pageNumber << endl;
        return tlb[pageNumber] * pageSize + offset;
    }

    const auto& pageTable = processPageTables[pid];
    const pageTableAddress& entry = pageTable[pageNumber];

    if (!entry.valid) {
        cerr << "Page fault: Page is not in physical memory!" << endl;
        return -1; // Simulate page fault
    }

    if (entry.accessMode != mode) {
        cerr << "Access violation: Illegal " << (mode == READ ? "READ" : "WRITE") << " access!" << endl;
        return -1;
    }

    tlb[pageNumber] = entry.frameNum;

    int physicalAddress = entry.frameNum * pageSize + offset;
    return physicalAddress;
}

// Display page table for a process
void virtualMemory::displayPageTable(int pid) const {
    if (processPageTables.find(pid) == processPageTables.end()) {
        cerr << "Error: Process ID not found" << endl;
        return;
    }

    const auto& pageTable = processPageTables.at(pid);
    cout << "Page Table for Process ID: " << pid << endl;
    cout << "Page Number | Valid | Frame Number | Dirty | Access Mode" << endl;
    for (size_t i = 0; i < pageTable.size(); ++i) {
        cout << i << " \t\t " << pageTable[i].valid
            << " \t " << pageTable[i].frameNum
            << " \t       " << pageTable[i].dirty
            << "  \t" << (pageTable[i].accessMode == READ ? "READ" : "WRITE") << endl;
        cout << endl;
    }
}

void virtualMemory::displayTLB(int pid) const {
    if (processTLBs.find(pid) == processTLBs.end()) {
        cerr << "Error: Process ID not found!" << endl;
        return;
    }

    const auto& tlb = processTLBs.at(pid);
    cout << "TLB for Process ID: " << pid << endl;
    cout << "Page Number | Frame Number" << endl;
    for (const auto& entry : tlb) {
        cout << entry.first << " | " << entry.second << endl;
    }
}
