// RIya Baphna
//rb4nk
//2/24/19
// TreeCalcTest.cpp

#include <iostream>
#include "TreeCalc.h"

using namespace std;

int main() {
    TreeCalc tester;
    // read expression input from the user
    tester.readInput();
    // print out the output in postorder, in order, preorder forms
    tester.printOutput();
    // calculate the result of the expression tree
    cout << "The result of the expression tree is "
         << tester.calculate() << endl;
    return 0;
}