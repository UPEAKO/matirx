#include <vector>
#include <string>
using namespace std;


class matrix
{
  private:
  //the struture of matix make up of vector(two dimensions)
  vector<vector<double> > _matrix;
  public:
  //create matrix
  matrix(){}
  ~matrix(){}
  int get_rows();
  int get_columns();
  void set_rc_data(int row,int column,double data);
  double get_rc_data(int row,int column);
  void set_data(vector<double> temp);
  void print_matrix();
};