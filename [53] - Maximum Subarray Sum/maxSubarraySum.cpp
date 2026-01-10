#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

///////////////////////
/// Cross sum logic ///
///////////////////////
long long getMaxCrossSum(const vector<int>& arr, int low, int mid, int high) {
	// --- Initialize sum --------- // 
	long long sum = 0;

	// --- Left side -------------- //
	long long leftSide = INT_MIN;
	sum = 0;
	for (int i=mid; i>=low; i--) {
		sum += arr[i];
		leftSide = max(leftSide, sum);
	}
	// --- Right side ------------- //
	long long rightSide = INT_MIN;
	sum = 0;
	for (int i=mid+1; i<=high; i++) {
		sum += arr[i];
		rightSide = max(rightSide,sum);
	}
	// --- Debugging --- //
	// cout << leftSide << endl;
	// cout << rightSide << endl;
	// cout << leftSide+rightSide << endl << endl;
	
	return leftSide + rightSide;
}
///////////////////
/// Propagation ///
///////////////////
int getMaxSubarraySum(const vector<int>& arr, int low, int high) {
	if (low == high) return arr[low];

	// --- Initialize mid -------- //
	int mid = low + (high-low)/2;

	// --- Get the maximum possible subarray ------- //
	// --- CASE 1: Left subarray sum is largest ---- //
	// --- CASE 2: Right subarray sum is largest --- //
	// --- CASE 3: Cross subarray sum is largest --- //
	int leftSum = getMaxSubarraySum(arr, low, mid);
	int rightSum = getMaxSubarraySum(arr, mid+1, high);
	int crossSum = (int) getMaxCrossSum(arr, low, mid, high);
	
	// --- Find Max sub-array sum value --- // 
	int maxSum = max(leftSum, rightSum);
	maxSum = max(maxSum, crossSum);

	return maxSum;
}
/////////////////
/// Intiation ///
/////////////////
int maxSubarraySum(vector<int>& arr) {
	return getMaxSubarraySum(arr, 0, arr.size()-1);
}

///////////////////
/// Driver Code ///
///////////////////
int main() {
	vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int maxSum = maxSubarraySum(arr);

	cout << "Maximum sub-array sum possible in given array is: ";
	cout << maxSum << endl;

	return 0;
}
