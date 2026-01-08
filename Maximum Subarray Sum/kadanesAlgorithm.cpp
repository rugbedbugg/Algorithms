#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int kadane(const vector<int>& arr) {
	int currSum = arr[0];
	int maxSum = arr[0];

	for (int i=1; i<arr.size(); i++) {
		currSum = max(currSum+arr[i], arr[i]);
		maxSum = max(maxSum, currSum);
	}

	return maxSum;
}

int main() {
	vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};

	int maxSum = kadane(arr);
	cout << "Maximum subarray sum using Kadane's Algorithm is: ";
	cout << maxSum << endl;

	return 0;
}

