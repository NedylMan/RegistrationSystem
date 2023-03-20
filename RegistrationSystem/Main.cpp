#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// Declaring functions
bool IsLoggedIn();
int FalseLogin();
int CorrectLogin();
void RegisterUser();




string UserName, Password, UN, PW;

bool IsLoggedIn()
{
	
	cout << " Please enter your username:";
	cin >> UserName;
	cout << "Hello again " << UserName << "! Now please enter your password : ";
	cin >> Password;

	ifstream read(UserName + ".txt");
	getline(read, UN);
	getline(read, PW);

	if (UN == UserName && PW == Password)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int FalseLogin()
{
	cout << "False Login!" << endl;
	system("PAUSE");
	return 0;
}

int CorrectLogin()
{
	cout << "Succesfully logged in!" << endl;
	system("PAUSE");
	return 1;
}


void RegisterUser()
{
	cout << " Please, select your username:";
	cin >> UserName;
	cout << "Hello again " << UserName << "! Now please select your password : ";
	cin >> Password;


	ofstream File;
	File.open(UserName + ".txt");
	File << UserName << endl << Password;
	File.close();
	


}

void main()
{
	int Choice;

	cout << "Hello and Welcome!" << endl << "To register write 1." //
		<< endl << "And write 2 in order to login." << endl << "Your choice: ";
	cin >> Choice;
	if (Choice == 1)
	{
		RegisterUser();
	}
	else if (Choice == 2)
	{
		bool Status = IsLoggedIn() ? CorrectLogin() : FalseLogin();
	}
	
}