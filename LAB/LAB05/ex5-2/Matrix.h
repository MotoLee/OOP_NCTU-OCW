// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

/* Write class definition for Matrix */
class Matrix{
	private:
		int dim;
		int** element;
	public:
		Matrix();
		Matrix(int n);
		Matrix(const Matrix &m);
		~Matrix();
		void assignDimension(int n);
		void assignElements();
		void printMatrix();
		void transposeMatrix();
		void multiplyMatrix(const Matrix &a, const Matrix &b);
};
#endif
