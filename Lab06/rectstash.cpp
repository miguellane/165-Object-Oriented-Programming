#include <vector>
#include <iostream>
#include <cassert>
class RectStash{
public:
	int size;
	int quantity;
	int next;
	unsigned char* storage;

	RectStash(int sz){
		size = sz;
		quantity = 0;
		storage = 0;
		next = 0;
	}  
	void cleanup(){
		if(storage != 0) {
		  std::cout << "freeing storage" << std::endl;
		  delete []storage;
		}
	}
	int add(const void* element){
		if(next >= quantity)
		  inflate(100);
		int startBytes = next * size;
		unsigned char* e = (unsigned char*)element;
		for(int i = 0; i < size; i++)
		  storage[startBytes + i] = e[i];
		next++;
		return(next - 1);
	}
	void* fetch(int index){
		assert(0 <= index);
		if(index >= next)
			return 0;
		return &(storage[index * size]);
	}
	int count() {
		return next;
	}
	void inflate(int increase){
		assert(increase > 0);
		int newQuantity = quantity + increase;
		int newBytes = newQuantity * size;
		int oldBytes = quantity * size;
		unsigned char* b = new unsigned char[newBytes];
		for(int i = 0; i < oldBytes; i++)
			b[i] = storage[i];
		delete []storage;
		storage = b;
		quantity = newQuantity;
	}
};
class Rect{
public:
  float x;
  float y;
  float width;
  float height;

  Rect(){
    this->x = 0;
    this->y = 0;
    this->width = 0;
    this->height = 0;
  }
  Rect(float x, float y, float width, float height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
  }
  ~Rect(){
  }
  void contains(float x, float y){
    if(this->x < x && x < this->x + this->width){
      if(this->y - this->height < y && y < this->y){
        std::cout << "in";
        return;
    } }
    std::cout << "out";
  }
};

int main(int argc, const char * argv[]){
//  std::vector<Rect> rectStash;
  RectStash rectStash(sizeof(Rect));
  float x, y, width, height;
  std::cin >> x;
  std::cin >> y;
  std::cin >> width;
  std::cin >> height;
  while(x >= 0 || y >= 0 || width >= 0 || height >= 0){
//    rectStash.push_back(Rect(x, y, width, height));
    rectStash.add(new Rect(x, y, width, height));
    std::cin >> x;
    std::cin >> y;
    std::cin >> width;
    std::cin >> height;
  }
  std::cin >> x;
  std::cin >> y;
  while(x != -99 && y != -99){
//    for(int i = 0; i < rectStash.size(); i++){
    for(int i = 0; i < rectStash.count(); i++){ 
//      rectStash[i].contains(x, y);
      ((Rect*)rectStash.fetch(i))->contains(x, y);
      std::cout << " ";
    }
    std::cout << std::endl;
    std::cin >> x;
    std::cin >> y;
  }
}
