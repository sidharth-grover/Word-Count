#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// Function to convert a string to lowercase
string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Function to remove punctuation from a string
string removePunctuation(const string& str) {
    string result;
    for (char c : str) {
        if (!ispunct(c)) {
            result += c;
        }
    }
    return result;
}

int main() {
    cout << "Enter a paragraph: ";
    string paragraph;
    getline(cin, paragraph);

    // Convert paragraph to lowercase and remove punctuation
    paragraph = toLower(paragraph);
    paragraph = removePunctuation(paragraph);

    // Use a stringstream to split the paragraph into words
    stringstream ss(paragraph);
    string word;
    map<string, int> wordCount;

    while (ss >> word) {
        ++wordCount[word];
    }

    // Print the word frequencies
    cout << "Word frequencies:" << endl;
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
