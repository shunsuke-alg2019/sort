#include <stdio.h>

// 素数
#define N 2999

int A[N];

// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}


/*
A[0], A[1], ..., A[n-1] をソートして昇順に書き換える関数
*/
void quick_sort(int A[], int n){
  if (n == 0) return;

  int pivot = A[0];

  int j = 1;
  for (int i = 1; i < n; i++) {
    if (A[i] <= pivot) swap(A + i, A + (j++));
  }

  swap(A, A + j - 1); // A[0] .. A[j - 2] <= pivot < A[j] .. A[n - 1]
  quick_sort(A, j - 1);
  quick_sort(A + j, n - j);
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

  quick_sort(A, N);
  for(i=0;i<N;i++){
    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
  }
}
