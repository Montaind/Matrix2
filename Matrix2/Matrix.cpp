#include "Matrix.h"
void Matrix::constr()
{
	A = new double* [n_];
	for (int i = 0; i < n_; i++) {
		A[i] = new double[m_];
	}
}

void Matrix::Display()
{
	for (int i = 0; i < n_; i++) {
		for (int j = 0; j < m_; j++) {
			std::cout << A[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

Matrix::Matrix() : n_(0), m_(0) {
	constr();
}

Matrix::Matrix(int n, int m)
{
	n_ = n;
	m_ = m;
	constr();
}

Matrix::Matrix(Matrix& m)
{
	n_ = m.n_;
	m_ = m.m_;
	constr();
	for (int i = 0; i < n_; i++) {
		for (int j = 0; j < m_; j++) {
			A[i][j] = m.A[i][j];
		}
	}
}

Matrix::~Matrix()
{
	destr();
}

void Matrix::destr()
{
	for (int i = 0; i < n_; i++) {
		delete[] A[i];
	}
	delete[] A;
}

void Matrix::randome()
{
	for (int i = 0; i < n_; i++) {
		for (int j = 0; j < m_; j++) {
			A[i][j] = rand() % 101;
		}
	}
}

void Matrix::plusM(Matrix& m)
{
	for (int i = 0; i < n_; i++) {
		for (int j = 0; j < m_; j++) {
			A[i][j] += m.A[i][j];
		}
	}
}

void Matrix::minusM(Matrix& m)
{
	for (int i = 0; i < n_; i++) {
		for (int j = 0; j < m_; j++) {
			A[i][j] -= m.A[i][j];
		}
	}
}

void Matrix::multiM(double& a)
{
	for (int i = 0; i < n_; i++) {
		for (int j = 0; j < m_; j++) {
			A[i][j] *= a;
		}
	}
}

void Matrix::divM(double& a)
{
	for (int i = 0; i < n_; i++) {
		for (int j = 0; j < m_; j++) {
			A[i][j] /= a;
		}
	}
}

Matrix& Matrix::operator+(Matrix& other)
{
	Matrix& result = *new Matrix(*this);
	result.plusM(other);
	return result;
}

Matrix& Matrix::operator-(Matrix& other)
{
	Matrix& result = *new Matrix(*this);
	result.minusM(other);
	return result;
}

Matrix& Matrix::operator*(double a)
{
	Matrix& result = *new Matrix(*this);
	result.multiM(a);
	return result;
}

Matrix& Matrix::operator/(double a)
{
	Matrix& result = *new Matrix(*this);
	result.divM(a);
	return result;
}

Matrix& Matrix::operator=(Matrix& other)
{
	return *new Matrix(other);
}
