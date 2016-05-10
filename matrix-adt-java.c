#include <iostream>
using namespace std;

class Matrix
{
    public:
        int rows;
        int cols;
        
        // *******************
        //  MATRIX FUNCTIONS
        // *******************        
        void define(int rows, int cols, bool zeros){
            this->rows = rows;
            this->cols = cols;
            double **newmat = new double*[this->rows];
        
            for(int i = 0; i < this->rows; i++){
                newmat[i] = new double[this->cols];
                for(int j = 0; j < this->cols; j++){
                    if(!zeros){
                        cout << "(" << i+1 << ", " << j+1 << ") = ";
                        cin >> newmat[i][j];
                    }
                    else{
                        newmat[i][j] = 0;
                    }
                }
            }
            this->data = newmat;
        }
        
        void print(){
            for(int i = 0; i < this->rows; i++){
                for(int j = 0; j < this->cols; j++){
                        cout << this->data[i][j];
                        cout << " ";
                }
                cout << endl;
            }        
            cout << endl;
        }
        
        // *******************
        //  MATRIX OPERATIONS
        // *******************

        Matrix operator+(const Matrix& b){
            Matrix newmat;
            newmat.define(this->rows, this->cols, true);
            
            if((this->rows != b.rows) || (this->cols != b.cols)){
                cout << "* cannot add matrices with different dimensions." << endl;
            }
            else{
                for(int i = 0; i < this->rows; i++){
                    for(int j = 0; j < this->cols; j++){
                            newmat.data[i][j] = this->data[i][j] + b.data[i][j];
                    }
                }
                return newmat;
            }
        }
        
        Matrix operator-(const Matrix& b){
            Matrix newmat;
            newmat.define(this->rows, this->cols, true);
            
            if((this->rows != b.rows) || (this->cols != b.cols)){
                cout << "* cannot subtract matrices with different dimensions." << endl;
            }
            else{
                for(int i = 0; i < this->rows; i++){
                    for(int j = 0; j < this->cols; j++){
                            newmat.data[i][j] = this->data[i][j] - b.data[i][j];
                    }
                }
                return newmat;
            }
        }
        
        Matrix operator*(const Matrix& b){
            Matrix newmat;
            newmat.define(this->rows, b.cols, true);
            
            if(this->cols != b.rows){
                cout << "* incompatible matrices for multiplication. " << endl;
            }
            else{
                for(int i = 0; i < this->rows; i++){
                    for(int j = 0; j < b.cols; j++){
                        for(int k = 0; k < b.rows; k++){
                            newmat.data[i][j] = newmat.data[i][j] + (this->data[i][k] * b.data[k][j]);
                        }
                    }
                }
                return newmat;
            }            
            // if((this->rows != b.rows) || (this->cols != b.cols)){
            //     cout << "* cannot subtract matrices with different dimensions." << endl;
            //     exit(0);
            // }
            // else{
            //     for(int i = 0; i < this->rows; i++){
            //         for(int j = 0; j < this->cols; j++){
            //                 newmat.data[i][j] = this->data[i][j] - b.data[i][j];
            //         }
            //     }
            //     return newmat;
            // }
        }
        
        // Matrix operator*(double **mat1, int rowsA, int colsA, double **mat2,  int rowsB, int colsB, double **mat3){
        //     if(colsA != rowsB){
        //         cout << "* incompatible matrices for multiplication. " << endl;
        //         return;
        //     }
        //     else{
        //         for(int i = 0; i < rowsA; i++){
        //             for(int j = 0; j < colsB; j++){
        //                 for(int k = 0; k < rowsB; k++){
        //                     mat3[i][j] = mat3[i][j] + (mat1[i][k] * mat2[k][j]);
        //                 }
        //             }
        //         }
        //     }
        //     printmatrix(rowsA, colsB, mat3);
        //     return;
        // }
        
    private:
        double **data;
};

int main() {
    //declare matrices
    int rowsA;
    int colsA;
    int rowsB;
    int colsB;
    
    Matrix matrix1;
    Matrix matrix2;
    Matrix matrix3;
    Matrix matrix4;
    Matrix matrix5;

    //input matrix sizes
    cout << "M1 row size: ";
    cin >> rowsA;
    cout << "M1 col size: ";
    cin >> colsA;
    
    matrix1.define(rowsA, colsA, false);

    cout << "M2 row size: ";
    cin >> rowsB;
    cout << "M2 col size: ";
    cin >> colsB;
    
    matrix2.define(rowsB, colsB, false);
    
    //define matrices
    matrix3.define(rowsA, colsB, true);
    matrix4.define(rowsA, colsB, true);
    matrix5.define(rowsA, colsB, true);
    
    //operate on matrices
    //matrix3 = matrix1 + matrix2;
    //matrix3.print();
    //matrix4 = matrix1 - matrix2;
    //matrix4.print();
    matrix5 = matrix1 * matrix2;
    matrix5.print();

    return 0;
}