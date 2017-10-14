#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

struct LinkedList {
	struct Link {
		void* data;
		Link* next;
		
		void initialize(void* dat, Link* nxt){
			data = dat;
			next = nxt;
		}
	}* head;
	void initialize(){
		head = 0;
	}
  LinkedList(void* dat, Link* nxt){
    Link* newLink = new Link;
    newLink->initialize(dat, nxt);
    head = newLink;
  }
  


  void add(Link* l, int n){
    Link* look = l;
    for(int i = 0; i < n; i++){    
		  Link* newLink = new Link;
		  newLink->initialize(new double(i), NULL);
		  look->next = newLink;
      look = look->next;
    }
  }
  void push(void* dat){
		Link* newLink = new Link;
		newLink->initialize(dat, head);
		head = newLink;
	}
	void* peek(){
		if (head == 0){
			std::cout << "Stack is empty";
		}
		return head->data;
	}
	void* pop(){
		if(head == 0)
			return 0;
		void* result = head->data;
		Link* oldHead = head;
		head = head->next;
		delete oldHead;
		return result;
	}
  void print(){
    Link* look = head;
    while(look != 0){
      std::cout << *(static_cast<double*>(look->data)) << std::endl;
      look = look->next;
    }
  }
	void cleanup(){
    while(pop() != 0);
	}
};
#endif
