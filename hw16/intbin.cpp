#include <iostream>
#include "build_random_array.cpp"
using namespace std;

void print_array(int *A, int N){
  for(int i = 0; i < N; i++){
  cout << A[i] << " ";
  }
  cout << endl;
}

int bin_search(int *A, int first, int last, int num)
{
  int middle;
  if(last >= first){ //Check if we have more than 1 element

    middle = (first + last)/2;
    if(A[middle] == num){ // Is the next middle our num?
        return middle; // Return its index
    }

    else if(A[middle] < num){ // Will num in upper half?
      return bin_search(A, middle + 1, last, num); // Search it
    }

    else{ // Otherwise, search lower half
      return bin_search(A, first, middle-1, num);
    }

  }
  return -1; // Not present
}

void merge(int *result, int *b, int *c, int n){
  int i = 0;
  int j = 0;

  for (int k = 0; k < n; k++){
    if ((i < (n/2)) && (j >= n - (n/2) || b[i] <= c[j])) { result[k] = b[i++]; }
    else { result[k] = c[j++]; }
  }
}

void merge_sort(int *a, int n){
  if (n >= 2){

    int *left = new int[(n/2)];
    for (int i = 0; i < (n/2); i++){ left[i] = a[i]; }

    int *right = new int[n - (n/2)];

    right = new int[n - (n/2)];
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
  int *A = build_random_array(N);

  merge_sort(A, N);

  cout << "Result from calling merge_sort(A, N); : "; 
  print_array(A, N);

  cout << "Enter a number whose index you want to find: ";
  int num;
  cin >> num;

  int loc = bin_search(A, 0, N, num);

  if(loc != -1){ // num has been found!
    cout << num << " is at index: " << loc << endl;
  }
  else{
    cout << num << " is not present in the array." << endl;
  }
  

  return 0;
}