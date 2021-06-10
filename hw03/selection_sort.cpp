#include<iostream>
using namespace std;
#include "elapsed_time.h"
#include"build_random_array.cpp"

int find_smallest(double *a, int p, int n){
  int result = p; // Set the value of result to our current index
  while (p < n){ // For each position p through n of a
    if (a[p] <=  a[result]) {result = p;} //If the new position is smaller, replace result with the smaller value's index
    p++;
  }
  return result; // Return the current smallest value's index
}

void selection_sort(double *a, int n) {
  int s; // Holds the smallest value's index
  for (int p = 0; p < n; p++) { // For each position p through n of a
    s = find_smallest(a, p, n); // Find the smallest value's index in the array, starting at p
    swap(a[p], a[s]); // Swap the smallest value with the current value
  }
}

int main() {
  cout << "Choose array size: ";
  int N;
  cin >> N;
  double *A = build_random_array(N);

  start_timer();
  selection_sort(A, N);
  double cycles = elapsed_time();

  if (N <= 100) {  // print out result for smaller sizes
    for (int i = 0; i < N; ++i) cout << A[i] << ' ';
    cout << endl;
  }
  

  cout << " Total cycles: " << cycles << endl;

  delete [] A;
}