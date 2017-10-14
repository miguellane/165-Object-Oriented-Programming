#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  string input;
  vector<string> words;

  getline(cin,input);

  while(input != "quit"){
    if(input.size() == 1){
      for(int i = 0; i < words.size(); i++){
        if(words[i][0] == input[0]){
          cout << words[i] << endl;
          break;
      } }
    }else{
      words.push_back(input);      
    }
    getline(cin, input);
  }
}
