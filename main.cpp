#include "auth.h" // Includes auth header file
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Declares the following strings in the main.cpp
    // so the authenticateUser function works.
    string userNameInput;
    string passwordInput;
    // Boot up message.
    cout << "Booting up operating system...\n";
    cout << "Boot up process complete.\n";
    cout << "---------- Welcome to Basic OS v0.1 ----------\a\n";
    // authenticateUser function and class call.
    authenticateUser authenticateUser(userNameInput, passwordInput);
    return 0; // Returns 0 when the program exits.
}
