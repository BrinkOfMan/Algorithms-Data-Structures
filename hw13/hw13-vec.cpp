#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> v = {2, 3, 5, 7, 11};

  cout << "Straight up printing the vector:\n";

  for (int i = 0; i < 5; ++i)
    cout << v[i] << endl;

  cout << "\nPrinting the vector using an iterator:\n";

  for (int x : v) 
    cout << x << endl;

  cout << "\nPrinting the vector size:\n";

  cout << v.size() << endl;

  cout << "\nv.push_back(22) and printing the new size:\n";

  // push_back method: Adds an element to the vector after the last index.
  v.push_back(22);
  cout << v.size() << endl;

  cout << "\nPrinting the new vector using an iterator:\n";

  for (auto x : v)
    cout << x << endl;

  cout << "\nv.erase(v.begin() + 1) and a subsequent print:\n";

  // erase method: Removes the element at index i.
  v.erase(v.begin() + 1);
  for (auto x : v)
    cout << x << endl;

  cout << "\nv.insert(v.begin() + 2, 9) and a subsequent print:\n";

  // insert method: Places an element at index i and shifts all subsequent indices farther back.
  v.insert(v.begin() + 2, 9);
  for (auto x : v)
    cout << x << endl;

  cout << "\nv.clear() and size print:\n";

  // clear method: Erases every element in the array.
  v.clear();
  cout << v.size() << endl;

  cout << "\nAdding nine elements in the middle of the vector, then printing out the entire vector.\n";

  v.insert((v.begin() + v.size() / 2), 9);
  v.insert((v.begin() + v.size() / 2), 8);
  v.insert((v.begin() + v.size() / 2), 7);
  v.insert((v.begin() + v.size() / 2), 6);
  v.insert((v.begin() + v.size() / 2), 5);
  v.insert((v.begin() + v.size() / 2), 4);
  v.insert((v.begin() + v.size() / 2), 3);
  v.insert((v.begin() + v.size() / 2), 2);
  v.insert((v.begin() + v.size() / 2), 1);

  for (auto x : v)
    cout << x << endl;


}