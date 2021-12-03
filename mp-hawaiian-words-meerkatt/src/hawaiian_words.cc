#include "functions.hpp"
using namespace std;



int main(int argc, char **argv) {
  int input_num = argc;
  string word = argv[1];
  if(valid_word(word)){
    string phonetic = conv_to_phonetic(input_num, word);
    print(phonetic);
  }
  else {
    return 0;
  }

}