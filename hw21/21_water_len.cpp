/*
Ethan Brinkman

Dijkstra Review

Please implement a version of panB to solve the original pouring water problem with three buckets, with the following additional constraint:

  what is the minimum amount of water that needs to be poured in order to reach the goal state? 

That is, let us consider the 'length' of a given pour to be the amount of water that is poured, and then the 'distance' from the start to the goal will be the minimum sum of lengths to get there.


- This code is so jank and I'm so tired that I don't want to try to transform it to be similar to panB

- HOWEVER, I was able to tally up the amount of water poured to reach a solution.

Here's the output from my console (minus the queue operations):

PS C:\Users\ethan\brinkm1\ADS\hw21> ./21_water_len.exe
Queue operation 0 - 13

(0,7,4)
(7,0,4)
(10,0,1)
(3,7,1)
(3,4,4)
(7,4,0)
(4,7,0)
(4,3,4)
(8,3,0)
(8,0,3)
(1,7,3)
(1,6,4)
(5,6,0)
(5,2,4)
This is a solution! Amount of water poured: 68

Queue operation 14
(0,7,4)
(7,0,4)
(10,0,1)
(3,7,1)
(3,4,4)
(7,4,0)
(4,7,0)
(4,3,4)
(8,3,0)
(8,0,3)
(1,7,3)
(1,6,4)
(5,6,0)
(5,2,4)
(9,2,0)
This is a solution! Amount of water poured: 73

Queue operation 15
(0,7,4)
(7,0,4)
(10,0,1)
(3,7,1)
(3,4,4)
(7,4,0)
(4,7,0)
(4,3,4)
(8,3,0)
(8,0,3)
(1,7,3)
(1,6,4)
(5,6,0)
(5,2,4)
(9,2,0)
(9,0,2)
This is a solution! Amount of water poured: 77

Queue operation 16
(0,7,4)
(7,0,4)
(10,0,1)
(3,7,1)
(3,4,4)
(7,4,0)
(4,7,0)
(4,3,4)
(8,3,0)
(8,0,3)
(1,7,3)
(1,6,4)
(5,6,0)
(9,2,0)
(9,0,2)
(2,7,2)
This is a solution! Amount of water poured: 84

Queue operation 17-20

PS C:\Users\ethan\brinkm1\ADS\hw21>

- Looks like 68 pints of water need to be poured based on this program's execution.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;


class Node{
  int **buckets;
  vector<string> path; // Path to reach specific Node
  int poured; // Holds the amount of water poured to reach a specific Node.

public:
  // Integer assignment constructor
  Node(int ten, int seven, int four, int p){
    // Create 3 new "buckets"
    buckets = new int*[3];
    // For each bucket, assign a new int array to hold current value and max capacity, as well as total water poured.
    for(int i=0; i<3; ++i){
      buckets[i] = new int[2];
    }

    poured = p; // Assign amount of water poured so far

    // Assign bucket "ten" its current value and max capacity
    buckets[0][0]=ten; // Current value
    buckets[0][1]=10; // Max capacity
    // Do the same with bucket "seven" and "four"
    buckets[1][0]=seven;
    buckets[1][1]=7;
    buckets[2][0]=four;
    buckets[2][1]=4;

    path.push_back(this->get_rep());
  }

  // Copy + add a Node contructor
  Node(int **old, Node p){
    buckets = new int*[3];
    for(int i=0; i<3; ++i){
      buckets[i] = new int[2];
    }
    for(int i=0; i<3; ++i){
      for(int j=0; j<2; ++j){
        // Copy values from old (old node) into this bucket, add previous node to path.
        buckets[i][j]=old[i][j];
      }
    }
    poured = old[3][0]; // Assign poured value from generated child to current Node
    path = p.path; // Assign path from previous Node to current node
    path.push_back(this->get_rep());
  }

  vector<int**> gen_state(){
    //Generate all valid neightbours
    vector<int**> neighbours; // Holds both valid child nodes and poured value
    bool next[] = {true, true, true, true, true, true};
    int pos[6][2] = {{0,1},{0,2},{1,2},{1,0},{2,0},{2,1}}; // All possible pairs of buckets (3!)
    int j = 0;
    
    while(j<3){
      // if bucket is full, all situations it is poured into are false
      if(buckets[j][0]==buckets[j][1]){ // If the current amount of water in the bucket is equal to its max capacity
        for(int w = 0; w < 6; w++){
          if(pos[w][1]==(j)) // If the current position's bucket has a matching max capacity
            next[w]=false; // Don't fill it up anymore
        }
      }
      // if bucket is empty, all situations it is poured from are false
      if(buckets[j][0]==0){
        for(int w = 0; w < 6; w++){
          if(pos[w][0]==(j)) // If the current position's bucket has a matching current value
            next[w]=false; // Stop pouring
        }
      }
      ++j;
    }

    int i = 0;
    while(i < 6){ // Go through each position (3! possible permutations)
      // Create a new temporary bucket state
      int **temp = new int*[4];
      for(int k=0; k<3; ++k){
        temp[k] = new int[2];
      }
      temp[3] = new int[1]; // Create an int[] just to hold the amount of water poured (kinda stupid but it works)
      temp[3][0] = poured;

      // Copy current bucket's values into temporary bucket
      for(int m = 0; m < 3; m++){
        for(int n = 0; n < 2; n++)
          temp[m][n]=buckets[m][n];
      }

      if(next[i]){
        int maxFill = buckets[pos[i][1]][1] - buckets[pos[i][1]][0]; // Set the maximum amount of liquid that can be filled before bucket is full
        int inAmount = buckets[pos[i][0]][0]; // How much is already in the bucket
        if(maxFill <= inAmount){ // If a valid pour is possible
          // Create a child node with: 
          temp[pos[i][0]][0]-=maxFill; // Subtract amount of liquid being poured from source bucket
          temp[pos[i][1]][0]+=maxFill; // Add that amount into receiving bucket
          temp[3][0] += maxFill; // Add to the amount of water poured so far
          neighbours.push_back(temp); // Add the valid Node to the neighbors vector
        }
        else{
          //new child with:
          temp[pos[i][0]][0]=0; // Empty source bucket
          temp[pos[i][1]][0]+=inAmount; // Add the amount that was in the now empty bucket into the receiving bucket
          temp[3][0] += maxFill; // Add to the amount of water poured so far
          neighbours.push_back(temp); // Add the valid Node to the neighbors vector
        }
      }
      i++;
    }
    // Return all valid subsequent states of buckets
    return neighbours;
  }

  int get_state(int i){
    // Return current state of bucket i's value
    return buckets[i][0];
  }

  string get_rep(){
    // Generate and return a string representation of a Node
    string s = "";
    s += '(' + std::to_string(buckets[0][0]) + ',';
    s += std::to_string(buckets[1][0]) + ',';
    s += std::to_string(buckets[2][0]) + ')';
    return s;
  }

  // Return amount of water poured so far
  int get_poured(){
    return poured;
  }

  void print_path(){
    // Print the path to the current node
    for(int i=0; i<int(path.size()); ++i){
      cout<<path[i]<<endl;
    }
  }
};

void BFS(Node root){
  queue<Node> FIFO;
  map<string, bool> control; // Map to see if a generated Node is unique or not
  vector<int**> children; // Will hold all possible children of a specific Node
  string rep = "";
  int steps = 0;

  FIFO.push(root); // Init queue with the root
  rep = root.get_rep(); // Get string representation of that Node, add it to map
  control[rep] = 1; // Map that string to be present


  while(!FIFO.empty()){ // While the queue isn't empty
    Node temp = FIFO.front(); // Create a temp Node from the first Node in the stack
    FIFO.pop(); // Pop top value off stack
    cout << "Queue operation " << steps << endl;

    if(temp.get_state(1) == 2 || temp.get_state(2) == 2){ // If either bucket "seven" or "four" contain 2 pints of water
      temp.print_path(); // Print the solution
      cout << "This is a solution! Amount of water poured: " << temp.get_poured() << endl << endl;
    }
    children = temp.gen_state(); // Generate valid children nodes
    for(unsigned int i=0; i< children.size() - 1; ++i){ // Loop through each one
      Node t(children[i], temp); // Create each child as a Node
      rep = t.get_rep(); // Get their string representation
      if(control.count(rep)){ // If this Node is a duplicate
        continue; // Do nothing
      }
      control[rep] = 1; // This string representation is now present in the map
      FIFO.push(t);
    }
    steps++; // Increment queue step counter
  }
  return;
}


int main(){

  // Create Node with buckets 10, 7, 4 holding 0, 7, and 4 pints, respectively.
  Node root(0,7,4,0);
  
  // Begin the BFS of possible states using root as the starting point
  BFS(root);
  

  return 0;
}