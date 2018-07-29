#include "matrix.h"
#include<fstream>


class calculation {
private:
	matrix matrix_result;
	matrix matrix1;
	matrix matrix2;
	vector<double> split_and_tod(string str);
public:
	calculation() {}
	~calculation() {}
	matrix *get_matrix1() {
		return &matrix1;
	}
	matrix *get_matrix2() {
		return &matrix2;
	}
	matrix *get_matrix_result() {
		return &matrix_result;
	}
	//get data from file
	void getDataFromFile(string file_path);
	//¾ØÕó³Ë·¨
	void multiplication();
	//¾ØÕó×ªÖÃ
	void transpose();
};