#include <iostream>
#include <string>
using namespace std;

//////////////////////////
/// 2-Pointer Approach ///
//////////////////////////
bool isPalindrome(string s) {
	// --- Initialize pointers --- //
	int left = 0;
	int right = s.length()-1;
	int i = 0;

	while (left < right) {
		// --- Delete non-alphanumeric chars --- //
		// --- datatype 'unsigned char' adds support for more chars --- //
		while (left<right && !isalnum((unsigned char)s[left])) left++;
		while (left<right && !isalnum((unsigned char)s[right])) right--;
		
		// --- convert to lowercase and check --- //
		if (tolower(s[left]) != tolower(s[right])) return false;

		// --- decrement iterators --- //
		left++;
		right--;
	}
	return true;
}

int main() {
	string s = "/;;,h./el.,l;/o;,,,'.'.'l;/,le,;/h,;/";

	if (isPalindrome(s)) cout << "Palindrome" << endl;
	else cout << "Not Palindrome" << endl;

	return 0;
}
