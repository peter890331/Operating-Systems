#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

// maximum size of matrix
#define MAX 200 

void multi(int C[MAX][MAX],int A[MAX][MAX],int B[MAX][MAX]) {
    for(int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++) {
            C[i][j] = 0;
            for (int k = 0; k < MAX; k++) {
                A[i][k] = 3.5 *i - 6.6 *k;
                B[k][j] = 6.6+8.8 *k - 3.5 *j;
                C[i][j] += A[i][k] * B[k][j];
			}
        }
}

// Main Code
int main() {	
	clock_t start, end;
	start = clock();
    int A[MAX][MAX];
    int B[MAX][MAX];
    int C[MAX][MAX];
    multi(C, A, B);
    cout <<"\n"
		 <<"Multiplication of A and B:"<<"\n";
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            cout << C[i][j]<<"\t";
        cout <<"\n";
    }
    end = clock();
    
 	//Displaying the execution time   
    double diff = end - start; // ms
    cout <<"\n"<<"execution time:"<<"\n"<<diff<<" ms";
    return 0;
}
