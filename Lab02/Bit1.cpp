#include <iostream>
#include <bitset>
#include <string>
using namespace std;

void printFlip(bitset<32> bits, int size){
  for(int i = 0; i < size; i++)
    cout << bits[i];
}
void printNeg(bitset<32> bits, int size){
  bitset<32> neg = bits^(bitset<32>(0xFFFFFFFF));
  for(int i = size-1; i >= 0; i--)
    cout << neg[i];
}

int main(){
  string input;
  getline(cin,input);
  int size;
  while(input != "-1"){
    size = input.size();    
    bitset<32> bits(input);

    cout << (int)(bits.to_ulong());
    cout << " ";
    printFlip(bits, size);
    cout << " ";
    printNeg(bits, size);
    cout << endl;

    getline(cin,input);
  }
}
