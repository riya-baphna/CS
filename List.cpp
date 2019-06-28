//Riya Baphna
//rb4nk
//List.cpp
//1/28/19

#include <iostream>
#include "List.h"
using namespace std;


List:: List(){
	 head = new ListNode;
	 tail = new ListNode;
	 head ->next = tail;
	 tail ->previous = head;
     count = 0;			
}

List::~List( ) {
	makeEmpty();
	delete head;
	delete tail;
   
}

 List::List(const List& source) {
 	
	head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

 bool List:: isEmpty()const{// check if count is 0

	if (count == 0){
		return true;
	}
	else{

		  return false;
		}
	}


List& List::operator=(const List& source) { 
	
	if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

 void List::makeEmpty(){// more than four nodes so fix this
 	

	head-> previous = NULL;
	head-> next = tail;
	tail -> previous = head;
	tail -> next = NULL;
}

ListItr List::first() {
	ListItr aListItr (head -> next);
	return aListItr;
 }

ListItr List::last(){
	ListItr bListItr (tail -> previous);
	return bListItr;
}

 void List::insertAfter(int x, ListItr position){// INCREMENT COUNT
 
	ListNode *newnode = new ListNode;
	newnode->value = x;

	newnode->previous = position.current;
	newnode->next = position.current -> next;
	position.current -> next-> previous = newnode;
	position.current -> next = newnode;
	count++;
	
	
 }

void List::insertBefore(int x, ListItr position){
	
	ListNode *newnode = new ListNode;
	newnode->value = x;

	newnode->next = position.current;
	newnode->previous = position.current->previous;
	position.current->previous->next = newnode;
	position.current->previous = newnode;
	count++;
}
 void List::insertAtTail(int x){
	ListNode *aNode = new ListNode;
	tail->value = x;
	tail->next = aNode;
	aNode->previous = tail;
	tail = aNode;
	count++;
	
}

void List::remove(int x){
    ListItr removepos = find(x);

    if (!(removepos.isPastEnd())){
	removepos.current->previous->next = removepos.current -> next;
    removepos.current->next->previous = removepos.current->previous;
    delete removepos.current;
	count--;
  }

}


 ListItr List:: find(int x){
 	ListNode *newnode = new ListNode;
    ListItr position(newnode);
    position = this ->first();
    while (!position.isPastEnd()){
    	if (position.current->value==x){
    	    return position;
    	}
    	else{
    		position.moveForward();
 
    	}

    		

  }
  ListItr position2(newnode);
  position2 = tail;
  return position2;

}


int List::size() const{
	return count;
 }


void printList(List& theList, bool forward){
	ListNode *newnode = new ListNode;
     ListItr aListItr(newnode);
	

	if (forward){
		aListItr = theList.first();
		while (!aListItr.isPastEnd()){
		cout<< aListItr.retrieve()<<endl;
		aListItr.moveForward();
	}
}
	else{
		aListItr = theList.last();
		while (!aListItr.isPastBeginning()){
		cout<< aListItr.retrieve()<<endl;
		 aListItr.moveBackward();
	}
	}
}




