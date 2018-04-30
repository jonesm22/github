// Author: Melissa Jones
// Filename: EncryptWord.cpp
// Date: Oct. 9th, 2017
// Revision History: No previous revisions


#include "EncryptWord.h"

using namespace std;

/**
 * The constructor initializes the counters, word, and the shift
 * @param word given by the user
 */
EncryptWord::EncryptWord(string word){
    this -> word = word;
    querycount = 0;
    highGuessHolder = 0;
    lowGuessHolder = 0;
    sumOfGuesses = 0;
    srand((unsigned)time(0));
    shift = rand() % 20 + 1;
}

/**
 * Encrypts the given word after processing out spaces and non-characters.
 * If a word is too small, a dummy word will be used instead.
 * @returns the encrypted word
 */
string EncryptWord::encryptOn(){
    string wrd = processLine(word);
    if(wrd == "small"){
        return "dummywordreplacement";
    }
    string encrypted;
    for (int i = 0; i < wrd.length(); i++){
        if (isupper(wrd[i])){
            encrypted += char((wrd[i] + shift - 65) % 26 + 65);
        } else {
            encrypted += char((wrd[i] + shift - 97) % 26 + 97);
        }
    }
    return encrypted;
}

/**
 * Getter for the query count
 * @returns the number of queries
 */
int EncryptWord::getQueryCount() const {
    return querycount;
}

/**
 * Resets the query count
 * @returns the reset values
 */
int EncryptWord::reset(){
    this -> highGuessHolder = 0;
    this -> lowGuessHolder = 0;
    this -> sumOfGuesses = 0;
    querycount = 0;
}

/**
 *"Decrypts" the encrypted word
 * @returns the original word, prior to encrypting
 */
string EncryptWord::decrypt(){
    return processLine(word);
}

/**
 * Processes the input given by the user to reflect a 'word'.
 * That is, no spaces and no special characters.
 * @param input the line of characters given by the user
 * @returns the process word
 */
string EncryptWord::processLine(string input){
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    string processedword;
    for(int i = 0; i < input.length(); i++){
        if (isalpha(input[i])){
            processedword += input[i];
        }
    }
    if(processedword.length() < 4){
        return input = "small";
    }
    return processedword;
}

/**
 * Evaluates if the users guess matches the secret shift
 * @param guess given by the user
 * @return a boolean
 */
bool EncryptWord::isRightShift(int guess){
    if (guess == shift){
        return true;
    }
    return false;
}

/**
 * Increments the query count, changes highest guess if necessary,
 * and adds the current guess to the sum of all guesses
 * @param guess given from the user
 */
void EncryptWord::guessIncrement(int guess){
    if(guess != 0) {
        querycount++;
        highestGuess(guess);
        lowestGuess(guess);
        sumOfGuesses += guess;
    }
}

/**
 * Compares to see if the current shift guess is the highest
 * guess given
 * @param currentguess is the users current guess
 */
void EncryptWord::highestGuess(int currentguess){
    if (currentguess > highGuessHolder){
            highGuessHolder = currentguess;
    }
}

/**
 * Compares to see if the current shift guess is the lowest
 * guess given
 * @param currentguess
 */
void EncryptWord::lowestGuess(int currentguess){
    if(lowGuessHolder == 0){
        lowGuessHolder = currentguess;

    }
    if(currentguess < lowGuessHolder){
        lowGuessHolder = currentguess;
    }
}

/**
 * Getter for the highest guess
 * @returns the highest value guessed
 */
int EncryptWord::getHighestGuess() const {
    return highGuessHolder;
}

/**
 * /**
 * Getter for the lowest guess
 * @return the lowest value guessed
 */
int EncryptWord::getLowestGuess() const {
    return lowGuessHolder;
}

/**
 *
 * Calculates the average number guessed for the shift
 * @returns the average the user guessed for the shift
 */
int EncryptWord::averageGuess() {
    int average;
    if (querycount != 0) {
       average =  sumOfGuesses / querycount;
    }
    if(querycount == 0){
        return 0;
    }
    return average;
}



