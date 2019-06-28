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
A[0], A[1], ..., A[n-1] の中でk+1番目に小さい値を返す関数
ただし、Aの中身は書き換えてしまう。
*/
int quick_select(int A[], int n, int k){
  int i, le, eg, pivot;

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

  if (le <= k && k < eg) return pivot;
  else if (eg <= k) return quick_select(A + eg, n - eg, k - eg);
  else return quick_select(A, le, k);
}


int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
//    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}
