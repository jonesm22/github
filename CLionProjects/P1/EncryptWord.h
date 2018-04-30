// Author: Melissa Jones
// Filename: EncryptWord.h
// Date: Oct. 9th, 2017
// Revision History: No previous revisions


//Class Overview: This class takes in a word, or series or words.
//Filters out all whitespaces, numbers and special characters and
//encrypts the remaining letter characters with a Caeser Cipher
//shift that is randomly generated between 1 and 20. This class
//also has functions that allow for queries into what the private
//shift is, tracking of the number of queries, the highest query,
//lowest query, and average query. This class allows the counters
//and statistics to be reset to zero and for the ability to decrypt
//the word.

//Assumptions: This class

//Functionality: This class is designed to encrypt characters and
//can handle queries pretaining to the cipher shift

//Legal Input: Integers may be passed as guesses in the queries
//and words may contain special characters, numbers, whitespaces,
//capital and lowercase letter characters may be included. However,
//only letters characters will be encrypted. The object must take only
//strings of characters or numbers.

//Illegal Input: None integer numbers or characters in the queries,
//non-string inputs into the object.

//Output: numeric statistics on the queries, a string of encrypted
// characters, a string of non-encrypted characters.

#ifndef P1_2_ENCRYPTWORD_H
#define P1_2_ENCRYPTWORD_H
#include <iostream>
#include <sstream>
using namespace std;


class EncryptWord{
private:
    string word; //the word to be encrypted
    int querycount; //counts the number of queries
    int highGuessHolder; //holds the highest shift guess
    int lowGuessHolder; //holds the lowest shift guess
    int sumOfGuesses; //holds the sume of all guess values
    int shift; // the private shift

public:
    explicit EncryptWord(string word);
    //description: Initializes the guess holder values, query
    //counter, sum of all guesses to zero. Initializes the shift
    //to a random integer between 1 and 20.
    //precondition: A string must be passed as a parameter.
    //postcondition: If a string is not passed, the program will
    //not function as intended.
    string encryptOn();
    //description: takes the word given by the user and
    //precondition: The user can enter any line, it must
    //include letter characters. If it contains numbers,
    //whitespace, or special characters those will be deleted
    //postcondition:the returned string will only contain
    //characters and will be encrypted with a Caeser Cipher shift.
    bool isRightShift(int);
    //description: Takes in the value guessed by the user and compares
    //it to the private cipher shift. Returns true if the given int and
    //the shift are equal
    //precondition: none
    //postcondition: none
    int getQueryCount() const;
    //description: Gets the number of queries and returns it
    //precondition: none
    //postcondition: Value returned may be 0 if reset or no queries have
    //occured.
    int reset();
    //description: Resets the query counter, high guess value,
    //low guess value
    //and sum of all gues values to zero.
    //precondition: none
    //postcondition: none
    string decrypt();
    //description: Returns the original message used for decryption.
    //precondition: The processed input from the user will be used
    //postcondition: No whitespace, special characters or numbers
    //will be included in the returned string.
    string processLine(string);
    //description: Removed and whitespace, numbers, and special
    //characters that the user may have inputted along with the
    //original word or phrase to be encrypted.
    //precondition: Input may contain numbers, whitespace,
    //special characters.
    //postcondition: Only characters will be returned in one 'word'.
    //No other types of character will be filtered out
    void highestGuess(int);
    //description: Takes in the users guessed value and
    //compares it with the current high shift guess to find the
    //new high value guessed.
    //precondition: Only integers can be passed in as a parameter
    //postcondition: If an integer is not given this function may
    //not compare values properly.
    int averageGuess();
    //description: Averages the sum of all guessed shift values
    //with the number of guesses the user has taken
    //precondition: All guesses prior must be numeric values
    //postcondition: Will not compute properly if a non-numeric
    //was passed in as a guess
    int getHighestGuess() const;
    //description: Gets and returns the highest value guessed by a user.
    //precondition: none
    //postcondition: May be zero if reset or no queries have occured.
    //May not function if a non-numeric was given in a query.
    int getLowestGuess() const;
    //description: Gets and returns the lowest value guessed by a user.
    //precondition: none
    //postcondition: May be zero if reset or no queries have occured.
    //May not function if a non-numeric was given in a query.
    void guessIncrement(int);
    //description: Increments the query counter. Adds the current guess
    //to the value that holds the sum of all guesses. Checks for the new
    //highest and lowest query value.
    //precondition: Must be a numeric value passed in as a parameter
    //postcondition: If a non-numeric value is given not all parts of
    //the function will work.
    void lowestGuess(int);
    //description: Takes in the value guessed by the user and
    //precondition: Must take an numeric value as a parameter
    //postcondition: If a numeric value is not given the lowest value
    //will not be accurately calculated.
};



#endif //P1_2_ENCRYPTWORD_H
