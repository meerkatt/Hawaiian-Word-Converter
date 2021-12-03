#include "functions.hpp"

using namespace std;
size_t hword_idx;

//This functions makes it easier to print strings
void print_string(string val){
  cout << val << endl;
}

//This function checks to see if the input vector
//(word) contains only valid Hawaiian characters
int valid_word(string hword){
  size_t inval_char = hword.find_first_not_of("AEIOUPKHLMNWaeioupkhlmnw,' ");
  if (inval_char != string::npos){
    print_string(hword + " contains a character not a part of the Hawaiian language.");
    return 0;
  }
  return 1;
}
int valid_char(char hchar){
  if (hchar){
    return 1;
  }
  return 0;
}

string conv_vowel_a(string hword){
  string vow_phonetic;
  if(hword[hword_idx+1] == 'i' || hword[hword_idx+1] == 'I' || hword[hword_idx+1] == 'e' || hword[hword_idx+1] == 'E'){
        vow_phonetic.append("eye");
        ++hword_idx;
  }
  else if(hword[hword_idx+1] == 'o' || hword[hword_idx+1] == 'O' || hword[hword_idx+1] == 'u' || hword[hword_idx+1] == 'U'){
        vow_phonetic.append("ow");
        ++hword_idx;
  }
  else{
    vow_phonetic.append("ah");
  }
  return vow_phonetic;
}


string conv_vowel_e(string hword){
  string vow_phonetic;
  if(hword[hword_idx+1] == 'i' || hword[hword_idx+1] == 'I'){
        vow_phonetic.append("ay");
        ++hword_idx;
  }
  else if(hword[hword_idx+1] == 'u' || hword[hword_idx+1] == 'U'){
        vow_phonetic.append("eh-oo");
        ++hword_idx;
  }
  else{
    vow_phonetic.append("eh");
  }
  return vow_phonetic;
}


string conv_vowel_i(string hword){
  string vow_phonetic;
  if(hword[hword_idx+1] == 'u' || hword[hword_idx+1] == 'U'){
        vow_phonetic.append("ew");
        ++hword_idx;
  }
  else{
    vow_phonetic.append("ee");
  }
  return vow_phonetic;
}

string conv_vowel_o(string hword){
  string vow_phonetic;
  if(hword[hword_idx+1] == 'i' || hword[hword_idx+1] == 'I'){
        vow_phonetic.append("oy");
        ++hword_idx;
  }
  else if(hword[hword_idx+1] == 'u' || hword[hword_idx+1] == 'U'){
        vow_phonetic.append("ow");
        ++hword_idx;
  }
  else{
    vow_phonetic.append("oh");
  }
  return vow_phonetic;
}

string conv_vowel_u(string hword){
  string vow_phonetic;
  if(hword[hword_idx+1] == 'i' || hword[hword_idx+1] == 'I'){
        vow_phonetic.append("ooey");
        ++hword_idx;
  }
  else{
    vow_phonetic.append("oo");
  }
  return vow_phonetic;
}

string conv_vowel_w(string hword){
  string vow_phonetic;
  if(hword[hword_idx-1] == 'i' || hword[hword_idx-1] == 'I' || hword[hword_idx-1] == 'e' || hword[hword_idx-1] == 'E'){
        vow_phonetic.append("v");
  }
  else{
    vow_phonetic.append("w");
  }
  return vow_phonetic;
}
char conv_cons(char consonant){
  if(consonant < 97 && consonant > 64){consonant = consonant + 32;}
  return consonant;
}

//This function converts a Hawaiian word
//to its phonetic spelling 
string conv_to_phonetic(int argc, string hword){
  string pword;
  for(hword_idx = 0; hword_idx < hword.size(); ++hword_idx){
    if(hword[hword_idx] == 'a' || hword[hword_idx] == 'A'){
     pword.append(conv_vowel_a(hword)); 
    } else if(hword[hword_idx] == 'e' || hword[hword_idx] == 'E'){
     pword.append(conv_vowel_e(hword)); 
    } else if(hword[hword_idx] == 'i' || hword[hword_idx] == 'I'){
     pword.append(conv_vowel_i(hword));
    } else if(hword[hword_idx] == 'o' || hword[hword_idx] == 'O'){
     pword.append(conv_vowel_o(hword)); 
    } else if(hword[hword_idx] == 'u' || hword[hword_idx] == 'U'){
     pword.append(conv_vowel_u(hword)); 
    } else if(hword[hword_idx] == 'w' || hword[hword_idx] == 'W'){
     pword.append(conv_vowel_w(hword));
     continue; 
    }else{
      char consonant = conv_cons(hword[hword_idx]);
      pword.push_back(consonant);
      continue;  
    }

    if(hword[hword_idx+1] != ' ' && hword[hword_idx+1] != 39 &&  argc > 0 && valid_char(hword[hword_idx+1])){pword.push_back('-');}
    if(hword[hword_idx+1] == ' ' && argc > 0 ){
        pword.push_back(' ');
        argc=argc-1;
        ++hword_idx;
    }
  }
  return pword;
}