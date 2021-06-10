#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

void find_max(int *arr, int n) {

   int max_sum = arr[0]; // Assign largest contiguous subsequence's sum to the array's first value
   int temp = max_sum; // To hold max summation at a current checking point
   map<int, string> lcs; // Keep track of all the fun stuff
   lcs[arr[0]] = to_string(arr[0]);

   for (int i = 1; i < n; i++ ) { // For all elements in the array

      // Find the max of either this array element OR the current max + the current array element
      if ((temp = max(arr[i], (temp + arr[i]))) == arr[i]){ // If we are at the start of a NEW LCS
         lcs.clear(); // Clear the map
         lcs[i] = to_string(arr[i]); // Start anew :')
      }
      else{
         if(arr[i] >= 0){ lcs[i] = ("+ " + to_string(arr[i])); } // place a '+' if new element is positive
         else { lcs[i] = ("- " + to_string(arr[i] * -1)); } // '-' otherwise
      }
      max_sum = max(max_sum, temp); // Update max sum
   }

   // Intensely jank code designed to remove the last checked element IF it's negative.
   // Wasted my entire night figuring out the map thing just to print out the LCS. Not worth.
   // The next programs probably won't include extra stuff like including the sequence itself.
   if(lcs[lcs.size()+1][0] == '0' || lcs[lcs.size()+1][0] == '-') { lcs.erase(lcs.size()+1); }

   // Output LCS and its sum
   cout << "The largest contiguous subsequence is: ";
   for (auto x : lcs){ cout << x.second << " "; }
   cout << "with a sum of " << max_sum << endl;

   return;
}

int main() {

   int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(arr) / sizeof(int); // Number of elements in the array

   find_max(arr, n);
}