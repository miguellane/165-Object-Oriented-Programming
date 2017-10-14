#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;
struct AddressBook {
  struct Entry {
  	std::string name;
    std::string lastname;
    std::string email;
    
    Entry(std::string nam, std::string lnam, std::string ema){
      name = nam;
      lastname = lnam;
      email = ema;
    }
    void setName(std::string nam){
      name = nam;
    }
    void setLastname(std::string lnam){
      lastname = lnam;
    }
    void setEmail(std::string ema){
      email = ema;
    }
    std::string getName(){
      return email;
    }
    std::string getLastname(){
      return lastname;
    }
    std::string getEmail(){
      return email;
    }
    void print(){
      std::cout << "First Name: " << name << std::endl;
      std::cout << "Last Name: " << lastname << std::endl;
      std::cout << "Email: " << email << std::endl;
    }
  };
  int size;
  vector<Entry> book;

  AddressBook(std::string nam, std::string lnam, std::string ema){
    book.push_back(Entry(nam, lnam, ema));
  }
  void add(AddressBook* addition){
    for(int i = 0; i < addition->book.size(); i++){
      book.push_back(addition->book[i]);
    }
  }
  void print(){
    for(int i = 0; i < book.size(); i++){
      book[i].print();
      std::cout << std::endl;
    }
  }
};
#endif
