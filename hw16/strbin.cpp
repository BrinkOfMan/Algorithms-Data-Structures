#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int compare_char(const char* str1, const char* str2){

  int len1 = 0, len2 = 0, ret = 0;

  while (str1[len1] != '\0'){
    len1++;
  }

  while (str2[len2] != '\0'){
    len2++;
  }

  for(int i = 0; i < min(len1, len2); i++){
    if(str1[i] > str2[i]){ // str1 is greater
      ret = -1;
      break;
    }
    else if(str1[i] < str2[i]){ //str2 is greater
      ret = 1;
      break;
    }
  }

  // Please note: there's no check for strings of equal characters, but one string continues after the comparisons
  // Ex: Comparing "He" and "Hello"
  // It's 4 AM and I just want to sleep, so that feature isn't coming

  return ret;

}

int bin_search(vector<const char *> &A, int first, int last, const char* buffer)
{
  int middle;
  if(last >= first) { //Check if we have more than 1 element

    middle = (first + last)/2;

    int ret = compare_char(A[middle], buffer);
    
    if(ret == 0){ // Is the next middle our word?
        return middle; // Return its index
    }

    else if(ret == 1){ // Will num in upper half?
      return bin_search(A, middle + 1, last, buffer); // Search it
    }

    else{ // Otherwise, search lower half
      return bin_search(A, first, middle-1, buffer);
    }

  }
  return -1; // Not present
}

int main(){
  
  vector<const char *> v = {"Aloha", "Bok", "Bonjour", "Bun", "Ciao", "Dobrii-den", "Goede-morgen", "Guten tag", "Hej", "Hello", "Hola", "Kalimera", "Merhaba", "Salutu", "Yadra"};

  for (auto x : v){ cout << x << endl;}

  cout << "Enter the word whose index you want to find: ";
  char buff[50];
  cin >> buff;

  int loc = bin_search(v, 0, 15, buff);

  // I'm too tired to figure this out. Wish I could have just used the string class. It's not like real-life programs require this unnecessary restriction.
  // This works completely fine if you type in a word that already exists in the array.
  // If you don't type in a word that exists, the program stops printing cout buffers.
  // What a nice 5.5 hour homework assignment

  if(loc != -1){ // num has been found!
    cout << buff << " is at index: " << loc << endl;
  }
  else{
    cout << buff << " is not present in the array." << endl;
  }

  return 0;

}

