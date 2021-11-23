//CPSC 2620 Assignment 4
//Made by: Andrew Primeau
//
//Professor: Shahadat Hossain

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include "Wordset.h"

using namespace std;

// prototypes
void inputKwdFromKbd(WordSet &words);
void inputKwdFromFile(WordSet&, const char document[]);
double sim(WordSet a, WordSet b);

int main()
{
  WordSet ws1, ws2, ws3;
  string doc1, doc2;

  cout << "Enter a text file name: ";
  cin >> doc1;

  cout << "Enter a second text file name: ";
  cin >> doc2;

  // convert filename strings to const char* with c_str() function
  const char *document1 = doc1.c_str();
  const char *document2 = doc2.c_str();

  inputKwdFromFile(ws1, document1);
  inputKwdFromFile(ws2, document2);
  inputKwdFromKbd(ws3);

  // computing the similarity score between the user query and the first file
  cout << "The similarity between ";
  ws3.print();
  cout << " and ";
  ws1.print();
  cout << " = " << sim(ws3, ws1) << endl << endl;

  // computing the similarity score between the user query and the second file
  cout << "The similarity between ";
  ws3.print();
  cout << " and ";
  ws2.print();
  cout << " = " << sim(ws3, ws2) << endl << endl;

  return 0;
}

// The function takes in a query of at least 10 keywords from the user, reads this set of
// words into a WordSet object passed via the parameter words. It then takes the length of the
// query entered by the user and loops through each character of the query to check if the
// character is alphanumeric. If it is not alphanumeric it erases the character and continues
// through the WordSet object, otherwise it changes the character to a lowercase character
// and continues until the end of the query. It does this for each word and then adds the
// word to the WordSet object and adds to the count. Once there are no more words in the
// query and all the words are added to the WordSet object, it takes the union with itself to
// eliminate duplicates.
void inputKwdFromKbd(WordSet &words)
{
  int count = 0;
  int length;
  string word;

  cout << "Enter a query with at least 10 keywords (enter a \".\" to stop):\n";
  // gather all words separated by whitespace
  while (cin >> word)
  {
    if (word == ".")
    {
      if (count < 10)
      {
        cout << "You must enter at least 10 words! (" << count << "/10)\n";
        continue;
      }
      else
        break;
    }
    length = word.length();
    // loop through each char to prune non alphanumeric chars and convert to lowercase
    for (int i=0; i<length; ++i)
    {
      if (!isalnum(word[i]))
      {
        word.erase(i, 1);
        continue;
      }
      word[i] = tolower(word[i]);
    }
    words.add(word);
    count++;
  }
  // take union with self to remove duplicates
  words = words + words;
}

// The function opens the text file passed  via parameter document, reads the words, discards
// punctuation marks, into the wordset object passed via parameter words. The object will take
// in the elements of the document, loop through to check if they meet the intended parameters
// of being alphanumeric and erase the characters that are not alphanumeric. It will then make
// all of the characters lowercase using the function tolower and then adds this to the WordSet
// object. It will then take the union of the WordSet object with itself to eleminate
// duplicates from the WordSet object. Finally it closes the file once it has reached the end.
void inputKwdFromFile(WordSet &words, const char document[])
{
  ifstream ins(document);
  string word;
  int length;

  // gather all words separated by whitespace
  while (ins >> word)
  {
    length = word.length();
    // loop through each char to prune non alphanumeric chars and convert to lowercase
    for (int i=0; i<length; ++i)
    {
      if (!isalnum(word[i]))
      {
        word.erase(i, 1);
        continue;
      }
      word[i] = tolower(word[i]);
    }
    words.add(word);
  }

  // take union with self to remove duplicates
  words = words + words;

  // close the file
  ins.close();
}

// The function checks if the length of the second object is 0, if it is, it returns 0.
// Otherwise, it returns the absolute value of the length of the intersection divided by
// the intersection of the square root of the first WordSet object's length and the
// square root of the second WordSet object's length. The similarity score formula.
double sim(WordSet a, WordSet b)
{
  if(b.len() == 0)
    return 0;

  // Similarity score formula
  return abs((a * b).len()) / (sqrt(a.len()) * sqrt(b.len()));
}
