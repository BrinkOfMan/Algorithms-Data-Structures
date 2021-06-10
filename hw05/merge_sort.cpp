#include <iostream>
#include "build_random_array.cpp"
using namespace std;

void print_array(double *A, int N){
  for(int i = 0; i < N; i++){
  cout << A[i] << " ";
  }
  cout << endl;
}

void merge(double *result, double *b, double *c, int n){
  int i = 0;
  int j = 0;

  for (int k = 0; k < n; k++){
    if ((i < (n/2)) && (j >= n - (n/2) || b[i] <= c[j])) { result[k] = b[i++]; }
    else { result[k] = c[j++]; }
  }
}

void merge_sort(double *a, int n){
  if (n >= 2){

    double *left = new double[(n/2)];
    for (int i = 0; i < (n/2); i++){ left[i] = a[i]; }

    double *right = new double[n - (n/2)];
    for (int i = 0; i < (n - (n/2)); i++) { right[i] = a[i + (n/2)]; }

    merge_sort(left, (n/2));
    merge_sort(right, (n - n/2));
    merge(a, left, right, n);

    delete[] left;
    delete[] right;
    
  }
}

int main(){

  cout << "Choose array size: ";
  int N;
  cin >> N;
  double *A = build_random_array(N);

  merge_sort(A, N);

  cout << "Result from calling merge_sort(A, N); : "; 
  print_array(A, N);

  return 0;
}