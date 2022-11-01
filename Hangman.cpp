
//Anas Banta Seutia, 2019
//Simple Hangman console game

#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <algorithm>
#include <ctime>

using namespace std;

void printHangman(int chancesLeft)
{
	switch (chancesLeft)
	{
	case 6:
		cout << "  ___   " << endl;
		cout << " |   |  " << endl;
		cout << " |      " << endl;
		cout << " |      " << endl;
		cout << " |      " << endl;
		cout << "_|__    " << endl;
		cout << endl;
		break;
	case 5:
		cout << "  ___   " << endl;
		cout << " |   |  " << endl;
		cout << " |   O  " << endl;
		cout << " |      " << endl;
		cout << " |      " << endl;
		cout << "_|__    " << endl;
		cout << endl;
		break;
	case 4:
		cout << "  ___   " << endl;
		cout << " |   |  " << endl;
		cout << " |  _O  " << endl;
		cout << " |      " << endl;
		cout << " |      " << endl;
		cout << "_|__    " << endl;
		cout << endl;
		break;
	case 3:
		cout << "  ___   " << endl;
		cout << " |   |  " << endl;
		cout << " |  _O_ " << endl;
		cout << " |      " << endl;
		cout << " |      " << endl;
		cout << "_|__    " << endl;
		cout << endl;
		break;
	case 2:
		cout << "  ___   " << endl;
		cout << " |   |  " << endl;
		cout << " |  _O_ " << endl;
		cout << " |   |  " << endl;
		cout << " |      " << endl;
		cout << "_|__    " << endl;
		cout << endl;
		break;
	case 1:
		cout << "  ___   " << endl;
		cout << " |   |  " << endl;
		cout << " |  _O_ " << endl;
		cout << " |   |  " << endl;
		cout << " |  /   " << endl;
		cout << "_|__    " << endl;
		cout << endl;
		break;
	case 0:
		cout << "  ___   " << endl;
		cout << " |   |  " << endl;
		cout << " |  _O_ " << endl;
		cout << " |   |  " << endl;
		cout << " |  / \\ " << endl;
		cout << "_|__    " << endl;
		cout << endl;
		break;
	}
}

void printWord(string word, vector<char> revealedLetters)
{
	for (int i = 0; i < word.length(); i++)
	{
		if (count(revealedLetters.begin(), revealedLetters.end(), word[i]) > 0)
		{
			cout << char(toupper(word[i])) << " ";
		}
		else
		{
			cout << "__ "; 
		}
	}
	cout << endl;
}

bool letterExists(string word, char letter)
{
	bool exists = false;
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] == letter)
		{
			exists = true;
		}
	}
	return exists;
}

int numOfUniqueLetters(string word)
{
	vector<char> uniqueLetters;
	for (int i = 0; i < word.length(); i++)
	{
		if (!(count(uniqueLetters.begin(), uniqueLetters.end(), word[i]) > 0))
		{
			uniqueLetters.push_back(word[i]);
		}
	}

	return (int)uniqueLetters.size();
}

int main(int argc, char *argv[])
{
	cout << "Welcome to Hangman!" << endl;

	vector<string> dictionary;
	dictionary.push_back("biscuit");
	dictionary.push_back("alarming");
	dictionary.push_back("anas");
	dictionary.push_back("memorable");
	dictionary.push_back("yellow");
	dictionary.push_back("jacket");
	dictionary.push_back("bumblebee");
	dictionary.push_back("purse");
	dictionary.push_back("pencil");
	dictionary.push_back("genes");
	dictionary.push_back("programming");
	dictionary.push_back("technology");
	dictionary.push_back("keyboard");
	dictionary.push_back("tabby");
	dictionary.push_back("cupboard");

	vector<char> guessedLetters;
	vector<char> successfulLetters;

	string playAgain = "y";
	while (playAgain == "y")
	{
		system("CLS");
		srand(time(NULL));
		int randomSpot = (rand()%(dictionary.size()));
		string randomWord = dictionary[randomSpot];

		int chances = 6;
		guessedLetters.clear();
		successfulLetters.clear();

		printHangman(chances);
		printWord(randomWord, successfulLetters);

		while ((chances > 0)&&(successfulLetters.size() != numOfUniqueLetters(randomWord)))
		{
			char guess = '1';
			while (!isalpha(guess))
			{	
				
				cout << "Please enter a letter! You have " << chances << " chance(s) left." << endl;
				cin >> guess;
				guess = tolower(guess);
				system("CLS");
				if (!isalpha(guess))
				{
					cout << "Your guess is not a letter; guess again" << endl;
				}
				else if (count(guessedLetters.begin(), guessedLetters.end(), guess) > 0)
				{
					cout << "You have already guessed that; guess again" << endl;
				}
				else
				{
					guessedLetters.push_back(guess);
					if (letterExists(randomWord, guess))
					{
						cout << "Great guess! That letter is found in the word." << endl;
						successfulLetters.push_back(guess);
					}
					else
					{
						cout << "Sorry, your guess was not found in the word!" << endl;
						chances--;
					}
				}
				printHangman(chances);
				printWord(randomWord, successfulLetters);
			}
			
		}

		if (chances == 0)
		{
			printHangman(0);
			cout << "You lost! The word was \"" << randomWord << "\"." << endl;
		}
		else if (successfulLetters.size() == numOfUniqueLetters(randomWord))
		{
			cout << "Yay! You won Hangman << endl;
		}

		playAgain = "foo";
		while (!((playAgain == "y")||(playAgain == "n")))
		{
			
			cout << "Would you like to play again? (y/n)." << endl;
			cin >> playAgain;
			if (!((playAgain == "y")||(playAgain == "n")))
			{
				system("CLS");
				cout << "Invalid input; try again" << endl;
			}
		}
	}
	system("CLS");
	return 0;
}