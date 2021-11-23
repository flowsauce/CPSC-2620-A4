//CPSC 2620 Assignment 3
//Made by: Andrew Primeau
//
//Professor: Shahadat Hossain

#ifndef WORDSET_H
#define WORDSET_H
#include <vector>
#include <string>

using namespace std;

// This is a class named WordSet to represent a "set of words"
class WordSet
{
    public:
        // Default constructor
        // creates an object of type Wordset in an "empty state"
        // We want to be able to use this, access it and initialize it in our test file as
        // well, so it is a public member
        WordSet();

        // Copy constructor
	// this will take the vector string this->set, clear it, and copy whatever data from
	// the address of ws (ws.set) to the vector string this->set using a for loop
	// We want to be able to use this, access it and initialize it in our test file as
	// well, so it is a public member
        WordSet(const WordSet& ws);

        // Destructor
	// This is to be used when we need to delete WordSet explicitly. Since we are working with
	// vector strings and not with dynamically allocated arrays using the new/delete keywords,
	// the destructor will automatically be called, created and deleting the WordSets
	// The destructors are automatically going to be used and called to delete WordSets in our
	// test file, thus it needs to be a public member
        ~WordSet();

        // Overload assignment
	// This is used to assign a WordSet object to a WordSet object. We first remove the previous
	// data from what is in the first WordSetm then copy the data over to the other WordSet object
	// using a for loop
	// We are going to need use this function in our WordSet.cpp and our test_wordset.cpp file
	// in order to do the operations we'd like and produce the results being asked of the
	// union and intersection of two WordSet objects. Therefore it must be a public member. It
	// is also public because it is an operation
        WordSet& operator=(const WordSet& ws);

        // Overloaded Constructor
	// Creates a WordSet with the elements of vector<string> v and uses the operator= to assign
	// the contents of v to WordSet's set member
	// We want to be able to use this, access it and initialize it in our test file as
	// well, so it is a public member
        WordSet(vector<string> v);

        // Add
	// this will add a string element to the WordSet using push_back to add this elements to
	// WordSet's set member
	// We need to access this function directly with our WordSet object to add to the length of
	// that object, so because we can access it with our object, it is a public member
        void add(string s);

        // Remove
	// This will remove the specified string from the WordSet using an iterator based range loop
	// to go through and remove the specified string
	// We are going to be using this function in our test file to remove an object of type
	// string from our WordSet object, and we can use this directly accessing it from our
	// WordSet object, so it is a public member
        void remove(string s);

        // Clear
	// This will clear the contents of WordSet and sets the size to 0.
	// We need to access this function directly from an object to clear
	// that object, so because we can access it with our object, it is a public member
        void clear();

        // Num words in vector
	// This uses size() to return the amount of elements in WordSet
	// We want to be able to call this function in our test file and through the use of other
	// functions to show the number of words in our vector string, thus it is a public
	// member
	// We need to access this function directly with our WordSet object to know the length of
	// that object, so because we can access it with the object, it is a public member
        int len();

        // Display
	// This is a utility function, used for printing the contents of WordSet, using a for loop
	// the length of the size of WordSet
	// We want to be able to use this function to print the contents of WordSet in our test file,
	// and we are accessing it directly with our WordSet object, therefore it is a public member
        void print();

        // Arithmetic overload
	// This will initialize a WordSet to contain the results of the union of two vector string. We
	// loop through the contents of the RHS of the union and iff the result does not alread contain
	// the string, it adds it to the vector string. We also loop through and delete the duplicate
	// words in the union to then return the WordSet for this union
	// We are going to need use this function in our WordSet.cpp and our test_wordset.cpp file
	// in order to do the operations we'd like and produce the results being asked of the union
	// of two WordSet objects. Therefore it must be a public member. It is also public because it is
	// an operation
        WordSet operator+(const WordSet& ws) const;

	// Arithmetic overload
	// This will initialize a WordSet to contain both the RHS and LHS of the intersection and then
	// initializes a WordSet as the result. It does the intersection then loops through for the length
	// of the both WordSet to add the items to the result if it is in both the RHS and LHS. It then
	// returns this result WordSet
	// We are going to need use this function in our WordSet.cpp and our test_wordset.cpp file
	// in order to do the operations we'd like and produce the results being asked of the
	// intersection of two WordSet objects. Therefore it must be a public member. It is also
        // public because it is an operation
        WordSet operator*(const WordSet& ws) const;

        // Helper fucntion that returns true if WordSet contains the value 's', false othewise looping
	// through every element in our vector string and checking if it is equal to 's' or not
	// Since this is a helper function of our WordSet class and we are accessing this function
	// directly with our WordSet object, it is a public member
        bool contains(string s) const;
  private:
	// vector string named set to contain an amount of strings
	// meant to be private as it only needs to be used in wordset.cc, only needs to be accessed
	// by other member functions, we don't want this to be manually set to anything, just arbitrary
        vector<string> set;

        // Const version of len for utility in  arithmetic overloads
        // Private because it only needs to be used in wordset.cc (internally)
	// uses size() to return the amount of elements in WordSet
        int len() const;
};

#endif
