#include "matrix.h"
#include<iostream>

int matrix::get_columns() {
    return _matrix[0].size();
}

int matrix::get_rows() {
    return _matrix.size();
}

void matrix::set_rc_data(int row,int column,double data) {
    _matrix[row][column] = data;
}

double matrix::get_rc_data(int row,int column) {
    double temp = _matrix[row][column];
    return temp;
}

void matrix::set_data(vector<double> temp) {
    this->_matrix.push_back(temp);
}

void matrix::print_matrix()
{
    for (int j = 0; j < this->_matrix.size(); j++)
    {
        vector<double> row = this->_matrix[j];
        for (int i = 0; i < row.size(); i++)
        {
            cout << row[i] << endl;
        }
    }
}
