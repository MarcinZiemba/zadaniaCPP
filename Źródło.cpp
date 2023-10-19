#include <iostream>
#include <string>

using namespace std;

struct Product {
	string name;
	int volume;
};

void bubbleSort(Product arr[], int n);
int kmToMiles(int k);
int main() {
	Product products[10];
	int km;

	for (int i = 0; i < 10; i++) {
		cout << "Podaj nazwe produktu: ";
		cin >> products[i].name;
		cout << "Podaj cene produktu:";
		cin >> products[i].volume;
	}

	bubbleSort(products, 10);

	for (int i = 0; i < 10; i++) {
		cout << products[i].name   << endl;
		cout << products[i].volume << endl;
	}

	cout << "Podaj kilometry:" ;
	cin >> km;

	km = kmToMiles(km);

	cout << km;

	return 0;
}

void bubbleSort(Product arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already 
		// in place 
		for (j = 0; j < n - i - 1; j++) {
			if ((arr[j].volume) > (arr[j + 1].volume)) {
				swap(arr[j], arr[j + 1]);
			}
		}
}

int kmToMiles(int k) {
	return 0.539956 * k;
}