#include <cstdlib>
#include <intersight/model/matrix.h>

#include <vector>

using namespace intersight;

template <typename T> Matrix<T>::Matrix() : num_rows_(3), num_cols_(3) {
  matrix_ = std::vector<std::vector<T>>(num_rows_, std::vector<T>(num_cols_));
}

template <typename T>
Matrix<T>::Matrix(int num_rows, int num_cols)
    : num_rows_(num_rows), num_cols_(num_cols) {
  matrix_ = std::vector<std::vector<T>>(num_rows_, std::vector<T>(num_cols_));
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &matrix) const {
  if (num_rows_ != matrix.num_rows_ || num_cols_ != matrix.num_cols_)
    exit(-1);

  Matrix<T> sum(num_rows_, num_cols_);

  for (int i = 0; i < num_rows_; i++) {
    for (int j = 0; j < num_cols_; j++) {
      sum.matrix_[i][j] = matrix_[i][j] + matrix.matrix_[i][j];
    }
  }

  return sum;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &matrix) const {
  if (num_cols_ != matrix.num_rows_)
    exit(-1);

  Matrix<T> product(num_rows_, matrix.num_cols_);

  for (int i = 0; i < num_rows_; i++) {
    for (int j = 0; j < matrix.num_cols_; j++) {
      T value = 0;
      for (int k = 0; k < num_cols_; k++)
        value += matrix_[i][k] * matrix.matrix_[k][j];

      product.matrix_[i][j] = value;
    }
  }

  return product;
}

template <typename T>
bool Matrix<T>::operator==(const Matrix<T> &matrix) const {
  if (num_rows_ != matrix.num_rows_ && num_cols_ != matrix.num_cols_)
    return false;

  for (int i = 0; i < num_rows_; i++) {
    for (int j = 0; j < matrix.num_cols_; j++) {
      if (matrix_[i][j] != matrix.matrix_[i][j])
        return false;
    }
  }

  return true;
}

template <typename T> int Matrix<T>::get_num_rows() const { return num_rows_; }

template <typename T> int Matrix<T>::get_num_cols() const { return num_cols_; }

template <typename T>
const std::vector<std::vector<T>> &Matrix<T>::get_matrix() const {
  return matrix_;
}

template class intersight::Matrix<float>;
template class intersight::Matrix<double>;
template class intersight::Matrix<long double>;
