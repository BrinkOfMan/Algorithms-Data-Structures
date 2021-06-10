#include<iostream>
using namespace std;
#include "elapsed_time.h"
#include"build_random_array.cpp"

void insertion_sort(double *a, int n) {
  for (int i = 1; i < n; ++i) {
    int j = i;
    while( j > 0 && a[j] < a[j-1]) {
      swap(a[j], a[j-1]);
      --j;
    }
  }
}

int main() {
  cout << "Choose array size: ";
  int N;
  cin >> N;
  double *A = build_random_array(N);

  start_timer();
  insertion_sort(A, N);
  double cycles = elapsed_time();

  if (N <= 100) {  // print out result for smaller sizes
    for (int i = 0; i < N; ++i) cout << A[i] << ' ';
    cout << endl;
  }
  

  cout << " Total cycles: " << cycles << endl;

  delete [] A;
}
