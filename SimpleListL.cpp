// SimpleListL.cpp

#include <cassert>
#include "SimpleListL.h"


SimpleList::SimpleList(){
  head = new Node;
  last = head;
  size = 0;
}

SimpleList::~SimpleList(){
  cout << "SimpleList object is being destroyed."<< endl;
  Node * temp = head;
  for(int i=0; i<size; i++){
    head = head->next;
    delete temp;
    temp = head; 
  }
  delete last;

}

SimpleList::SimpleList(const SimpleList & listToCopy){
  head = new Node;
  head->data = listToCopy.head->data;
  Node * thisSL = head;
  Node * copySL = listToCopy.head;
  for(int i=0; i<listToCopy.size; i++){
    Node * temp = new Node;
    thisSL->next = temp;
    thisSL = thisSL->next;
    copySL = copySL->next;
    thisSL->data = copySL->data;
    
  } 
  last = thisSL;
  size = listToCopy.size;
}

SimpleList & SimpleList::operator=(const SimpleList & listToCopy){
  if(&listToCopy != this){
    Node * temp = head;
    for(int i=0; i<size; i++){
      head = head->next;
      delete temp;
      temp = head;
    }
    delete last;
    head = new Node;
    head->data = listToCopy.head->data;
    Node * thisSL = head;
    Node * copySL = listToCopy.head;
    for(int i=0; i<listToCopy.size; i++){
      Node * temp = new Node;
      thisSL->next = temp;
      thisSL = thisSL->next;
      copySL = copySL->next;
      thisSL->data = copySL->data;
    }
    last = thisSL;
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
  last->data = item;
  last->next = new Node;
  last = last->next;
  size++;
}


void SimpleList::insert (const ItemType & item, int position){
  assert(position >0 && position <= size+1);
  if(size == 0 || position == size+1){
      append(item);
      size--;
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
  }
  size++;
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
  Node * temp1 = head;
  if(size >1){
    if(position ==1){
      head = temp1->next; 
    }
    else{
      Node * temp2;
      for(int i = 1; i < position; i++){
        temp2 = temp1;
        temp1 = temp1->next;
      }
      temp2->next = temp1->next;
    }
  }
  delete temp1;
  size--;
}

void SimpleList::display (ostream & out) const{
  Node * var;
  for(int i = 0; i < size; i++){
    if(i==0){
      out << head->data << endl;
      var = head->next;
    }
    else{
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
  return cur == last;
}
