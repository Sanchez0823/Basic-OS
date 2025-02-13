#ifndef AUTH_H
#define AUTH_H
//Defines the auth.h header file.

#include <string> // Allows the string variable
using namespace std;

class authenticateUser { 
//Class authenticateUser with private and public declarations
private:
	// These private variable declaration contain the
	// correct username and password.
	string userName = "admin";
	string password = "password123";

public:
	// Function declaration for authenticateUser
	authenticateUser(string userNameInput, string passwordInput);
};
#endif //AUTH_H
