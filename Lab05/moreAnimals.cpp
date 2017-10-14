#include <iostream>
#include <vector>
#include <string>
#include "Dog.h"
#include "display.h"
using namespace std;

int main(int argc, const char * argv[]){
  int n = 0;
  cin >> n;
  vector<Animal*> animals;
  char type;
  string name;
  int age;
  for(int i = 0; i < n; i++){
    cin >> type;
    cin >> name;
    cin >> age;
    if(type == 'D'){
      animals.push_back(new Dog(name, age));
    }else{
      Animal* animal = new Animal;
      animal->setName(name);
      animal->setAge(age);
      animals.push_back(animal);
    }
  }
  display(animals);

}

