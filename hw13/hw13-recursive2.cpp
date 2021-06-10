#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void recur(double degree, double nodes, double depth){

    double height = log(nodes)/log(degree);

    cout << string(2*depth, ' ') << "depth = " << depth << " node"<< endl;

    if (height > depth){ 
        for(int i = 0; i < degree; i++){
            recur(degree, nodes, depth + 1);
        }  
    }
}

int main(){
    int degree = 5, nodes = 25, depth = 0;
    cout << "Maximum tree size with height corresponding to log_" << degree << "(" << nodes << ")" << " starting at depth " << depth << ":\n";
    recur(degree, nodes, depth);
}