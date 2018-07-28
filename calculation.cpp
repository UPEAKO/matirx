#include "calculation.h"
#include<iostream>


void calculation::multiplication() {
    int first_matrix_rows = get_matrix1()->get_rows();
    int first_matrix_columns = get_matrix1()->get_columns();
    for (int row = 0; row < first_matrix_rows; row++) {
        for (int column = 0; column < first_matrix_columns; column++) {
            double result = get_matrix1()->get_rc_data(row,column) * get_matrix2()->get_rc_data(column,row);
            get_matrix_result()->set_rc_data(row,column,result);
        }
    }
    //cout<<get_matrix_result()->get_rc_data(1,2)<<endl;
}

void calculation::getDataFromFile(string file_path) {
    ifstream in;
    in.open(file_path);
    if (!in.is_open())
    {
        cout << "open file failed!" << endl;
    }
    string str;
    //当前读取第二个矩阵的标志
    bool sign_for_second_matrix = false;
    while (!in.eof())
    {
        getline(in, str);
        //解决eof最后一次判断导致重复读取的问题
        if (!in.fail()) {
            if (sign_for_second_matrix) {
                matrix2.set_data(split_and_tod(str));
            } else {
                if (str != "+") {
                    matrix1.set_data(split_and_tod(str));
                } else {
                    sign_for_second_matrix = true;
                }
            }
        }
    }
    in.close();
}

vector<double> calculation::split_and_tod(string str) {
    //获取所有逗号的位置
    vector<int> nums;
    nums.push_back(-1);
    int comma = -1;
    do {
        comma = str.find(",", comma+1);
        if (comma != -1) {
            nums.push_back(comma);
        }
    } while(comma != -1);
    nums.push_back(str.length());
    //截取所有的数据
    vector<double> strs;
    for (int i = 0; i < nums.size()-1; i++) {
        strs.push_back(stod(str.substr(nums[i]+1, nums[i+1]-nums[i]-1)));
    }
    return strs;
}