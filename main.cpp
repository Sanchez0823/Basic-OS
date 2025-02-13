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
    cout << "Booting up Basic OS...\n";
    cout << "Boot up process complete.\n";
    // authenticateUser function and class call.
    authenticateUser authenticateUser(userNameInput, passwordInput);
    return 0; // Returns 0 when the program exits.
}
