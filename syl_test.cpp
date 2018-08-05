// Started 12/2/17
// Finalized + Published 08/05/18
// Eric Graves

// syl_test.cpp
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

  cout << "=============start==============" << endl;
  const int min = 0;
  const int max = 45384; // Taylor this to the number of entries in input txt file
  ifstream inf(argv[1]); // Call ./out american_english.txt when testing
  string word;
  string haiku = "";

  // Random number generator setup
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(min, max);

  int num_lines = 3;
  int line_syl[3] = {5, 7, 5}; // Change these values for different structures

  for(int l = 0; l < num_lines; l++){

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

    if(DEBUG){
      haiku += " : ";                 // Debug Message
      haiku += to_string(syllables);  // Debug Message
    }
    // Add a newline between lines
    haiku += '\n';
  }
  cout << haiku << "============================= end." << endl;

  return 0;
}
