#include <iostream>
#include <string>
using namespace std;


bool naiveSMA(const string& main_str, const string& ptrn) {
	int mainLen = main_str.length();
	int ptrnLen = ptrn.length();

	for (int i=0; i<=mainLen-ptrnLen; i++) {
		int matchLen = 0;
		for (int j=0; j<ptrnLen; j++) {
			if (main_str[i+j] != ptrn[j]) break;
			matchLen++;
		}
		if (matchLen == ptrnLen) return true;
	}
	return false;
}

int main() {
	string mainString = "25f4eytbtyeb";
	string patternString = "ytbt";

	string matchStatus = naiveSMA(mainString, patternString)? " ": " not ";

	cout << "\'" << patternString << "\'";
       	cout << " is" << matchStatus << "a substring of ";
	cout << "\'" << mainString << "\'" << endl;

	return 0;
}
