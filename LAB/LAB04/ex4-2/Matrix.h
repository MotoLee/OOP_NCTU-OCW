// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

/* Write class definition for Matrix */
class Matrix{
	private:
		int dim;
		int** element;
	public:
		~Matrix();
		void assignDimension(int);
		void assignElements();
		void printMatrix();
		void assignMatrix(Matrix);
		void transposeMatrix();
		Matrix addMatrix(Matrix);
		Matrix subtractMatrix(Matrix);
		Matrix multiplyMatrix(Matrix);
};
#endif
