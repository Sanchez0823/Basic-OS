#ifndef AUTH_H
#define AUTH_H

#include <string>

using namespace std;

class authenticateUser {
private:
	string userName = "admin";
	string password = "password123";

public:
	authenticateUser(string userNameInput, string passwordInput);
};
#endif //AUTH_H
