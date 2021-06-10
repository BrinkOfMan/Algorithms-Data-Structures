#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){

  map<string, int> price;
  price["socks"] = 1000; // Adds the key value pair for socks to the top of the map
  price["shoes"] = 3000; // Adds the key value pair for shoes to the top of the map
  cout << price["socks"] << endl; // Prints the value for the key "socks"
  cout << price.size() << endl; // Prints the size of the map (# of key-value pairs)

  for (auto p : price) // Iterates through the key-value pairs of the map
    cout << p.first << ' ' << p.second << endl; // Prints the name (key), followed by the price (value)

  if (price.find("boots") == price.end()) // Checks for "boots" key. If not found by the end of the array.
    cout << "not found" << endl; // Print that it wasn't found

  price.erase("socks"); // Byebye key-value pair for "socks" key
  for (auto p : price) // Iterate through the only value in the map
    cout << p.first << ' ' << p.second << endl; // Print key and value
  price.clear(); // Byebye entire map values


}