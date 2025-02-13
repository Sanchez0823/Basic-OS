#include "auth.h" // Includes the AUTH_H header file.
#include <iostream>

// AuthenticateUser function definition
authenticateUser::authenticateUser(string userNameInput, string passwordInput) {
	// Asks user for username.
	cout << "Enter Username: ";
	cin >> userNameInput;
	// Asks user for password.
	cout << "Enter Password: ";
	cin >> passwordInput;
	/* Makes the private variables equal to the public variables.
	   The If statment checks if userName matches "admin",
	   and if password matches "password123". */
	if (userNameInput == userName  && passwordInput == password) {
		cout << "Logging in..." << endl;
		cout << "Welcome " << userNameInput << "!\n";
	}
	else { // If either the username or password do not match,
		// the following error message is thrown.
		cerr << "Username or password are incorrect." << endl
			<< "Please try again." << endl;
		// The unused code that displays username and password input.
		// For debugging purposes only.
		// 		cout << "EXPERIMENTAL:\n" << userName << endl;
		// 		cout << password << endl;
	}
}
