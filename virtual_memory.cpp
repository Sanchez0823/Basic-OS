#include <iostream>

#include "virtual_memory.h"

virtualAddressSpace::readConfig(string fileName, string line) {
    string filename = "config.txt";
    ifstream file(fileName);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
    else {
        std::cerr << "Configuaration file not found " << fileName << std::endl;
    }
}