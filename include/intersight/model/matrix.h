#ifndef INTERSIGHT_MODEL_MATRIX_H_
#define INTERSIGHT_MODEL_MATRIX_H_

#include <ostream>
#include <vector>

namespace intersight {

template <typename T> class Matrix {
public:
  Matrix();
  Matrix(int, int);

  Matrix<T> operator+(const Matrix<T> &) const;
  Matrix<T> operator*(const Matrix<T> &) const;
  bool operator==(const Matrix<T> &) const;

  int get_num_rows() const;
  int get_num_cols() const;
  const std::vector<std::vector<T>> &get_matrix() const;

private:
  int num_rows_;
  int num_cols_;
  std::vector<std::vector<T>> matrix_;
};

template <typename T>
std::ostream &operator<<(std::ostream &ostream, const Matrix<T> &matrix) {
  const std::vector<std::vector<T>> &matrix_ = matrix.get_matrix();

  for (int i = 0; i < matrix.get_num_rows(); i++) {
    for (int j = 0; j < matrix.get_num_cols(); j++) {
      ostream << matrix_[i][j] << ' ';
    }
    ostream << '\n';
  }
  return ostream;
}

} // namespace intersight

#endif // !INTERSIGHT_MODEL_MATRIX_H_
