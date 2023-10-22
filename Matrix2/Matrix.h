#pragma once
#include <iostream>


class Matrix {
public:		
	Matrix();
	Matrix(int n, int m);
	Matrix(Matrix& m);
	~Matrix();
	void Display();
	void randome();
	void plusM(Matrix& m);
	void minusM(Matrix& m);
	void multiM(double& a);
	void divM(double& a);
	Matrix& operator+(Matrix& other);
	Matrix& operator-(Matrix& other);
	Matrix& operator*(double a);
	Matrix& operator/(double a);
	Matrix& operator=(Matrix& other);
private:
	void constr();
	void destr();
private:
	int n_;
	int m_;
	double** A;
};