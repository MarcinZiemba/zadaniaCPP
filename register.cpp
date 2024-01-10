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
	    
	    while(1){
    		cout << "Login (minimum 8 znakow): ";
    		cin >> login;
    		cout << "Haslo (minimum 8 znakow): ";
    		cin >> haslo;
    		
    		if(login.length() >= 8 && haslo.length() >= 8){
    		    break;
    		}
    		cout << "Login lub haslo jest za krotkie podaj inne." << endl;
	    }

		ofstream outfile;
		outfile.open("dane_uzytkownikow.txt", ios_base::app);
		outfile << login << " " << haslo << endl;
		
		cout << "Konto zostalo utworzone poprawnie, zostałeś zalogowany." << endl;
	}

	return 0;
}