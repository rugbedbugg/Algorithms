#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int subArraySumK(vector<int>& nums, int k) {
	/////////////////////////////////////
	/// Initialize starting variables ///
	/////////////////////////////////////
	unordered_map <int, int> runningSumFreq;
	runningSumFreq[0] = 1;	// For sub arrays starting with 0 index

	int runningSum = 0;
	int count = 0;
	
	////////////////////////////////////
	/// Store running sum in hashmap ///
	////////////////////////////////////
	for (int num : nums) {
		// --- Get running sum --- //
		runningSum += num;

		// --- previousRunningSum = currRunningSum - k --- //
		int extraSum = runningSum - k;
		
		// --- If that previousRunningSum exists ----- //
		// --- Add all occurences of that to count --- //
		if (runningSumFreq.find(extraSum) != runningSumFreq.end()) {
			count += runningSumFreq[extraSum];
		}
		// --- Add current prefixSum to hashmap ---------- //
		runningSumFreq[runningSum]++;
	}

	return count;
}

int main() {
	vector<int> nums = {1,6,7,9,4,8,1,5};
	int target = 13;
	
	cout << subArraySumK(nums, target) << endl;

	return 0;
}
