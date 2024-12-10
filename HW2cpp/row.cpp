#include <bits/stdc++.h>
#include <time.h>

using namespace std;

// maximum size of matrix
#define MAX 200 

int A[MAX][MAX];
int B[MAX][MAX];
int C[MAX][MAX];
int step_i = 0;

void* multi(void* arg) {
	int core = step_i++;
	
	// Each thread computes 1/MAX of matrix multiplication
	for (int i = core * MAX / MAX; i < (core + 1) * MAX / MAX; i++)
		for (int j = 0; j < MAX; j++)
			for (int k = 0; k < MAX; k++) {
                A[i][k] = 3.5 *i - 6.6 * k;
                B[k][j] = 6.6+8.8 *k - 3.5 *j;
                C[i][j] += A[i][k] * B[k][j];
			}
}

// Main Code
int main() {
	clock_t start, end;
	start = clock();
	//creating threads
	pthread_t threads[MAX];

	for (int i = 0; i < MAX; i++) {
		int* p;
		pthread_create(&threads[i], NULL, multi, (void*)(p));
	}

	for (int i = 0; i < MAX; i++)
		//join threads
		pthread_join(threads[i], NULL);	

	// Displaying the multiplication matrix
	cout << "\n"
		 << "Multiplication of A and B:" << "\n";
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
			cout << C[i][j] << " ";		
		cout << "\n";
	}
	end = clock();
	
	//Displaying the execution time
    double diff = end - start; // ms
    cout <<"\n"<<"execution time:"<<"\n"<<diff<<" ms";
	return 0;
}
