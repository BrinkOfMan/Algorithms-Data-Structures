// Not going to include a location path to this one. It's 2:40AM and wowowowow there's still so much to do!
// No time to waste on obsessing over figuring out path creation.
// Might go to sleep TBH, getting kind of delirious.
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int getAns (int* miles, int* profits, int n, int k, int index, int* max_expected){

  if (index >= n){ return 0; } // If we're beyond valid indices, just return 0 (shouldn't happen though)
  if (max_expected[index] > -1){ return max_expected[index]; } // If we already have a max_expected value, return it!
  
  int ans = 0;
  int sum = profits[index];
  int nextIndex = index+1;
  int curr_dist = miles[index];
  int distance = miles[nextIndex] - curr_dist;

  while ((distance < k) && (nextIndex < n)){ // Find next valid location
    nextIndex++;
    distance = miles[nextIndex] - curr_dist;
  }

  // Finding max profit when considering valid distance to next index
  sum += getAns(miles, profits, n, k, nextIndex, max_expected);
  
  // Finding max profit when NOT considering valid distance to next index (but the max value for that invalid next index should follow the rules!)
  // Maybe there's a chance that this breaks if we only consider non-valid distances. I don't know. It's 2:40. I want sleep.
  // The alternative is only having this algorithm check valid distances from the start node to the end node, ONLY employing a greedy method to choose the next possible valid location (incorrect for this kind of problem)
  ans += getAns(miles, profits, n, k, index + 1, max_expected); 

  max_expected[index] = max(ans, sum);
  return max_expected[index];

}

int main(){

  int m[7] = {10, 15, 20, 23, 27, 35, 42}; // Distances to each hotel
  int p[7] = {200, 300, 400, 800, 450, 600, 350}; // Expected profit at each location
  // Max profit SHOULD be 2300 (hotel 0, 1, 2, 4, 5, 6), barely beating the less optimal path 2250 (0, 1, 3, 5, 6)
  // Change "800" to "900" and the algorithm should adapt, stating the new maximum profit of 2350
  int max_expected[7] = {-1, -1, -1, -1, -1, -1, -1}; // For assigning the max expected profit at a hotel location
  int k = 5; // MINIMUM distance between restaurant locations

  cout<<"The maximum expected profit is: " << getAns(m, p, 7, k, 0, max_expected) << endl;

  return 0;

}