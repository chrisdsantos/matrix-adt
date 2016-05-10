#include <stdio.h>
#include <stdlib.h>
//#include <new>
using namespace std;

class matrix {
	int row;
	int col;
	int **array;
	public:
		matrix(int,int); //constuctor
		matrix(const matrix&); //constructor to copy a matrix
		~matrix(); //destructor
		void setElement(int r, int c, int e);
		int getElement (int r, int c);		
		void setColumn (int c, int a[]);
		int* getColumn (int c);
		void setRow (int r, int a[]);
		int* getRow (int r);
		matrix operator+(const matrix&);
};

matrix::matrix(int r, int c){ //defines the constructor to create a new matrix
	row = r;
	col = c;
	array = new int*[row];
	for (int i=0; i<row; i++){
		array[i] = new int[col];
		}
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			array[i][j] = 0;
		}
	}
};

matrix::matrix(const matrix& m){ //defines the copying constructor
	row = m.row;
	col = m.col;
	array = new int*[row];
	for (int i=0; i<row; i++){
		array[i] = new int[col];
		}
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			array[i][j] = m.array[i][j];
		}
	}
}

matrix::~matrix(){ //defines the destructor
	for (int i=0; i<row; i++){
		delete[] array[i];
		}
	delete[] array;
	};

void matrix::setElement(int r, int c, int e){
	array[r][c] = e;
};

int matrix::getElement(int r, int c){
	return array[r][c];
}

void matrix::setColumn(int c, int a[]){
	for (int i=0; i<row; i++){
		array [i][c] = a[i];
	}
}
	
int* matrix::getColumn(int c){
	int *output = new int[row];
	for (int i=0; i<row; i++){
		output[i] = array[i][c];
	}
	return output;
}	

void matrix::setRow(int r, int a[]){
	for(int i=0; i<col; i++){
		array[r][i] = a[i];
	}
}

int* matrix::getRow (int r){
	int *output = new int[col];
	for (int i=0; i<col; i++){
		output[i] = array[r][i];
	}
	return output;
}

matrix matrix::operator+(const matrix& m){
	// first, make sure matrices can be added. if not, return original matrix
	if (row != m.row || col != m.col){
		cerr << "Matrix sizes do not match. Mission impossible.";
		return (*this);
	}
	matrix new_mat(row,col);
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			new_mat.array[i][j] = array[i][j] + m.array[i][j];
		}
	}
	return new_mat;
}


int main()
{
	int r = 4;
	int c = 4;
	matrix matrixA(r,c);
	matrix matrixB(r,c);
	matrix matrixC(r,c);
	
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			matrixA.setElement(i,j,1);
			matrixB.setElement(i,j,2);
		}
	}
	
	cout << "matrixA" << endl;
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			cout << matrixA.getElement(i,j) << "\t";
		}
		cout << endl;
	}
	cout << endl;

	cout << "matrixB" << endl;
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			cout << matrixB.getElement(i,j) << "\t";
		}
		cout << endl;
	}
	cout << endl;
	
	cout << "matrixC before addition" << endl;
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			cout << matrixC.getElement(i,j) << "\t";
		}
		cout << endl;
	}
	cout << endl;	
	
	matrixC = matrixA + matrixB;
	
	cout << "matrixC after addition" << endl;
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			cout << matrixC.getElement(i,j) << "\t";
		}
		cout << endl;
	}
	cout << endl;	
}