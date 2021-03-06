// Word Jumble 1.0
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  enum fields {WORD, HINT, NUM_FIELDS};
  const int NUM_WORDS = 5;
  const string WORDS[NUM_WORDS][NUM_FIELDS] =
  {
    {"wall", "Do you feel you're banging your head against something?"},
    {"glasses", "These might help you see the answer."},
    {"labored", "Going slowly, is it?"},
    {"persistent", "Keep at it."},
    {"jumble", "It's what the game is all about."}
  };
  int points = 0;

  srand(static_cast<unsigned int>(time(0)));
  int choice = (rand() % NUM_WORDS);
  // word to guess
  string theWord = WORDS[choice][WORD];
  // hint for word
  string theHint = WORDS[choice][HINT];

  // jumbled version of word
  string jumble = theWord;
  int length = jumble.size();
  for (int i = 0; i < length; ++i)
  {
    int index1 = (rand() % length);
    int index2 = (rand() % length);
    char temp = jumble[index1];
    jumble[index1] = jumble[index2];
    jumble[index2] = temp;
  }

  cout << "\t\tWelcome to Word Jumble!\n\n";
  cout << "Unscramble the letters to make a word.\n";
  cout << "Enter 'hint' for a hint.\n";
  cout << "Enter 'quit' for a quit the game.\n\n";
  cout << "The jumble is: " << jumble;

  string guess;
  cout << "\n\nYour guess: ";
  cin >> guess;

  while ((guess != theWord) && (guess != "quit"))
  {
    if (guess == "hint")
    {
      points -= 1;
      cout<<"\nThis cost you 1 point!\n\n";
      cout << theHint;
    }
    else
    {
      cout << "Sorry, that's not it.";
    }
    cout << "\n\nYour guess: ";
    cin >> guess;
  }

  if (guess == theWord)
  {
    points += theWord.size();
    cout << "\nThat's it! You guessed it!\n";
    if (points < 0)
      points = 0;
    cout << "Your score: " << points << endl;
  }

  cout << "\nThanks for playing.\n";

  return 0;
}

