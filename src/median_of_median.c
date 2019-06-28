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

void sort_k(int A[], int n, int k) {
  for (int i = 0; i < n && i < k; i++) {
    for (int j = i + 1; j < n; j++) {
      if (A[j] < A[i]) swap(A + i, A + j);
    }
  }
}

int quick_select(int A[], int n, int k){
  int i, le, eg, pivot, rem;

  if (n <= 5) {
    sort_k(A, n, k + 1);

    return A[k];
  }

  for (i = 0; i < n / 5; i++) {
    sort_k(A + 5 * i, 5, 3);
    swap(A + i, A + 5 * i + 2);
  }
  rem = n % 5;
  if (rem >= 1) {
    sort_k(A + 5 * i, rem, rem / 2 + 1);
    swap(A + i, A + 5 * i + rem / 2);
    i++;
  }
  pivot = quick_select(A, i, i / 2);

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
  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
//    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}
