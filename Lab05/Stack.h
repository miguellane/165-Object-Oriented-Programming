#ifndef STACK_H
#define STACK_H

#include <iostream>

struct Stack {
	struct Link {
		double data;
		Link* next;
		
		void initialize(double dat, Link* nxt){
			data = dat;
			next = nxt;
		}
	}* head;
  

  Stack(){
    head = 0;    
  }
  Stack(int n){
    double e = 1.0;
    for(int i = 0; i < n; i++){
      push(e);
      e += .1;
    }
  }
  ~Stack(){
    double run = pop();
    while(run != 0){
      std::cout << run << " ";
      run = pop();
    }
  }
	
	void initialize(){
		head = 0;
	}
	
	void push(double dat){
		Link* newLink = new Link;
		newLink->initialize(dat, head);
		head = newLink;
	}
	
	double peek(){
		if (head == 0){
			std::cout << "Stack is empty";
		}
		return head->data;
	}
	
	double pop(){
		if(head == 0)
			return 0;
		
		double result = head->data;
		Link* oldHead = head;
		head = head->next;
		delete oldHead;
		return result;
	}
	
	void cleanup(){
		if (head == 0){
			std::cout << "Stack is empty";
		}
		else {
			std::cout << "Stack is not empty";
		}
	}
};
#endif
