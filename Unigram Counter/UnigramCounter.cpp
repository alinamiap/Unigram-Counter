//Alina Palomino
//This program determines how many times a unigram is repeated in a string
#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<sstream>
#include<string>

using namespace std;

int main() {
	//Declare a set to store a unique collection of elements
	set<string>unigram_set;

	//Declare a map to store a collection of values
	map<string, int>count_map;

	//Declare one string for user input, another for 
	string input;
	string word;

	//Ask user to enter a string, assign to input
	cout << "Please enter a string: ";
	getline(cin, input);

	//Pass input to a stringstream to break individual words
	stringstream ss(input);

	//Remove any symbols and adjust all letters to lowercase
	while (ss >> word) {
		transform(word.begin(), word.end(), word.begin(), [](unsigned char c) {return tolower(c); });
		word.erase(remove_if(word.begin(), word.end(), [](unsigned char c) { return !isalnum(c); }), word.end());
		unigram_set.insert(word);
		count_map[word]++;
	}

	//Display the unigram and it's count
	cout << "Unigram\t" << "Count\n";
	for (const auto& unigram : unigram_set) {
		cout << unigram << "\t" << count_map[unigram] << endl;
	}

	return 0;
}