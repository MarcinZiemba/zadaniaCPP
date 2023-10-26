#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int decision;
	string login, haslo;

	cout << "-------- Lodowka --------" << endl;
	cout << "Zeby sie zarejestrowc napisz 1." << endl;
	cin >> decision;


	if (decision == 1) {
		cout << "Login (minimum 8 znakow): ";
		cin >> login;
		cout << "Haslo (minimum 8 znakow): ";
		cin >> haslo;

		ofstream outfile;
		outfile.open("dane_uzytkownikow.txt", ios_base::app);
		outfile << "test";
	}

	return 0;
}