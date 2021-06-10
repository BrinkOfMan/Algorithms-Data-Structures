/*
Here's the algorithm:
for j = 1, 2, ..., n:
  L(j) = 1 + max{L(i) : (i, j) \in E}
return max_jL(j)

I can't really figure out a way to solve the subproblem of finding L(j) without looping through the entire array for a starting point
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void longest_sub(int *arr){
  int size = 11;
  int start[11]; // Used for checking to see if a node has been used as a starting point
  vector<string> list; // Used to hold the path of each node as a starting point
  for(int i = 0; i < size; i++){
    list.push_back(to_string(arr[i]));
  }

  start[0] = 1;

  for (int i = 1; i < size; i++) // Try each node as a starting point
  {
    start[i] = 1; // Mark it as tried
    for (int j = 0; j < i; j++ )  // Compare each subsequent value in the array
      if (arr[i] > arr[j] && start[i] < start[j] + 1){ // If subsequent value is larger AND farther in the array than the previously checked node
        start[i] = start[j] + 1; // Increment longest list size of that starting node by the value of the comparison node's lis value
        list[i] += ' ' + to_string(arr[j]); // Add string representation to list
      }
  }

  int max = 0, max_index = 0;
  for (int i = 0; i < size; i++) {
    if (max < start[i]){
      max = start[i];
      max_index = i;
    }
  }

  cout << "The length of the longest increasing subsequence in arr[] is " << max << " with a sequence of: " << list[max_index] <<endl;

}
   
int main()
{
  int arr[] = {4, 7, 2, 13, 8, 9, 12, 11, 18, 17, 20};
  longest_sub(arr);
  return 0;
}