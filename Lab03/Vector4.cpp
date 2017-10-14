#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  string input;
  string output;
  int find;
  vector<string> words;

  getline(cin,input);

  while(input != "quit"){

    if(input.size() < 4){
      words.push_back(input);  
    }else{
      output = input;
      for(int i = 0; i < words.size(); i++){
        find = output.find(words[i]);
        if (find != string::npos)
          output.erase(find, words[i].size());
      }
      cout << output << endl; 
    }
    getline(cin, input);
  }
}
