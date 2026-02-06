#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
using namespace std;


double findMaxAverage(vector<int>& nums, int k) {
	// --- Initialize Sliding window --- //	(NOT A TRUE SLIDING WINDOW)
	int left = 0;
	int right = k-1;

	// --- 'average' trackers --- //
	double currAvg = 0;
	double maxAvg = numeric_limits<double>::lowest();

	// --- Iterate over array and keep track of highest average --- //
	while (right < nums.size()) {
		int sum = 0;
		for (int i=left; i<=right; i++) {
			sum += nums[i];
		}
		currAvg = sum/(double)k;
		maxAvg = max(maxAvg, currAvg);
		
		left++;
		right++;
	}

	return maxAvg;
}

int main() {
	vector<int> nums = {1,12,-5,-6,50,3};
	int target = 4;

	cout << "Maximum average: " << fixed << setprecision(5) << findMaxAverage(nums, target) << endl;

	return 0;
}
