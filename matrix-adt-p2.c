/////////////////////////////////
// MATRIX MULTIPLICATION - non-ADT, dynamic 2D array (pointer to pointer)
// author: Christopher Santos
// modified: 2/26/2016
//////

#include <iostream>
#include <ctime>
using namespace std;

double** defmatrix(int rows, int cols, bool randomize){
    double **newmat = new double*[rows];

    for(int i = 0; i < rows; i++){
        newmat[i] = new double[cols];
        for(int j = 0; j < cols; j++){
            if(!randomize){
                cout << "(" << i+1 << ", " << j+1 << ") = ";
                cin >> newmat[i][j];
            }
            else{
                newmat[i][j] = rand() % 100;
            }
        }
    }
    return newmat;
}

void printmatrix(int rows, int cols, double **mat1){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
                cout << mat1[i][j];
                cout << " ";
        }
        cout << endl;
    }        
    cout << endl;
}

// *******************
//  MATRIX OPERATIONS
// *******************

void addition(double **mat1, int rowsA, int colsA, double **mat2,  int rowsB, int colsB, double **mat3){
    if((rowsA != rowsB) || (colsA != colsB)){
        cout << "* cannot add matrices with different dimensions." << endl;
        return;
    }
    for(int i = 0; i < rowsA; i++){
        for(int j = 0; j < colsA; j++){
                mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    printmatrix(rowsA, colsA, mat3);
    return;
}

void subtraction(double **mat1, int rowsA, int colsA, double **mat2,  int rowsB, int colsB, double **mat3){
    if((rowsA != rowsB) || (colsA != colsB)){
        cout << "* cannot substract matrices with different dimensions." << endl;
        return;
    }
    for(int i = 0; i < rowsA; i++){
        for(int j = 0; j < colsA; j++){
                mat3[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    printmatrix(rowsA, colsA, mat3);
    return;
}

void multiplication(double **mat1, int rowsA, int colsA, double **mat2,  int rowsB, int colsB, double **mat3){
    if(colsA != rowsB){
        cout << "* incompatible matrices for multiplication. " << endl;
        return;
    }
    else{
        for(int i = 0; i < rowsA; i++){
            for(int j = 0; j < colsB; j++){
                for(int k = 0; k < rowsB; k++){
                    mat3[i][j] = mat3[i][j] + (mat1[i][k] * mat2[k][j]);
                }
            }
        }
    }
    printmatrix(rowsA, colsB, mat3);
    return;
}
    
int main() {
    int rowsA;
    int colsA;
    int rowsB;
    int colsB;
    char randomize;
    bool israndom;
    
    double **mat1;
    double **mat2;
    double **mat3;
    double **mat4;
    double **mat5;
    
    clock_t startTime;
    clock_t endTime;
    clock_t elapsedTime;
    double timeInSeconds;
    
    char choice;
    
    cout << "M1 row size: ";
    cin >> rowsA;
    cout << "M1 col size: ";
    cin >> colsA;
    cout << "randomize? (y/n): ";
    cin >> randomize;
    if(randomize == 'y') israndom = true;
    if(randomize == 'n') israndom = false;
    
    mat1 = defmatrix(rowsA, colsA, israndom);
    cout << "M1 = " << endl;
    printmatrix(rowsA, colsA, mat1);
    
    cout << "M2 row size: ";
    cin >> rowsB;
    cout << "M2 col size: ";
    cin >> colsB;
    cout << "randomize? (y/n): ";
    cin >> randomize;
    if(randomize == 'y') israndom = true;
    if(randomize == 'n') israndom = false;
    
    mat2 = defmatrix(rowsB, colsB, israndom);
    cout << "M1 = " << endl;
    printmatrix(rowsB, colsB, mat2);
    
    mat3 = defmatrix(rowsA, colsB, true); //sum
    mat4 = defmatrix(rowsA, colsB, true); //difference
    mat5 = defmatrix(rowsA, colsB, true); //product

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
                addition(mat1, rowsA, colsA, mat2, rowsB, colsB, mat3);
                endTime = clock();
                cout << "M3 = M1 + M2 = " << endl;
                elapsedTime = endTime - startTime;
            break;
            case 's':
                if((rowsA != rowsB) || (colsA != colsB)){
                    cout << "* cannot subtract matrices with different dimensions." << endl;
                }
                startTime = clock();
                subtraction(mat1, rowsA, colsA, mat2, rowsB, colsB, mat4);
                endTime = clock();
                cout << "M4 = M1 - M2 = " << endl;
                elapsedTime = endTime - startTime;
            break;
            case 'm':
                if(colsA != rowsB){
                    cout << "* incompatible matrices for multiplication. " << endl;
                }
                startTime = clock();
                multiplication(mat1, rowsA, colsA, mat2, rowsB, colsB, mat5);
                endTime = clock();
                cout << "M5 = M1 * M2 = " << endl;
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
    
    delete mat1;
    delete mat2;
    delete mat3;
    delete mat4;
    delete mat5;
    
    return 0;
}