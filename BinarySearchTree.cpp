//RIya Baphna
//BinarySearchTree.cpp
//2/26/19
//rb4nk


#include "BinarySearchTree.h"
#include <string>
#include <iostream>
#include "BinaryNode.h"
using namespace std;

BinarySearchTree::BinarySearchTree() { root = NULL; }

BinarySearchTree::~BinarySearchTree() {
  delete root;
  root = NULL;
}

// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
	root = insert(root,x);
	printTree();
  
}

// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) { root = remove(root, x); printTree();}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x) const {
  return pathTo(root,x);
}

// find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x) const {
 return (find(root,x));
}

// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes() const {
  return numNodes(root);
}

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
  if (n == NULL) {
    return NULL;
  }
  // first look for x
  if (x == n->value) {
    // found
    // no children
    if (n->left == NULL && n->right == NULL) {
      delete n;
      n = NULL;
      return NULL;
    }
    // single child
    if (n->left == NULL) {
      BinaryNode* temp = n->right;
      n->right = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    if (n->right == NULL) {
      BinaryNode* temp = n->left;
      n->left = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    // two children
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  return n;
}

BinaryNode* BinarySearchTree::insert(BinaryNode*& n, const string& x) {
  if(n==NULL){
  	n = new BinaryNode;
  	n->value =x;
  }
  else if (x < n->value){
  	 insert(n->left,x);
  }else if(x > n->value){
  	insert(n->right,x);
  }
  return n;
}

bool BinarySearchTree::find(BinaryNode* n, const string& x) const{
	if (n == NULL)  // we've "run" off the bottom
        return false;
    else if (x < n->value)
        return find(n->left,x);  // search left
    else if (x > n->value)
        return find(n->right,x); //search right
    else
        return true;   

}

string BinarySearchTree::pathTo(BinaryNode* n, const string& x) const{
	string str = n-> value+ " ";
	if(n==NULL)
		return " ";
	else if (x < n->value)
        return str+" " + pathTo(n->left,x);  
    else if (x > n->value)
        return str+" " +pathTo(n->right,x); 
    else
        return str;  
}

int BinarySearchTree::numNodes(BinaryNode* n) const{
    int count = 0;
    if (n == NULL) 
      return 0; 
   
    if  (n->left && n->right)  
       count++; 
   
    count += (numNodes(n->left) +  
            numNodes(n->right)); 
    return count;

	}

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
  if (p == nullptr) return;
  showTrunks(p->prev);
  cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isLeft) {
  if (root == NULL) return;

  string prev_str = "    ";
  Trunk* trunk = new Trunk(prev, prev_str);

  printTree(root->left, trunk, true);

  if (!prev)
    trunk->str = "---";
  else if (isLeft) {
    trunk->str = ".---";
    prev_str = "   |";
  } else {
    trunk->str = "`---";
    prev->str = prev_str;
  }

  showTrunks(trunk);
  cout << root->value << endl;

  if (prev) prev->str = prev_str;
  trunk->str = "   |";

  printTree(root->right, trunk, false);
}

void BinarySearchTree::printTree() { printTree(root, NULL, false); }