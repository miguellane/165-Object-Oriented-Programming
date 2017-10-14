#ifndef ENTRY_H
#define ENTRY_H
#include <string>
#include <iostream>

using namespace std;

struct Entry {
	std::string name;
  std::string lastname;
  std::string email;
//  Entry(){
//    name = NULL;
//    lastname = NULL;
//    email = NULL;
//  }

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
#endif
