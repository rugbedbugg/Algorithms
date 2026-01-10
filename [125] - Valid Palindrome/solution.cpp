#include <iostream>
#include <string>
#include <stack>
using namespace std;


bool isPalindrome(string s) {
	// --- Sanitize input --- //
	// ------------------------------------------------------ //
	// --- Iterate backwards to avoid shifting of iterator
	// for (int i=s.length()-1; i>=0; i--) {		  // T.C: O(n^2)
	//	bool alphanumeric = 
	//		(s[i] >= 48 && s[i] <= 57) ||
	//		(s[i] >= 65 && s[i] <= 90) || 
	//		(s[i] >= 97 && s[i] <= 122);
	//	bool upperCase =
	//		(s[i] >= 65 && s[i] <= 90);

		// -- Remove non-alphanumeric (Shorten string)
	//	if (!alphanumeric) { s.erase(i,1); continue; }	  // .erase() is O(n) [!!!]
		// -- Convert capital to small
	//	if (upperCase) s[i] += 32;
	// ------------------------------------------------------ //
	// ------------------------------------------------------ //
	// --- Better Sanitization --- //
	int k = 0;
	for (int i=0; i<s.length(); i++) {
		if (isalnum(s[i])) {
			s[k++] = tolower(s[i]);
		}
	}
	s.resize(k);
	// ------------------------------------------------------- //

	}
	cout << "Sanitized string: ";
	for (char s_i: s) {
		cout << s_i;
	}
	cout << endl << endl;

	// --- Initialize starting variables --- //
	stack<char> firsthalf;
	int mid = s.length()/2;
	cout << "Initialized" << endl;

	// --- Check if palindrome --- //
	// --- 1. Populate stack with first half of elements
	for (int i=0; i<mid; i++) {
		firsthalf.push(s[i]);
	}
	cout << "Stack Populated" << endl << endl;
	// --- 2. Compare top of stack with second half elements
	mid = (s.length() % 2 == 0)?  mid : mid+1;
	for (int i=mid; i<s.length(); i++) {
		// -- If stack is empty nothing to match with
		// -- second half of string longer than first half
		// -- Hence NOT Palindrome
		if (firsthalf.empty()) {
			cout << "Stack empty!" << endl;
			return false;
		}
		// Palindrome logic
		if (firsthalf.top() == s[i]) {
			cout << "Popped " << firsthalf.top() << endl;
			firsthalf.pop();
		}
		// -- Early exit if mismatch
		else {
			cout << "Element mismatch" << endl;
			return false;
		}
	}
	
	return true;
}


int main() {
	string str = "hello::;;._lleh";

	if (isPalindrome(str)) {
		cout << "Palindrome" << endl;
	} else cout << "Not Palindrome" << endl;

	return 0;
}
