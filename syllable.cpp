// Started 11/29/17
// Finalized + Published 08/05/18
// Eric Graves

// syllable.cpp
// Estimate how many syllables are in a word. Tested using syl_test.cpp

#include <string>
#include <iostream>

using namespace std;
bool DEBUG = 0;
bool DEBUG_VERBOSE = 0;

// Warning: no error checking
bool isVowel(char c){
  if(c =='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y'
   ||c =='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='Y'){
    return true;
  }
  return false;
}

/*------------------------------------------------- numSyllables -----
         |  Function numSyllables
         |
         |  Purpose: estimate the number of syllables in a word from the
         |           order of vowels and consonants which it contains.
         |
         |  Parameters:
         |      word (IN) -- string holding the word to be analyzed.
         |
         |  Returns: n, the number of syllables estimaed for the given
         |           string.
         *-------------------------------------------------------------------*/

int numSyllables(string word){

  // Ignore Proper Nouns in dictionary
  if(word[0] <= 90 && word[0] >= 65)
    return 99; // Itll work as long as youre not trying to write a paragraph

  // For readability
  if(DEBUG_VERBOSE)
    cout << endl << "============== " << word << " ==========" << endl;

  int l = word.length() -1; // word length -> .length() returns one more than actual length, thus -1
  int n = 0; // number of syllables

  // If starting with a vowel, add a syllable
  if (isVowel(word[0])){
    n +=1;
    if(DEBUG_VERBOSE)
      cout << "Word starts with vowel - ";
  }
  // For consecutive letters, each time a vowel is followed by a consonant, add a syllable
  for(int i = 1; i <= l-1; i++){ // l-1 prevents overflow
    if(isVowel(word[i]) && !isVowel(word[i+1]) ){
      n +=1;
      if(DEBUG_VERBOSE)
        cout << "Vowel followed by consonant - ";
    }
  }

  //  cout << "PRINTING THE LAST TWO LETTERS: " << word[l-1] << word[l] << endl;
  // Catch for words ending in vowel followed by -y
  if (word[l] == 'y' && isVowel(word[l-1])){
    n += 1;
    // this is a change
    if(DEBUG_VERBOSE)
      cout << "Vowel followed by -y at ending - ";
  }

  // Add a case for words ending two consonants
  if(!isVowel(word[l])){
    if(!isVowel(word[l-1])){
      n +=1;
      if(DEBUG_VERBOSE)
        cout << "Ending has two consonants - ";
    }
  }

  // Except if its -ng!
  if(word[l] == 'g' || word[l] == 'G'){
    if(word[l-1] == 'n' || word[l-1] == 'N'){
      n -= 1;
      if(DEBUG_VERBOSE)
        cout << "Ending in '-ng' (-1) - ";
    }
  }
  // OR -ck!
  if(word[l] == 'c' || word[l] == 'C'){
    if(word[l-1] == 'k' || word[l-1] == 'K'){
      n -= 1;
      if(DEBUG_VERBOSE)
        cout << "Ending in '-ck' (-1) - ";
    }
  }
  // OR ENDS IN -s!
  if(word[l] == 's' || word[l] == 'S'){
    n -= 1;
    if(DEBUG_VERBOSE)
      cout << "Ending in '-s' (-1) - ";
  }

  // Remove a syllable for words ending in -e
  if(word[l] == 'e' || word[l] == 'E'){
    if(word[l-1] == 'l' || word[l-1] == 'L'){
      n+=2; // Except if they are not silent like -le, then add a syllable. because thats not confusing
      if(DEBUG_VERBOSE)
        cout << "Second to last char is 'l' - ";
    }
    n-=1;
    if(DEBUG_VERBOSE)
      cout << "Word ends in e - ";
  }

  // No 0 syllable words allowed
  if (n <= 0){
    n = 1;
    if(DEBUG_VERBOSE)
      cout << "Zero syllables?";
  }

  // For readability
  if(DEBUG_VERBOSE)
    cout << endl << "=============================" << endl;

  // Here's the number of syllables
  return n;
}

/*------------------------------------------------- numSyllables_2 -----
         |  Function numSyllables_2
         |
         |  Purpose: estimate the number of syllables in a word from the
         |           vowels in that word.
         |
         |  Parameters:
         |      word (IN) -- string holding the word to be analyzed.
         |
         |  Returns: n, the number of syllables estimaed for the given
         |           string.
         *-------------------------------------------------------------------*/

int numSyllables_2(string word){

  // Ignore Proper Nouns in dictionary
  if(word[0] <= 90 && word[0] >= 65)
    return 99; // Itll work as long as youre not trying to write a paragraph

  // For readability
  if(DEBUG_VERBOSE)
    cout << endl << "============== " << word << " ==========" << endl;

  int l = word.length() -1; // word length -> .length() returns one more than actual length, thus -1
  int n = 0; // number of syllables

  for(int i = 0; i <= l; i++){
    // Catch all vowels up to the last character
    if((i != l) && isVowel(word[i]) && !isVowel(word[i+1]) ){
      n += 1;
    }
    // Catch the last character
    if( (i == l) && isVowel(word[i])){
      n += 1;
    }
  }

  if(DEBUG_VERBOSE)
    cout << n << " syllables" << endl;

  return n;
}
