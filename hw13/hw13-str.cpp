#include <iostream>
#include <string>
using namespace std;

int main(){

  string s = "hi hi";
  cout << s[1] << endl;  
  cout << "size " << s.size() << endl;

  s = s + " ok";
  cout << s << endl; 

  string s2 = "ji ji";
  // This < operator will compare the strings character by character until it finds out if the character at s is NOT < the character at s2
  // If a character is found that breaks the rule, it will return 0; otherwise, 1
  cout << (s < s2) << endl;

}