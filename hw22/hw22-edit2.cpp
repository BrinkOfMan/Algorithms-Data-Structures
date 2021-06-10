#include<iostream>
#include<string>
#include<vector>

using namespace std;

int edit_cost(string str1, string str2, int index1, int index2){

  if (index1 == int(str1.size()) - 1){
    return str2.size() - index2;
  }

  else if(index2 == int(str2.size()) - 1){
    return str1.size() - index1;
  }

  else{
    vector<int> costs;

    // E(i, j-1) + 1
    int insertion_cost = 1 + edit_cost(str1, str2, index1, index2 + 1);
    costs.push_back(insertion_cost);

    // E(i-1, j) + 1
    int deletion_cost = 1 + edit_cost(str1, str2, index1 + 1, index2);
    costs.push_back(deletion_cost);

    // E(i-1,j-1)/2 (+1 to avoid 0 cost)
    int replace_cost;
    if (str1[index1] == str2[index2]){
      replace_cost = edit_cost(str1, str2, index1 + 1, index2 + 1)/2 + 1;
    }

    // E(i-1,j-1) + 1 (the +1 is diff(i,j))/2
    else{
      replace_cost = (1 + edit_cost(str1, str2, index1 + 1, index2 + 1))/2 + 1;
    }
    costs.push_back(replace_cost);

    int min = costs[0];

    for(auto x: costs){
      if (x < min){
        min = x;
      }
    }
    return min;
  }

}

int main(){
    string first;
    cout << "Please input the first word to compare: ";
    cin >> first;
    string second;
    cout << "\nPlease input the second word to compare: ";
    cin >> second;
    cout << "\nThe minimum amount of edits needed to make these words similar is: " << edit_cost(first, second, 0, 0) << endl;
}