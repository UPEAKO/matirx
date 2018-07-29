#include "matrix.h"
#include<iomanip>
#include<iostream>

int matrix::get_columns() {
	return _matrix[0].size();
}

int matrix::get_rows() {
	return _matrix.size();
}

void matrix::resize(int m, int n) {
	_matrix.resize(m, vector<double>(n));
}

void matrix::set_rc_data(int row, int column, double data) {
	_matrix[row][column] = data;
}

double matrix::get_rc_data(int row, int column) {
	double temp = _matrix[row][column];
	return temp;
}

void matrix::set_data(vector<double> temp) {
	this->_matrix.push_back(temp);
}

void matrix::print_matrix()
{
	//cout << "请设置输出精度: ";
	int preci = 15;
	//cin >> preci;
	cout << "********************************************" << endl;
	cout.precision(preci);
	for (unsigned int j = 0; j < this->_matrix.size(); j++)
	{
		vector<double> row = this->_matrix[j];
		for (unsigned int i = 0; i < row.size(); i++)
		{
			cout<<left<<setw(preci) << row[i];
			if (i != (row.size()-1))
				cout<< ",  ";
		}
		cout << endl;
	}
	cout << "********************************************" << endl;
}

int matrix::change_for_not_zero_in_rows(int base,bool up) {
	int nums = _matrix.size();
	if (up) {
		for (int sign = base + 1; sign < nums; sign++) {
			if (_matrix[sign][base] != 0.0) {
				for (int each_in_row = 0; each_in_row < nums; each_in_row++) {
					double temp = _matrix[base][each_in_row];
					_matrix[base][each_in_row] = _matrix[sign][each_in_row];
					_matrix[sign][each_in_row] = temp;
				}
				return sign;
			}
		}
		return -1;
	}
	else {
		for (int sign = base; sign >= 0; sign--) {
			if (_matrix[sign][base] != 0.0) {
				for (int each_in_row = 0; each_in_row < nums; each_in_row++) {
					double temp = _matrix[base][each_in_row];
					_matrix[base][each_in_row] = _matrix[sign][each_in_row];
					_matrix[sign][each_in_row] = temp;
				}
				return sign;
			}
		}
		return -1;
	}
}

void matrix::change_in_rows(int up, int down) {
	int nums = _matrix.size();
	for (int each_in_row = 0; each_in_row < nums; each_in_row++) {
		double temp = _matrix[up][each_in_row];
		_matrix[up][each_in_row] = _matrix[down][each_in_row];
		_matrix[down][each_in_row] = temp;
	}
}