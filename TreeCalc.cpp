// RIya Baphna
//rb4nk
//2/24/19
// TreeCalc.cpp

#include "TreeCalc.h"
#include <iostream>
#include <stack>

using namespace std;

//Constructor
TreeCalc::TreeCalc() {
    stack <TreeNode*> newstack ;

}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
    cleanTree(newstack.top());
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
   
    cleanTree(ptr->left);
    cleanTree (ptr -> right);
     delete ptr;

}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
    TreeNode *newnode = new TreeNode(val);
    if(val== "+" || val == "-" || val=="*" ||val=="/" ){
        TreeNode *right = newstack.top();
        newstack.pop();
        TreeNode *left = newstack.top();
        newstack.pop();
        newnode -> left = left;
        newnode -> right = right;
        newstack.push(newnode);

    }
    else{
        newstack.push(newnode);
        
    }

    

}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
    if (ptr==NULL){
        return;
    }
    cout<< ptr-> value << endl;
    if (ptr -> left != NULL){
        printPrefix(ptr->left);

    }
    if(ptr ->right !=NULL){
        printPrefix(ptr->right);
    }

}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
   string values = ptr->value;
   if (ptr==NULL){
    return;
   }
    if (ptr -> left != NULL){
        cout<<"("<<endl;
        printInfix(ptr->left);
    }
    
    if(isdigit(values[0])|| (values[0] == '-')){
    cout<< ptr->value <<endl;
   }

    if (ptr ->right != NULL){
        printInfix(ptr->right);
        cout<<")"<<endl;
    }
}


//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
    if (ptr == NULL){
        return;
    }
    if (ptr -> left != NULL){
        printPostfix(ptr->left);

    }
    if(ptr ->right !=NULL){
        printPostfix(ptr->right);
    }
    cout<< ptr-> value <<endl;


}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (newstack.size()!=0 && newstack.top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
        printPostfix(newstack.top());
        cout << endl;
        cout << "Expression tree in infix expression: ";
        printInfix(newstack.top());
        cout << endl;
        cout << "Expression tree in prefix expression: ";
        printPrefix(newstack.top());
        cout << endl;
    } else
        cout<< "Size is 0." << endl;
}


int TreeCalc::calculate(TreeNode* ptr) const {
    // Traverse the tree and calculates the result
  string value = ptr->value;
  if(value[0] == '+') {
    return (calculate(ptr->left) + calculate(ptr->right));
  }
  else if(value[0] == '-'&& !isdigit(value[1])) {
    return (calculate(ptr->left) - calculate(ptr->right));
  }
  else if(value[0] == '*') {
    return (calculate(ptr->left) * calculate(ptr->right));
  }
  else if(value[0] == '/') {
    return (calculate(ptr->left) / calculate(ptr->right));
  }
  else {
    return atoi(value.c_str());
}
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int i = 0;
    i = calculate(newstack.top());
    return i;
}