#include <iostream>
#include <string>
using namespace std;
void printByteStringInt(string strByte){
  int intByte = 0;
  for(int j = 0; j < strByte.size(); j++){      
    if(strByte[j] == '1')
      intByte += 1;
    intByte <<= 1;
  }
  intByte >>= 1;
  cout << intByte;
}


int main(){
  string input;
  getline(cin,input);
  int i, end = input.find_first_not_of("01");
  string strByte;


  for(i = 0; i+8 < end; i += 8){
    strByte = input.substr(i,8);
    printByteStringInt(strByte);
    cout << " ";
  }
  strByte = input.substr(i,end-i);
  printByteStringInt(strByte);
  cout << endl;
}
