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
  int i, le, eg, pivot;

  if (n == 0) return;

  // 真ん中の要素をピボットとする
  pivot = A[n/2];

  for (i = le = eg = 0; i < n; i++) {
    if (A[i] == pivot) swap(A + i, A + (eg++));
    else if (A[i] < pivot) {
      swap(A + i, A + le);
      if (le != eg) swap(A + i, A + eg);
      le++;
      eg++;
    }
  }

  // A[0] .. A[le - 1] < pivot = A[le] .. A[eg - 1] < A[eg] .. A[n - 1]

  quick_sort(A, le);
  quick_sort(A + eg, n - eg);
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  quick_sort(A, N);
  for(i=0;i<N;i++){
    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
  }
}
