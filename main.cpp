#include "auth.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string userNameInput;
    string passwordInput;
    cout << "Booting up Basic OS...\n";
    cout << "Boot up process complete.\n";
    authenticateUser authenticateUser(userNameInput, passwordInput);
    return 0;
}
