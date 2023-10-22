#include "Matrix.h"

int main() {
	srand(time(0));
	Matrix& A = *new Matrix(3, 3);
	std::cout << "A Matrix: " << "\n\n";
	A.randome();
	A.Display();
	std::cout << "\n\n\n";
	Matrix& B = *new Matrix(A);
	
	std::cout << "B Matrix: " << "\n\n";
	B.Display();
	std::cout << "\n\n";
	B.plusM(A);
	std::cout << "B Matrix: " << "\n\n";
	B.Display();
	std::cout << "\n\n\n";
	std::cout << "A Matrix: " << "\n\n";
	A.Display();

	Matrix& C = A * 5;
	std::cout << "\n\n\n";
	std::cout << "C Matrix: " << "\n\n";
	C.Display();

	
	delete& A;
	delete& B;
}