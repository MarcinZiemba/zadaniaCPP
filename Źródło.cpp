#include <iostream>
#include <vector>

#include "funkcje.h"

using namespace std;

int main() {
	vector<int> tab = { 1, 4, 12, 8 };

	cout << logN(3) << endl;

	cout << odchylenieSt(tab) << endl;

	cout << expon(3) << endl;

	return 0;
}

//dodaj tak¹ funkcjê x^(x-1)
