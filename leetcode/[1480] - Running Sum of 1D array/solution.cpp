#include <iostream>
#include <vector>
using namespace std;

vector<int> getRunningSum(vector<int>& nums) {
	
	////////////////////////////////////
	/// Initialize staring variables ///
	////////////////////////////////////
	vector<int> runningSumArray = {};
	int runningSum = 0;

	//////////////////////////////////
	/// Populate running Sum array ///
	//////////////////////////////////
	for (int i=0; i<nums.size(); i++) {
		runningSum += nums[i];
		runningSumArray.push_back(runningSum);
	}

	return runningSumArray;
}

int main() {
	vector<int> nums = {1,5,7,3,8,3,0,4,5};
	vector<int> runningSum = getRunningSum(nums);
	
	for (int num : nums) {
		cout << num << " ";
	}
	cout << endl;
	for (int num : runningSum) {
		cout << num << " ";
	}
	cout << endl;

	return 0;
}
