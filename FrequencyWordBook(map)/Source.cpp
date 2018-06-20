#include"LIbrary.h"
string& toLowerString(string &s) {
	for (int i = 0; i < s.size();i++)
		s[i] = tolower(s[i]);
	return s;
}

int main() {
	setlocale(LC_ALL, "Russian");

	map<string, int> dict;
	ifstream in_file("First.txt");
	string word,word2;
	vector<string>words;

	int count = 0;
	if (!in_file) {
		cout << "File open error" << endl;
	}
	else {
		while (!in_file.eof()) {
			in_file >> word;
			words.push_back(word);
		}
	}
	for (int i = 0;i < words.size();i++) {
		toLowerString(words[i]);
	}
	for (int i = 0;i < words.size();i++) {
		dict[words[i]]++;
	}
	for (auto it = dict.begin();it != dict.end();it++)
		cout << it->first << "\t" << it->second << endl;
	in_file.close();


	in_file.open("Second.txt");
	if (!in_file) {
		cout << "File open error" << endl;
	}
	else {
		while (!in_file.eof()) {
			in_file >> word2;
			toLowerString(word2);
			count = 0;
			for (auto it = dict.begin();it != dict.end();it++) {
				if (word2 == it->first) {
					count++;
				}
			}
			
			if (count == 0) {
				cout << " Word not found." << endl;
				int k;
				cout << "1. replace the word, "<<endl;
				cout << "2. add to the dictionary "<<endl;
				cin >> k;
				switch (k)
				{
					
				case 1: {
					string newWord;
					cout << "Enter a newWord: ";
					cin >> newWord;
					dict[newWord]++;
					
				}break;

				case 2: {
					dict[word2]++;
					
				}break;
				}
			}
		}
	}
	for (auto it = dict.begin();it != dict.end();it++)
		cout << it->first << "\t" << it->second << endl;
	in_file.close();

	ofstream out;
	out.open("Third.txt");
	for (auto it = dict.begin();it != dict.end();it++)
		out << it->first << "\t" << it->second << endl;
	out.close();

	system("pause");
	return 0;
}

