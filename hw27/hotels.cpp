#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

void printPath(int *path, int i) {

  if (i == 0) { return; }

  printPath(path, path[i]);
  cout << i << " ";

  return;
}

int main() {

  int limit = 200;
  int hotels[] = {0, 190, 230, 370, 420, 500, 600, 640, 800}; // Hotel distances
  int penalties[] = {0, ((limit - hotels[1]) * (limit - hotels[1])), -1, -1, -1, -1, -1, -1, -1}; // Penalties for visiting that hotel
  int path[] = {0, 0, -1, -1, -1, -1, -1, -1, -1}; // Will work in conjunction with printPath.

  for (int i = 2; i < (int(sizeof(hotels)) / int(sizeof(int))); i++) { // Go through all hotels

    for(int j = 0; j < i; j++){ // Go through all hotels UP TO the current hotel being checked out

      int tempPen = (penalties[j] + ((limit - (hotels[i] - hotels[j])) * (limit - (hotels[i] - hotels[j])))); // Calculate the penalty of (limit - distance)^2

      if(penalties[i] == -1 || tempPen < penalties[i]){ // No assigned penalty OR less than the current minimum penalty
        penalties[i] = tempPen; // Assign a penalty value
        path[i] = j; // Add if we should visit/not to the path
      }
    }
  }

  cout << "After stating at hotel 0 (at distance 0), we begin our search for the optimal path towards hotel 8.\nWe will print the current minimum penalty path as we search through the array.\n";
  for (int i = 1; i < (int(sizeof(hotels)) / int(sizeof(int))); i++) {
    cout << "At hotel " << i << " our distance is " << hotels[i] << " and our minmum penalty would be " << penalties[i] << " with a path of: ";
    printPath(path, i);
    cout << endl;
  }
}