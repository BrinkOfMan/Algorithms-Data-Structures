#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void recur(int degree, int height, int depth){

    cout << string(2*depth, ' ') << "depth = " << depth << " node"<< endl;

    if (height > depth){ 
        for(int i = 0; i < degree; i++){
            recur(degree, height, depth + 1);
        }  
    }
}

int main(){
    recur(5,3,0);
}