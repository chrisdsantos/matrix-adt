/////////////////////////////////
// MATRIX MULTIPLICATION - non-ADT (static 2D array)
// author: Christopher Santos
// modified: 2/26/2016
//////

#include <iostream>
#include <ctime>
using namespace std;

const int MAX = 5;

void clearmatrix(double mat1[MAX][MAX]){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            mat1[i][j] = 0;
        }
    }
}

void printmatrix(double mat1[MAX][MAX]){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
                cout << mat1[i][j];
                cout << " ";
        }
        cout << endl;
    }        
}

void addition(double mat1[MAX][MAX], double mat2[MAX][MAX], double mat3[MAX][MAX]){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
                mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    printmatrix(mat3);
}

void subtraction(double mat1[MAX][MAX], double mat2[MAX][MAX], double mat3[MAX][MAX]){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
                mat3[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    printmatrix(mat3);
}

void multiplication(double mat1[MAX][MAX], double mat2[MAX][MAX], double mat3[MAX][MAX]){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            mat3[i][j] = 0;
            for(int k = 0; k < 5; k++){
                mat3[i][j] = mat3[i][j] + (mat1[i][k] * mat2[k][j]);
            }
        }
    }
    printmatrix(mat3);
}
    
int main() {
    clock_t startTime;
    clock_t endTime;
    clock_t elapsedTime;
    double timeInSeconds;
    char choice;
    
    double mat1[5][5] = 
    {
        {1.0, 2.0, 3.0, 4.0, 5.0},
        {2.0, 2.0, 2.0, 2.0, 2.0},
        {3.0, 1.0, 1.0, 1.0, 3.0},
        {0.0, 0.0, 2.0, 3.0, -2.0},
        {4.0, 4.0, -4.0, 0.0, 0.0}
    };
    
    double mat2[5][5] = 
    {
        {1.0, 0.0, 0.0, 0.0, 0.0},
        {1.0, 2.0, 1.0, 2.0, 1.0},
        {0.0, 0.0, 1.0, 0.0, 0.0},
        {1.0, 1.0, 1.0, 1.0, 1.0},
        {2.0, 2.0, -2.0, 2.0, 2.0}
    };
    
    double mat3[5][5] = 
    {
        {0.0, 0.0, 0.0, 0.0, 0.0},
        {0.0, 0.0, 0.0, 0.0, 0.0},
        {0.0, 0.0, 0.0, 0.0, 0.0},
        {0.0, 0.0, 0.0, 0.0, 0.0},
        {0.0, 0.0, 0.0, 0.0, 0.0}
    };
    
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
                startTime = clock();
                addition(mat1, mat2, mat3);
                endTime = clock();
                elapsedTime = endTime - startTime;
            break;
            case 's':
                startTime = clock();
                subtraction(mat1, mat2, mat3);
                endTime = clock();
                elapsedTime = endTime - startTime;
            break;
            case 'm':
                startTime = clock();
                multiplication(mat1, mat2, mat3);
                endTime = clock();
                elapsedTime = endTime - startTime;    
            break;
            case 'q':
                cout << "Program exited";
                exit(0);
            default:
            break;
        }
        timeInSeconds = elapsedTime / (double) CLOCKS_PER_SEC;
        cout << "TIME(sec): " << timeInSeconds << endl;
    }
    return 0;
}