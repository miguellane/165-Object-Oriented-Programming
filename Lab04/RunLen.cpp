#include <iostream>
#include <cassert>
struct Stash {
	int size;      // Size of each space
	int quantity;  // Number of storage spaces
	int next;      // Next empty space
  int calls;
  int increment;
	unsigned char* storage;
  
	void initialize(int sz, int inc){
		size = sz;
		quantity = 0;
		storage = 0;
		next = 0;
    calls = 0;
    increment = inc;
	}
	void cleanup(){
		if(storage != 0) {
		  std::cout << "freeing storage" << std::endl;
		  delete []storage;
		}
	}
	int add(const void* element){
		if(next >= quantity) // Enough space left?
		  inflate(increment);
		int startBytes = next * size;
		unsigned char* e = (unsigned char*)element;
		for(int i = 0; i < size; i++)
		  storage[startBytes + i] = e[i];
		next++;
		return(next - 1); // Index number
	}
	void* fetch(int index){
		assert(0 <= index);
		if(index >= next)
			return 0;
		return &(storage[index * size]);
	}
	int count() {
		return next; // Number of elements in CStash
	}
	void inflate(int increase){
		assert(increase > 0);
		int newQuantity = quantity + increase;
		int newBytes = newQuantity * size;
		int oldBytes = quantity * size;
		unsigned char* b = new unsigned char[newBytes];
		for(int i = 0; i < oldBytes; i++)
			b[i] = storage[i]; // Copy old to new
		delete []storage; // Old storage
		storage = b; // Point to new memory
		quantity = newQuantity;
    calls++;
	}
};

int main(){
  char ch;
  char* val;
  int in;
  std::cin >> in;
  Stash* myStash = new Stash;
  myStash->initialize(sizeof(char), in);
//  myStash->initialize(sizeof(char));

  std::cin >> ch;
  val = new char(ch);
  std::cin >> in;
  while(ch != '&' && in != 99){
    if(in >= 0){
      for(int i = 0; i < in; i++){
        myStash->add(val);
      }
    }else{
      for(int i = 0; i < -in; i++){
        myStash->add(val);
      }
      myStash->add(new char('\n'));
    }
    std::cin >> ch;
    val = new char(ch);
    std::cin >> in;
  }

  int i = 0;
  val = static_cast<char*>(myStash->fetch(i));
  while(val != 0){
    std::cout << *val;
    i++;
    val = static_cast<char*>(myStash->fetch(i));
  }

  std::cout << myStash->calls << std::endl;
  std::cout << myStash->quantity << std::endl;
}
