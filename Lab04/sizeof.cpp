#include <iostream>
using namespace std;

struct A{
  char aa;
  double ab;
}a;
struct B{
  char ba;
  char bb;
  double bc;
}b;
struct C{
  char ca;
  char cb;
  char cc;
  double cd;
}c;
struct D{
  char da;
  char db;
  char dc;
  char dd;
  double de;
}d;
struct E{
}e;
struct F{
  char fa;
  int fb;
  char fc;
}f;
struct G{
  char ga;
  char gb;
  int gc;
}g;

int main(int argc, const char * argv[]){
  std::cout << sizeof(a);
  std::cout << std::endl;
  std::cout << sizeof(b);
  std::cout << std::endl;
  std::cout << sizeof(c);
  std::cout << std::endl;
  std::cout << sizeof(d);
  std::cout << std::endl;
  std::cout << sizeof(e);
  std::cout << std::endl;
  std::cout << sizeof(f);
  std::cout << std::endl;
  std::cout << sizeof(g);
  std::cout << std::endl;
  return 0;
}

