// RIya Baphna
//rb4nk
//2/24/19
// TreeCalc.h


#ifndef TREECALC_H
#define TREECALC_H

// include your stack implementation here

#include "TreeNode.h"
#include <stack>
using namespace std;

class TreeCalc {
public:

    TreeCalc();						//Constructor
    ~TreeCalc();					//Destructor

    void cleanTree(TreeNode * ptr);	//Deletes tree/frees memory
    void readInput();				//gets data from user
    void insert(const string & val);	//puts value in tree

    // print methods
    void printPrefix(TreeNode * curNode) const;	//prints data in prefix form
    void printInfix(TreeNode * curNode) const;	//prints data in infix form
    void printPostfix(TreeNode * curNode) const;//prints data in postfix form
    void printOutput() const;				//prints in pre,in,post form
    int calculate();					//calls private calculate method

private:
    // declare a stack to hold your expression tree
    int calculate(TreeNode* ptr) const;		//Evaluates tree, returns value
    stack <TreeNode*> newstack; 

};

#endif