#include "calculation.h"
#include<string>
#include<iostream>


void calculation::multiplication() {
	get_matrix1()->print_matrix();
	get_matrix2()->print_matrix();
	int first_matrix_rows = get_matrix1()->get_rows();
	int first_matrix_columns = get_matrix1()->get_columns();
	int second_matrix_columns = get_matrix2()->get_columns();

	get_matrix_result()->resize(first_matrix_rows, second_matrix_columns);

	for (int row = 0; row < first_matrix_rows; row++) {
		for (int column = 0; column < second_matrix_columns; column++) { 
			double result = 0;
			for (int each = 0; each < first_matrix_columns; each++) {
				double x = get_matrix1()->get_rc_data(row, each);
				double y = get_matrix2()->get_rc_data(each, column);
				double temp = x * y;
				result += temp;
			}
			get_matrix_result()->set_rc_data(row, column, result);
		}
	}
	cout << "��������˵Ľ��Ϊ��" << endl;
	get_matrix_result()->print_matrix();
}

//����Ϊǰ��(ע���������ȼ�������ʽֵ��Ϊ�㣩
//Ŀǰ��������Ϊ��ʱ������
void calculation::transpose() {
	//����������
	int nums = get_matrix1()->get_rows();
	//��������ʼ��Ϊ��λ��
	get_matrix_result()->resize(nums,nums);
	for (int i = 0; i < nums; i++) {
		get_matrix_result()->set_rc_data(i, i, 1.0);
	}
	//ÿ������ı���
	double multiple = 0.0;
	//���½�ȫΪ��
	for (int base = 0; base < nums - 1; base++) { /*�������ڵڼ���Ϊ������*/
	    //����Ϊ�㣬���ҷ����н��������Ϊ������������ѭ����������һ��ѭ��
		if (get_matrix1()->get_rc_data(base, base) == 0.0){
			int sign;
			if ((sign = get_matrix1()->change_for_not_zero_in_rows(base,true)) == -1)
				continue;
			else {
				get_matrix_result()->change_in_rows(base, sign);
			}
		}
		for (int current = base + 1; current < nums; current++) { /*���ƻ������µĵ�ǰ�н��м���*/
			multiple = get_matrix1()->get_rc_data(current, base) / get_matrix1()->get_rc_data(base, base);
			for (int each_in_row = 0; each_in_row < nums; each_in_row++) { /*����ÿһ����Ҫ�ı���������ÿһ�е�����ֵÿ�ζ���*/
				double temp = get_matrix1()->get_rc_data(current, each_in_row) - get_matrix1()->get_rc_data(base, each_in_row) * multiple;
				get_matrix1()->set_rc_data(current, each_in_row, temp);
				double temp_result = get_matrix_result()->get_rc_data(current, each_in_row) - get_matrix_result()->get_rc_data(base, each_in_row) * multiple;
				get_matrix_result()->set_rc_data(current, each_in_row, temp_result);
			}
		}
	}
	//���Ͻ�ȫΪ��
	for (int base = nums - 1; base > 0; base--) {
		//����Ϊ�㣬���ҷ����н��������Ϊ������������ѭ����������һ��ѭ��
		if (get_matrix1()->get_rc_data(base, base) == 0.0) {
			int sign;
			if ((sign = get_matrix1()->change_for_not_zero_in_rows(base, false)) == -1)
				continue;
			else {
				get_matrix_result()->change_in_rows(base, sign);
			}
		}
		for (int current = base - 1; current >= 0; current--) {
			multiple = get_matrix1()->get_rc_data(current, base) / get_matrix1()->get_rc_data(base, base);
			for (int each_in_row = 0; each_in_row < nums; each_in_row++) {
				double temp = get_matrix1()->get_rc_data(current, each_in_row) - get_matrix1()->get_rc_data(base, each_in_row) * multiple;
				get_matrix1()->set_rc_data(current, each_in_row, temp);
				double temp_result = get_matrix_result()->get_rc_data(current, each_in_row) - get_matrix_result()->get_rc_data(base, each_in_row) * multiple;
				get_matrix_result()->set_rc_data(current, each_in_row, temp_result);
			}
		}
	}
	//�Խ��߷ǡ�1��Ԫ�ػ�Ϊ��1��
	for (int base = 0; base < nums; base++) {
		double base_num = get_matrix1()->get_rc_data(base, base);
		get_matrix1()->set_rc_data(base, base, 1.0);
		for (int each_in_row = 0; each_in_row < nums; each_in_row++) {
			double temp_result = get_matrix_result()->get_rc_data(base, each_in_row) / base_num;
			get_matrix_result()->set_rc_data(base, each_in_row, temp_result);
		}
	}
	//get_matrix1()->print_matrix();
	cout << "�����Ϊ��" << endl;
	get_matrix_result()->print_matrix();
}

void calculation::getDataFromFile(string file_path) {
	ifstream in;
	in.open(file_path);
	if (!in.is_open())
	{
		cout << "open file failed!" << endl;
	}
	string str;
	//��ǰ��ȡ�ڶ�������ı�־
	bool sign_for_second_matrix = false;
	while (!in.eof())
	{
		getline(in, str);
		//���eof���һ���жϵ����ظ���ȡ������
		if (!in.fail()) {
			if (sign_for_second_matrix) {
				matrix2.set_data(split_and_tod(str));
			}
			else {
				if (str != "*") {
					matrix1.set_data(split_and_tod(str));
				}
				else {
					sign_for_second_matrix = true;
				}
			}
		}
	}
	in.close();
}

vector<double> calculation::split_and_tod(string str) {
	//��ȡ���ж��ŵ�λ��
	vector<int> nums;
	nums.push_back(-1);
	int comma = -1;
	do {
		comma = str.find(",", comma + 1);
		if (comma != -1) {
			nums.push_back(comma);
		}
	} while (comma != -1);
	nums.push_back(str.length());
	//��ȡ���е�����
	vector<double> strs;
	for (unsigned int i = 0; i < nums.size() - 1; i++) {
		strs.push_back(stod(str.substr(nums[i] + 1, nums[i + 1] - nums[i] - 1)));
	}
	return strs;
}