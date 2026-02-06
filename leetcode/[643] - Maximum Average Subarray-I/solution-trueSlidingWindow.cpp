#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
using namespace std;


double findMaxAverage(vector<int>& nums, int k) {
	// --- Initialize Sliding window --- //	(TRUE SLIDING WINDOW)
	long long windowSum = 0;
	for (int i=0; i<k; i++) {
		windowSum += nums[i];
	}

	// --- Initialize maxSum --- //
	// -- will directly provide us with 'maxAvg'
	long long maxSum = windowSum;

	// --- Iterate over array and keep track of highest average --- //
	for (int right=k; right<nums.size(); right++) {
		windowSum += nums[right];
		windowSum -= nums[right-k];
		
		maxSum = max(maxSum, windowSum);
	}

	return (double)maxSum/k;
}

int main() {
	vector<int> nums = {1,12,-5,-6,50,3};
	int target = 4;

	cout << "Maximum average: " << fixed << setprecision(5) << findMaxAverage(nums, target) << endl;

	return 0;
}
