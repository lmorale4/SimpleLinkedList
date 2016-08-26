// SimpleListL.cpp

#include <cassert>
#include "SimpleListL.h"


SimpleList::SimpleList(){
  head;
  last;
	cur;
  size = 0;
}

SimpleList::~SimpleList(){
  cout << "\nSimpleList object is being destroyed."<< endl;
  Node * temp;
  for(int i=0; i<size; i++){
		temp = head;
    head = head->next;
    delete temp;
		// cout << "temp next: " << temp->next <<endl;
  }
}

SimpleList::SimpleList(const SimpleList & listToCopy){
  head = new Node;
	last = head;
  Node * copySL = listToCopy.head;
	last->data = copySL->data;
  for(int i=0; i<listToCopy.size - 1; i++){
    last->next = new Node;
    last = last->next;
    copySL = copySL->next;
		last->data = copySL->data;
  } 
  size = listToCopy.size;
}

SimpleList & SimpleList::operator=(const SimpleList & listToCopy){
  if(&listToCopy != this){
		if(!empty()){
			Node * temp;
			for(int i=0; i<size; i++){
				temp = head;
				head = head->next;
				delete temp;
				
			}
		}
		
    head = new Node;
		last = head;
		Node * copySL = listToCopy.head;
		last->data = copySL->data;
		for(int i=0; i<listToCopy.size - 1; i++){
			last->next = new Node;
			last = last->next;
			copySL = copySL->next;
			last->data = copySL->data;
		} 
		size = listToCopy.size; 
  }
}

bool SimpleList::empty () const{
  return size == 0;
}

int SimpleList::listSize ()const{
  return size;
}

void SimpleList::append (const ItemType & item){
	if(empty()){
		head = new Node;
		last = head;
	}
	else{
		last->next = new Node;
		last = last->next;
	}
	last->data = item;
	last->next = 0;
	size++;
}


void SimpleList::insert (const ItemType & item, int position){
  assert(position > 0 && position <= size+1);
  if(empty() || position == size+1){
      append(item);
  }
  else{
		// cout << "\nhead before: " << head << endl;
		// cout << "last before: " << last << endl;
    Node * newNode = new Node;
    newNode->data = item;
		// cout << "\nnewNode before data: " << newNode << endl;
    Node * temp1 = head;
		// cout << "temp1 before data: " << temp1 << endl;
    if(position == 1){
      head = newNode;
      head->next = temp1;
			// cout << "head after data: " << head << endl;
			// cout << "head next data: " << head->next << endl;

    }
    else{
      Node * temp2;
      for(int i = 1; i < position; i++){
        temp2 = temp1;
        temp1 = temp1->next;
			  // cout << "\ntemp2 during data: " << temp2 << endl;
				// cout << "temp1 during data: " << temp1 << endl;
      }
      temp2->next = newNode;
      newNode->next = temp1;
			// cout << "\ntemp2->next after data: " << temp2->next << endl;
			// cout << "newNode->next after data: " << newNode->next << endl;
    }
		size++;
  }
	// cout << "\ninsert head: " << head->data << endl;
	// if(head->next){cout << "insert next: " << head->next->data << endl;}
	// cout << "insert last: " << last->data << endl;
	// cout << "last next: " << last->next << endl;
	// cout << "size: " << size << endl;
}

ItemType SimpleList::retrieve (int position)const{
  assert (position > 0 && position <= size);
  Node * retVal = head;
  for(int i=0; i<position-1; i++){
    retVal = retVal->next;
  }
  return retVal->data;
}

void SimpleList::remove (int position){
  assert (position > 0 && position <= size);
  if(!empty()){
		Node * temp1 = head;
    if(position == 1){
      head = head->next; 
    }
    else{
      Node * temp2;
      for(int i = 1; i < position; i++){
        temp2 = temp1;
        temp1 = temp1->next;
      }
      temp2->next = temp1->next;
			if(position == size){
				last = temp2;
			}
    }
		delete temp1;
  }
  size--;
}

void SimpleList::display (ostream & out) const{
	if(!empty()){
		Node * var = head;
		for(int i = 0; i < size; i++){
			out << var->data << endl;
			var = var->next;
		}
	}
}

void SimpleList::moveToStart(){
  cur = head;
}

void SimpleList::next(){
	// cout << "cur->next: " << cur->next << endl;
  cur = cur->next;
}

ItemType SimpleList::getItem() const{
	// cout << "\nhead: " << head << endl;
	// cout << "next: " << head->next << endl;
	// cout << "next: " << head->next->next << endl;
	// cout << "last: " << last << endl;
	// cout << "last next: " << last->next << endl;
	// cout << "cur: " << cur << endl;
  return cur->data;
}

bool SimpleList::pastTheEnd() const{
	// last->next = 0;
	// cout << "last->next: " << last->next << endl;
  return cur == last->next;
}
