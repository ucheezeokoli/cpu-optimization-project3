#include<stdlib.h>
//START UNCOMMENTING HERE
void dgemm( int m, int n, float *A, float *C ) //unrolling
{
// FILL-IN 
  for( int i = 0; i < m; i++ )
    for( int k = 0; k < n; k++)    
      for( int j = 0; j < m; j++) {
        C[i+j*m] += A[i+k*m] * A[j+k*m];               
        while(j+3 < m){
          j++;
          C[i+j*m] += A[i+k*m] * A[j+k*m];
          j++; 
          C[i+j*m] += A[i+k*m] * A[j+k*m];
          j++; 
          C[i+j*m] += A[i+k*m] * A[j+k*m]; 
        }
                                  
      }
}
//END UNCOMMENTING PADDING HERE


//THIS IS PADDING
//START UNCOMMENTING HERE
void dgemm( int m, int n, float *A, float *C )
{
  if ((m * n) % 2 == 1){ //IF MATRIX IS ODD
    int s = m * n;
    n = n + 1;  
    float *A2 = (float*)realloc(A,m*n*sizeof(float));
    float *C2 = (float*)realloc(C,m*m*sizeof(float));
    for(int t = s; t < m * n; t++){
        A2[t] = 0;
    }
    for( int i = 0; i < m; i++ )
        for( int k = 0; k < n; k++ ) 
          for( int j = 0; j < m; j++ ) 
      C2[i+j*m] += A2[i+k*m] * A2[j+k*m];
  
  
  
  }
  else{
    for( int i = 0; i < m; i++ )
      for( int k = 0; k < n; k++ ) 
        for( int j = 0; j < m; j++ ) 
    C[i+j*m] += A[i+k*m] * A[j+k*m];
  
  
     
  }
}
//END UNCOMMENTING PADDING HERE


// START UNCOMMENTING HERE
//THIS IS REORDERING (PEEPHOLE OPTIMIZATION)
void dgemm( int m, int n, float *A, float *C ){ 
    for( int i = 0; i < m; i++){
      for( int k = 0; k < n; k++){
        float a = A[i+k*m]; //this is invariant in the inner loop so it doesnt need to be calculated j times
        for( int j = 0; j < m; j++) {         
          C[i+j*m] += a * A[j+k*m];
        }
      }  
    }

}
//END UNCOMMENTING PADDING HERE




