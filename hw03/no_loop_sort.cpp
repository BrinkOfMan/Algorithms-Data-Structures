#include<iostream>
using namespace std;
#include "elapsed_time.h"
#include"build_random_array.cpp"

void no_loop_sort(double *a, int i0, int i1){
  if (i1 - i0 > 1){ // If there is more than 1 index left to check
    int i_mid = (i0 + i1)/2; // Create a "Halfway point"
    no_loop_sort(a, i0, i_mid); // Sort with the "Lower half"
    no_loop_sort(a, i_mid, i1); // Sort with the "Upper half"
    if (a[i_mid - 1] > a[i1 - 1]){ // If the value of the lower index is greater than the higher index value
      swap(a[i_mid - 1], a[i1 - 1]); // Swap 'em!
    }
    no_loop_sort(a, i0, i1 - 1); // Do it again, but with 1 fewer (the current max) to work with
  }
}

int main() {
  cout << "Choose array size: ";
  int N;
  cin >> N;
  double *A = build_random_array(N);

  start_timer();
  no_loop_sort(A, 0, N);
  double cycles = elapsed_time();

  if (N <= 100) {  // print out result for smaller sizes
    for (int i = 0; i < N; ++i) cout << A[i] << ' ';
    cout << endl;
  }
  

  cout << " Total cycles: " << cycles << endl;

  delete [] A;
}