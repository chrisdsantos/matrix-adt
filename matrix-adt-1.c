/////////////////////////////////
// MATRIX MULTIPLICATION - ADT, dynamic 2D array (class)
// author: Christopher Santos
// modified: 2/26/2016
//////

#include <iostream>
#include <ctime>
using namespace std;

class Matrix
{
    public:
        int rows;
        int cols;
        
        // *******************
        //  MATRIX FUNCTIONS
        // *******************        
        void define(int rows, int cols, bool randomize){
            this->rows = rows;
            this->cols = cols;
            double **newmat = new double*[this->rows];
        
            for(int i = 0; i < this->rows; i++){
                newmat[i] = new double[this->cols];
                for(int j = 0; j < this->cols; j++){
                    if(!randomize){
                        cout << "(" << i+1 << ", " << j+1 << ") = ";
                        cin >> newmat[i][j];
                    }
                    else{
                        newmat[i][j] = rand() % 100;
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
            for(int i = 0; i < this->rows; i++){
                for(int j = 0; j < this->cols; j++){
                        newmat.data[i][j] = this->data[i][j] + b.data[i][j];
                }
            }
            return newmat;
        }
        
        Matrix operator-(const Matrix& b){
            Matrix newmat;
            newmat.define(this->rows, this->cols, true);
            for(int i = 0; i < this->rows; i++){
                for(int j = 0; j < this->cols; j++){
                        newmat.data[i][j] = this->data[i][j] - b.data[i][j];
                }
            }
            return newmat;
        }
        
        Matrix operator*(const Matrix& b){
            Matrix newmat;
            newmat.define(this->rows, b.cols, true);
            for(int i = 0; i < this->rows; i++){
                for(int j = 0; j < b.cols; j++){
                    for(int k = 0; k < b.rows; k++){
                        newmat.data[i][j] = newmat.data[i][j] + (this->data[i][k] * b.data[k][j]);
                    }
                }
            }
            return newmat;
        }
        
    private:
        double **data;
};

int main() {
    //setup timer
    clock_t startTime;
    clock_t endTime;
    clock_t elapsedTime;
    double timeInSeconds;
    char choice;
    
    //declare matrices
    int rowsA;
    int colsA;
    int rowsB;
    int colsB;
    char randomize;
    bool israndom;
    
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
    cout << "randomize? (y/n): ";
    cin >> randomize;
    if(randomize == 'y') israndom = true;
    if(randomize == 'n') israndom = false;
    
    matrix1.define(rowsA, colsA, randomize);
    cout << "M1 = " << endl;
    matrix1.print();
    
    cout << "M2 row size: ";
    cin >> rowsB;
    cout << "M2 col size: ";
    cin >> colsB;
    cout << "randomize? (y/n): ";
    cin >> randomize;
    if(randomize == 'y') israndom = true;
    if(randomize == 'n') israndom = false;
    
    matrix2.define(rowsB, colsB, randomize);
    cout << "M2 = " << endl;
    matrix2.print();
    
    //define matrices
    matrix3.define(rowsA, colsB, true);
    matrix4.define(rowsA, colsB, true);
    matrix5.define(rowsA, colsB, true);
    
    //operate on matrices
    while(true){
        cout << "* MENU *" << endl;
        cout << "[a] addition" << endl;
        cout << "[s] subtraction" << endl;
        cout << "[m] multiplication" << endl;
        cout << "[q] quit" << endl;
        cout << "choice: ";
        cin >> choice;
        switch(choice){
            case 'a':
                if((rowsA != rowsB) || (colsA != colsB)){
                    cout << "* cannot add matrices with different dimensions." << endl;
                }
                startTime = clock();
                matrix3 = matrix1 + matrix2;
                endTime = clock();
                cout << "M3 = M1 + M2 = " << endl;
                matrix3.print();
                elapsedTime = endTime - startTime;
            break;
            case 's':
                if((rowsA != rowsB) || (colsA != colsB)){
                    cout << "* cannot subtract matrices with different dimensions." << endl;
                }
                startTime = clock();
                matrix4 = matrix1 - matrix2;
                endTime = clock();
                cout << "M4 = M1 - M2 = " << endl;
                matrix4.print();
                elapsedTime = endTime - startTime;
            break;
            case 'm':
                if(colsA != rowsB){
                    cout << "* incompatible matrices for multiplication. " << endl;
                }
                startTime = clock();
                matrix5 = matrix1 * matrix2;
                endTime = clock();
                cout << "M5 = M1 * M2 = " << endl;
                matrix5.print();
                elapsedTime = endTime - startTime;    
            break;
            case 'q':
                cout << "Program exited";
                exit(0);
            default:
            break;
        }
        timeInSeconds = elapsedTime / (double) CLOCKS_PER_SEC;
        cout << "TIME (microseconds): " << timeInSeconds*(.001) << endl;
    }
    return 0;
}