#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


int lengthOfLongestSubstring(string s) {
	// --- Initialize starting variables --- //
	unordered_map<char, int> prevIndex;	// Stores char,INDEX pair
	int left = 0;
	int maxLen = 0;

	// --- Single Pass through array ------- //
	for (int right=0; right<s.length(); right++) {	
		// --- If duplicate, shrink substring -------- //
		// --- abcdefc -> defc -- //
		while (prevIndex.count([s[right]]) && left <= prevIndex[s[right]]) {
			left = prevIndex[s[right]] + 1;
		}
		// --- Add the new character to substring ------- //
		prevIndex[s[right]] = right;
	
		// --- Update length ---- //
		int currLen = right-left+1;
		maxLen = max(maxLen, currLen);
	}

	return maxLen;
}

int main() {
	string s = "afcdlcasdcfl";

	cout << "Length of longest substring: " << lengthOfLongestSubstring(s) << endl;

	return 0;
}

