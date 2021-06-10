/*
Exercise 5: Implement the knapsack dynamic programming solution in C++ 
Test it with the examples you have created in Exercises 2 and 3.

initialize all K(0,j) = 0 and all K(w, 0) = 0
for j = 1 to n:
  for w = 1 to W:
    if w_j > w: K(w,j) = K(w, j-1)
    else: K(w, j) = max{K(w, j-1), K(w - w_j, j-1) + v_j}

*/

#include<iostream>

using namespace std;

int max(int x, int y) {
  // Can't believe I've just now learned the ternary operator '?'
  return (x > y ? x : y); // Is x > y ? If so, return x. Else, return y
}


void no_repetition(int W, int w[], int v[], int n) {

  int K[W + 1][n + 1]; // We need to add +1 to account for using "0" weight or "0" items

  // Initialize all K(j,0) = 0 and all K(0, w) = 0
  for (int j = 0; j <= n; j++) { K[0][j] = 0;} 
  for (int weight = 0; weight <= W; weight++) { K[weight][0] = 0;}

  for (int j = 1; j <= n; j++) {
    for (int weight = 1; weight <= W; weight++) {
      if (w[j - 1] > weight) { K[weight][j] = K[weight][j - 1];} // If w_j > w: K(w,j) = K(w, j-1)
      else { K[weight][j] = max(K[weight][j - 1], K[weight - w[j - 1]][j - 1] + v[j - 1]);} // Else: K(w, j) = max{K(w, j-1), K(w - w_j, j-1) + v_j}      
    }
  } 
  cout << "The maximum value you can hold with a weight of " << W << " is " << K[W][n] << ".\n";
  // Currently, this doesn't get along well with trying to keep track of "crucial" indices to reach the max value
  // It just finds the max value

}

int main(int argc, char const *argv[]){

  int n = 0, W = 0; // The (n)umber of items, maximum (W)eight capacity

  cout << "Enter the maximum weight capacity of knapsack: ";
  cin >> W;

  cout << "Enter the amount of items you can choose from: ";
  cin >> n;

  int v[n], w[n]; // Array to hold each item's (v)alue and its corresponding (w)eight

  // Loop through all indices of v and w's items
  for (int i = 0; i < n; i++) {

    cout << "Enter the weight for item " << i << ": ";
    cin >> w[i];

    cout << "Enter the value for item " << i << ": ";
    cin >> v[i];
  }
  no_repetition(W, w, v, n);


  return 0;
}


/*
Test run output:

######################## EXERCISE 1 #########################
PS C:\Users\ethan\brinkm1\ADS\hw23> .\hw23-knap.exe         #
Enter the maximum weight capacity of knapsack: 10           #
Enter the amount of items you can choose from: 4            #
Enter the weight for item 0: 1                              #
Enter the value for item 0: 2                               #
Enter the weight for item 1: 6                              #
Enter the value for item 1: 9                               #
Enter the weight for item 2: 4                              #
Enter the value for item 2: 5                               #
Enter the weight for item 3: 5                              #
Enter the value for item 3: 6                               #
The maximum value you can hold with a weight of 10 is 14.   #
#############################################################

######################## EXERCISE 2 #########################
PS C:\Users\ethan\brinkm1\ADS\hw23> .\hw23-knap.exe         #
Enter the maximum weight capacity of knapsack: 15           #
Enter the amount of items you can choose from: 5            #
Enter the weight for item 0: 5                              #
Enter the value for item 0: 8                               #
Enter the weight for item 1: 7                              #
Enter the value for item 1: 10                              #
Enter the weight for item 2: 2                              #
Enter the value for item 2: 3                               #
Enter the weight for item 3: 4                              #
Enter the value for item 3: 5                               #
Enter the weight for item 4: 6                              #
Enter the value for item 4: 9                               #
The maximum value you can hold with a weight of 15 is 22.   #
#############################################################

*/