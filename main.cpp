#include "calculation.h"
#include<iostream>

int main() {
	calculation calculation;
	int sign = 1;
	cout << "�����������1\n����ת������2" << endl;
	cin >> sign;
	if (sign == 1) {
		calculation.getDataFromFile("./multiply.txt");
		calculation.multiplication();
	}
	else {
		calculation.getDataFromFile("./Transpose.txt");
		calculation.transpose();
	}
	//system("pause");
	return 0;
}