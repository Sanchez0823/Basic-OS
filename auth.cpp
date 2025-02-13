#include "auth.h"
#include <iostream>
#include <string>
using namespace std;

authenticateUser::authenticateUser(string userNameInput, string passwordInput) {
	cout << "Enter Username: ";
	cin >> userNameInput;
	cout << "Enter Password: ";
	cin >> passwordInput;
	userName = userNameInput;
	password = passwordInput;
	if (userName == "admin" && password == "password123") {
		cout << "Logging in..." << endl;
		cout << "Welcome " << userNameInput << "!\n";
	}
	else {
		cout << "Username or password are incorrect." << endl
			<< "Please try again." << endl;
		// The unused code 		     
		// 		cout << "EXPERIMENTAL:\n" << userName << endl;
		// 		cout << password << endl;
	}
}
