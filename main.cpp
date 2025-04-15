#include "auth.h" // Includes auth header file
#include "virtual_memory.h" // new virtual memory file

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // Declares the following strings in the main.cpp
    // so the authenticateUser function works.
    string userNameInput;
    string passwordInput;
    // Boot up message.
    cout << "Booting up operating system...\n";
    cout << "Boot up process complete.\n";
    cout << "---------- Welcome to Basic OS v0.2 ----------\a\n";
    // authenticateUser function and class call.
    authenticateUser authenticateUser(userNameInput, passwordInput);

    // virtual memory function
    int virtualMemorySize = 64;   // in KB
    int physicalMemorySize = 32;  // in KB
    int pageSize = 4;             // in KB

    // Create VirtualMemory instance
    virtualMemory virtualMemory(virtualMemorySize, physicalMemorySize, pageSize);

    // Initialize page tables for processes
    virtualMemory.initializePageTable(1); // Process ID 1
    virtualMemory.initializePageTable(2); // Process ID 2

    // Display page tables for processes
    virtualMemory.displayPageTable(1);
    virtualMemory.displayPageTable(2);
    virtualMemory.displayTLB(1);
    virtualMemory.displayTLB(2);

    // Simulate address translation
    int virtualAddress = 12; // Example virtual address
    int physicalAddress = virtualMemory.translateAddress(1, virtualAddress, READ);
    if (physicalAddress != -1) {
        cout << "Virtual Address: " << virtualAddress
            << "\nTranslated to Physical Address: " << physicalAddress << endl;
    }

    return 0; // Returns 0 when the program exits.
}
