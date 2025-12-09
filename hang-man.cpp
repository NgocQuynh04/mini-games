//code the Hangman game in C++ that can be played in the console.
//Rules:
    //1. The computer randomly selects a word from a predefined list.
    //2. The player has to guess the word one letter at a time.
    //3. The player has a limited number of incorrect guesses (e.g., 6).
    //4. After each guess, the computer displays the current state of the word and the letters guessed so far.
    //5. The game continues until the player guesses the word or runs out of incorrect guesses.
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <limits>
using namespace std;
string getRandomWord(const vector<string>& wordList) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, wordList.size() - 1);
    return wordList[dist(gen)];
}
void displayState(const string& word, const string& guessedLetters) {
    for (char c : word) {
        if (guessedLetters.find(c) != string::npos) cout << c << " ";
        else cout << "_ ";
    }
    cout << "\nGuessed letters: " << guessedLetters << "\n";
}
bool isWordGuessed(const string& word, const string& guessedLetters) {
    for (char c : word) {
        if (guessedLetters.find(c) == string::npos) return false;
    }
    return true;
}
int main() {
    vector<string> wordList = {"computer", "programming", "hangman", "challenge", "random", "guess"};
    string wordToGuess = getRandomWord(wordList);
    string guessedLetters;
    int incorrectGuesses = 0;
    const int maxIncorrectGuesses = 6;
    cout << "Welcome to Hangman! Try to guess the word.\n";
    while (incorrectGuesses < maxIncorrectGuesses) {
        displayState(wordToGuess, guessedLetters);
        cout << "Enter a letter: ";
        char guess;
        cin >> guess;
        if (guessedLetters.find(guess) != string::npos) {
            cout << "You already guessed that letter. Try again.\n";
            continue;
        }
        guessedLetters += guess;
        if (wordToGuess.find(guess) == string::npos) {
            incorrectGuesses++;
            cout << "Incorrect guess! You have " << (maxIncorrectGuesses - incorrectGuesses) << " guesses left.\n";
        }
        if (isWordGuessed(wordToGuess, guessedLetters)) {
            cout << "Congratulations! You've guessed the word: " << wordToGuess << "\n";
            break;
        }
    }
    if (incorrectGuesses == maxIncorrectGuesses) 
        cout << "Sorry, you've run out of guesses. The word was: " << wordToGuess << "\n";
    return 0;
}
