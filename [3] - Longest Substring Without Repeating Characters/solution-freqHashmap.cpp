#include <iostream>
#include <unordered_map>
using namespace std;


int lengthOfLongestSubstring(string s) {
	// --- Initialize starting variables --- //
        unordered_map<char, int> freq;
        int left = 0;
        int maxLen = 0;

        // --- Single Pass through array ------- //
        for (int right=0; right<s.length(); right++) {
        	// --- Add new character to sub-array ------- //
            	freq[s[right]]++;
            
            	// --- If duplicate, shrink subarray -------- //
            	// --- abcdefc -> defc -- //
            	while (freq[s[right]] > 1) {
                	freq[s[left]]--;
                	left++;
            	}
            	// --- Update length ---- //
            	int currLen = right-left+1;
            	maxLen = max(maxLen, currLen);
        }

        return maxLen;
}

int main() {
	string s = "yuctriuweiwyerdeqrtin";

	cout << "Maximum Substring length is: " << lengthOfLongestSubstring(s) << endl;

	return 0;
}
