// 12/2/17
// Eric Graves
// Test file for syllable.cpp

// Bool debug to enable debug messages

#include "syllable.h"
#include <iostream>
#include <fstream>
#include <random>
#include <string>

using namespace std;
extern bool DEBUG;
extern bool DEBUG_VERBOSE;

int main(int argc, char* argv[]){

  /*
  // Test 1: Test on static array of srting
  string a[7] = {"array", "syllable", "test", "run", "burdensome", "verbose" };

  for(int i=0; i < 7; i++){
    cout << a[i] << " : " << numSyllables_2(a[i]) << endl;
  }
  // */
  cout << "=============start==============" << endl;
  const int min = 0;
  const int max = 45384;
  ifstream inf(argv[1]);
  string word;
  string haiku = "";

  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(min, max);

  int line_syl[5] = {5, 7, 5};

  for(int l = 0; l < 3; l++){

    int syllables = 0;
    while(syllables < line_syl[l]){
      int random_int = dis(gen);
      // Iterate to the line
      for(int i = 0; i < random_int; i++){
        getline(inf, word);
      }

      // Get the desired word
      getline(inf, word);
      int ns = numSyllables_2(word);

      // Check if the word fits in the line
      if(syllables + ns <= line_syl[l]){
        if(DEBUG_VERBOSE)
          cout << "+++++++ WORD USED +++++++" << endl;
        haiku += word;
        if(DEBUG){
          haiku += '(';
          haiku += to_string(ns);
          haiku += ')';
        }
        haiku += ' ';
        syllables += ns;
      }
      // Reset the file pointer to the first word
      inf.clear();
      inf.seekg (0, ios::beg);
    }
    // Add a newline between lines
    if(DEBUG){
      haiku += " : "; // Debug Message
      haiku += to_string(syllables); // Debug Message
    }
    haiku += '\n';
  }
  cout << haiku << endl;
  cout << "============================= end." << endl;
  // */
  return 0;
}
