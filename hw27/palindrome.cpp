#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int longest_palindrome(string X, int i, int j)
{
    // Base condition
    if (i > j) {
        return 0;
    }
 
    // If the string X has only one character, it is a palindrome
    if (i == j) {
        return 1;
    }
 
    // If the last character of the string is the same as the first character,
    if (X[i] == X[j]){
        // include the first and last characters in palindrome
        // and recur for the remaining substring `X[i+1, j-1]`
        return longest_palindrome(X, i + 1, j - 1) + 2;
    }
 
    
    // If the last character of the string is different from the first character: 2 cases
    // 1. Remove the last character and recur for the remaining substring (X[i, j-1])  
    // 2. Remove the first character and recur for the remaining substring (X[i+1, j])
 
    // Return the maximum of the two cases
    return max(longest_palindrome(X, i, j - 1), longest_palindrome(X, i + 1, j));
}
 
int main()
{
    string X = "A BONOBO IS A MONKEY";
    // "A BONOB A" is the LPS with a length of 9 (including spaces)
    int n = X.length();
 
    cout << "The length of the longest palindromic subsequence is " << longest_palindrome(X, 0, n - 1);
 
    return 0;
}