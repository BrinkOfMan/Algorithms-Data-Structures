#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
 
int LCS(string X, string Y, int m, int n){
 
    int lcs_table[m + 1][n + 1]; // Hold values of LCS for each suffix of X and Y
    int result = 0; // To store length of the current LCS

    for (int i = 0; i <= m; i++){ // Iterate through all possible suffixes of X
        for (int j = 0; j <= n; j++){ // Iterate through all possible suffixes of Y
            if (i == 0 || j == 0){
                lcs_table[i][j] = 0; // Fill out colum/row of 0s for first character suffix matches (works with this 2D table)
            }
            else if (X[i - 1] == Y[j - 1]){ // Previous characters match! Possiblity of increasing LCS!
                lcs_table[i][j] = lcs_table[i - 1][j - 1] + 1; //
                result = max(result, lcs_table[i][j]);
            }
            else // Previous characters don't match. Go check next pair.
                lcs_table[i][j] = 0;
        }
    }
    return result;
    // Again, not going to spend extra time on keeping track of the letters associated with each LCS
    // I could probably do that with a vector of a map of LCS value and current character assocation, but ¯\_(ツ)_/¯

}
 

int main()
{
    string X = "ALGORITHMS AND DATA STRUCTURES"; // Gross, ADS! (jk)
    string Y = "PLATYPUS AND DINOSAUR FOSSILS"; // Aww yeah, archeology and old stuff B)
    // LCS *should* be "S AND D" with a length of 7 (including spaces)
    
    cout << "Length of Longest Common Substring is " << LCS(X, Y, X.length(), Y.length()) << endl;
    
    return 0;
}