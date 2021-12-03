#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_string(string val);
int valid_word(string hword);
int valid_char(char hchar);
string conv_to_phonetic(int argc, string hword);
string conv_vowel_a(string hword);
string conv_vowel_e(string hword);
string conv_vowel_i(string hword);
string conv_vowel_o(string hword);
string conv_vowel_u(string hword);
string conv_vowel_w(string hword);
char conv_cons(char consonant);