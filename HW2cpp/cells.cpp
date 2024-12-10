#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;
#define MAX 200 
  
  
//Each thread computes single element in the resultant matrix
void *mult(void* arg) {
    int *data = (int *)arg;
    int k = 0, i = 0;
      
    int x = data[0];
    for (i = 1; i <= x; i++)
           k += data[i]*data[i+x];
      
    int *p = (int*)malloc(sizeof(int));
         *p = k;
         
    pthread_exit(p);
}
  
// Main Code
int main() {
  	clock_t start, end;
	start = clock();
	
    int A[MAX][MAX]; 
    int B[MAX][MAX]; 
    int max = MAX*MAX;    
	int i,j,k;
      
    //declaring array of threads of size MAX*MAX        
    pthread_t *threads;
    threads = (pthread_t*)malloc(max*sizeof(pthread_t));
      
    int count = 0;
    int* data = NULL;
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++) {
        	A[i][j] =3.5 * i - 6.6 * j ;
			B[i][j] =6.6+8.8 *i - 3.5 *j ;  
 
            data = (int *)malloc((max)*sizeof(int));
            data[0] = MAX;
      
            for (k = 0; k < MAX; k++) {
                data[k+1] = A[i][k];
                data[k+MAX+1] = B[k][j];
			}
         
                //creating threads
                pthread_create(&threads[count++], NULL, mult, (void*)(data));
    	}
    	
	cout << "\n"
		 << "Multiplication of A and B:" << "\n";
		 
    for (i = 0; i < max; i++) {
      void *k;
	  //join threads
      pthread_join(threads[i], &k);
      int *p = (int *)k;
      printf("%d ",*p);
      if ((i + 1) % MAX == 0)
          printf("\n");
    }
    end = clock();
    
	//Displaying the execution time
	double diff = end - start; // ms
    cout <<"\n"<<"execution time:"<<"\n"<<diff<<" ms";
	return 0;
}
