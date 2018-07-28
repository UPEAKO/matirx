#include "calculation.h"
#include<iostream>

int main() {
    calculation calculation;
    calculation.getDataFromFile("./matrix.txt");
    calculation.get_matrix1()->print_matrix();
    calculation.get_matrix2()->print_matrix();
    cout<<"******************"<<endl;
    calculation.multiplication();
    return 0;
}