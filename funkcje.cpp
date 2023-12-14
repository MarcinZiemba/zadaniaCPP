#include <iostream>
#include <vector>
#include <cmath>

#include "funkcje.h"

using namespace std;

double logN(int num) {
	return log(num);
}

float odchylenieSt(vector<int> tab) {
	int tabSize = tab.size();
	int average = 0;
	float result = 0;

	for (int i = 0; i < tabSize; i++) average += tab[i];
	average /= tabSize;

	for (int i = 0; i < tabSize; i++) result += pow((tab[i] - average), 2);
	result /= tabSize;

	result = sqrt(result);

	return result;
}

float expon(int num) {
	return exp(num);
}