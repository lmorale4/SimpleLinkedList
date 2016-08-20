// SimpleListL.cpp

#include <cassert>
#include "SimpleListL.h"


SimpleList::SimpleList(){
  head;
  last = head;
  size = 0;
}

SimpleList::~SimpleList(){
  cout << "SimpleList object is being destroyed."<< endl;
  Node * temp;
  for(int i=0; i<size; i++){
		temp = head;
    head = head->next;
    delete temp; 
  }
}

SimpleList::SimpleList(const SimpleList & listToCopy){
  head = new Node;
  head->data = listToCopy.head->data;
  Node * copySL = listToCopy.head;
  for(int i=0; i<listToCopy.size; i++){
    last->next = new Node;
    last = last->next;
    copySL = copySL->next;
    last->data = copySL->data;
  } 
  size = listToCopy.size;
}

SimpleList & SimpleList::operator=(const SimpleList & listToCopy){
  if(&listToCopy != this){
    Node * temp;
    for(int i=0; i<size; i++){
			temp = head;
      head = head->next;
      delete temp;
      
    }
		
    head = new Node;
    head->data = listToCopy.head->data;
    Node * copyTemp = listToCopy.head;
    for(int i=0; i<listToCopy.size; i++){
      last->next = new Node;
      last = last->next;
      copyTemp = copyTemp->next;
      last->data = copyTemp->data;
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
  size++;
}


void SimpleList::insert (const ItemType & item, int position){
  assert(position >0 && position <= size+1);
  if(empty() || position == size+1){
      append(item);
  }
  else{
    Node * newNode = new Node;
    newNode->data = item;
    Node * temp1 = head;
    if(position == 1){
      head = newNode;
      head->next = temp1;      
    }
    else{
      Node * temp2;
      for(int i = 1; i < position; i++){
       temp2 = temp1;
       temp1 = temp1->next;
      }
      temp2->next = newNode;
      newNode->next = temp1;
    }
		size++;
  }

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
			if(position == size + 1){
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
  cur = cur->next;
}

ItemType SimpleList::getItem() const{
  return cur->data;
}

bool SimpleList::pastTheEnd() const{
  return cur == last->next;
}
