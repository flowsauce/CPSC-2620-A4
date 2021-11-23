//CPSC 2620 Assignment 3
//Made by: Andrew Primeau
//
//Professor: Shahadat Hossain

#include <iostream>
#include <algorithm>
#include "Wordset.h"

// Default constructor
// creates an object of type WordSet in an "empty state"
WordSet::WordSet()
{
   //cout << "Default" << endl;
}

// Copy constructor
// the copy constructor will take the vector string this->set, clear it, and copy whatever
// data from the the address of ws (ws.set) to the vector string this->set using a for loop
WordSet::WordSet(const WordSet &ws)
{
   // here remove the previous data from whatever was in our vector string
   this->set.clear();
   // now we copy the data from ws.set to this->set using a for loop
   int ws_size = ws.set.size();
   for(int i=0; i<ws_size; i++)
      set.push_back(ws.set[i]);
}

// to be used when we need to delete WordSet explicitly
// since we are not working with the dynamically allocated arrays
// and instead with a vector string, our destructor is automatically
// created and deletes the WordSets.
WordSet::~WordSet()
{
   //cout << "Destroy" << endl;
}

// overload operator= so we can assign a WordSet to a WordSet
WordSet& WordSet::operator=(const WordSet& ws)
{
   // here we remove the previous data from whatever was in our vector string
   this->set.clear();
   // now we copy the data from ws.set to this->set using a for loop
   int ws_size = ws.set.size();
   for(int i=0; i<ws_size; i++)
      set.push_back(ws.set[i]);

   return (*this);
}

// Create WordSet with the elements of vector<string> v
WordSet::WordSet(vector<string> v)
{
   // use std::vector::operator= to assign contents of v to WordSet's set member
    this->set = v;
}

// Add a string element to the WordSet
void WordSet::add(string s)
{
    // use std::vector::push_back to add the element to WordSet's set member
    this->set.push_back(s);
}

// Removes the specified string s
void WordSet::remove(string s)
{
    // Iterator based range loop, this will go through and remove the specified string 
    for (vector<string>::iterator it=this->set.begin(); it!=this->set.end(); ++it)
    {
        if (*it == s)
            this->set.erase(it);
    }
}

// Clear contents of WordSet
void WordSet::clear()
{
    // use std::vector::clear to remove elements of set and sets size to 0
    this->set.clear();
}

// Utility to return the length of the WordSet
int WordSet::len()
{
    // use std::vector::size to return the amount of elements in set
    return this->set.size();
}

// Utility to return the length of the WordSet
int WordSet::len() const
{
    // use std::vector::size to return the amount of elements in set
    return this->set.size();
}

// Utility for printing contents of WordSet
void WordSet::print()
{
    int size = this->len();
    
    cout << "[";
    for (int i=0; i<size; ++i)
    {
        cout << "\"" << this->set[i];
        if (i+1 != size)
            cout << "\", ";
        else
            cout << "\"";
    }
    cout << "]\n";
}

// Union
// this will initialize a wordset to contain the results of the union of two vectors. We then loop through the
// contents of the RHS of the union and if the result does not already contain the string, it adds it to the
// vector string. We then loop through again to delete the duplicate words in the union, giving us a true union
// of the two wordsets, to then return this union.
WordSet WordSet::operator+(const WordSet& ws) const
{
    // Initialize the result with the contents of either LHS or RHS (in this case LHS) with the copy constructor
    WordSet res(*this);

    int size = ws.len();
    // Loop through the contents on RHS
    // If res does not contain the string, then add the string to res.
    for (int i=0; i<size; ++i)
        if (!res.contains(ws.set[i]))
            res.add(ws.set[i]);

    // Remove duplicates
    // initializes a wordset that will contain the resulting wordset that has no duplicate entries
    // this will loop through the vector string and if it does not contain the item, adds it to the vector
    WordSet noDupes;
    size = res.len();
    for (int i=0; i<size; ++i)
        if (!noDupes.contains(res.set[i]))
            noDupes.add(res.set[i]);

    return noDupes;
}

// Intersection
// this will initialize a wordset to contain both the RHS and LHS of the intersection and then
// initializes a wordset to be the result. It will do the intersection, then goes through for
// the length of the both wordset and looping to add the items to the result if the value is
// in both the LHS and RHS of the intersection. It will then return the result wordset
WordSet WordSet::operator*(const WordSet& ws) const
{
    // Initialize a WordSet 'both' to store the union of LHS and RHS. Initialize 'res' as result
    WordSet both, res;
    both = (*this) + ws;

    int size = both.len();
    // Loop through the intersectiom of LHS and RHS and only add to result if the
    // value is in the LHS AND the RHS using our helper function
    for (int i=0; i<size; ++i)
        if (this->contains(both.set[i]) && ws.contains(both.set[i]))
            if (!res.contains(both.set[i]))
                res.add(both.set[i]);

    return res;
}

// Helper function that returns true if WordSet contains value 's', false otherwise
// It will loop through every element in our vector string and check if it is equal to
// the value 's' or not
bool WordSet::contains(string s) const
{
    // the following line is a solution with <algorithm>
    //return std::find(this->set.begin(), this->set.end(), s) != this->set.end();

    // for the length/size of the vector string, it will loop through to check if the item in
    // the vector string is equal to a string value, then returns true if their equal and
    // false if they're not
    int size = this->len();
    for (int i=0; i<size; ++i)
        if (this->set[i] == s)
            // found, return true
            return true;

    // not found, return false
    return false;
}
