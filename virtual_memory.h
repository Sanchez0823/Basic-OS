#ifndef VIRTUAL_MEMORY_H
#define VIRTUAL_MEMORY_H

#include <iostream>
#include <map>	// Used for implementing the page addresses
#include <string>#ifndef VIRTUAL_MEMORY_H
#define VIRTUAL_MEMORY_H

#include <iostream>
#include <map>	// Used for implementing the page addresses
#include <string>
#include <vector>
#include <unordered_map>

using namespace std; // reduces the use of std::

enum AccessMode {READ, WRITE};

class pageTableAddress {
public:
	bool valid, dirty;
	int frameNum;
	
	AccessMode accessMode; // page protection

	pageTableAddress(bool valid, int frameNum, bool dirty, AccessMode accessMode)
		: valid(valid), frameNum(frameNum), dirty(dirty), accessMode(accessMode) {}
};

// Renamed class virtualAddressSpace to virtualMemory for ease
class virtualMemory {

private:
	int virtualMemorySize, physicalMemorySize; // memory size
	int pageSize, numPages, numFrames; // frames and pages

	map<int, vector<pageTableAddress>> processPageTables;
	map<int, unordered_map<int, int>> processTLBs;

public:

	virtualMemory(int virtualMemorySize, int physicalMemorySize, int pageSize);
	
	int translateAddress(int pid, int virtualAddress, AccessMode mode);

	// Process ID (pid)
	void initializePageTable(int pid);
	void displayPageTable(int pid) const;
	void displayTLB(int pid) const;
};

#endif // !VIRTUAL_MEMORY_H

#include <fstream>

using namespace std; // reduces the use of std::

class virtualAddressSpace {

public:
	//private:

	// Since the highest address index is 15, then 

	// Physical Addresses
	map<int, string> physicalPageNumber = { {8, "0x0000"}, {9, "0x0007"}, {10, "0x0011"},
	{11, "0x0015"}, {12, "0x0019"}, {13, "0x0023"}, {14, "0x0027"}, {15, "0x0031"} };

	// public

	// Page offset
	map<int, string> pageOffset = { {0, "0x000"}, {1, "0x002"}, {2, "0x004"},
	{3, "0x006"}, {4, "0x008"}, {5, "0x010"}, {6, "00012"}, {7, "0x014"} };
	
	// Virtual Addresses
	map<int, string> virtualPageNumber = { {8, "0x0000"}, {9, "0x0004"}, {10, "0x0008"},
	{11, "0x0012"}, {12, "0x0016"}, {13, "0x0020"}, {14, "0x0024"}, {15, "0x0028"} };

	// virtualPageNumber = physicalPageNumber;

	// opens the file
	void readConfig(string fileName, string line);

};

#endif // VIRTUAL_MEMORY_H
