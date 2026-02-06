#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxArea(vector<int>& height) {
	// --- Initialize pointers --- //
	int left = 0;
	int right = height.size()-1;

	// --- Area variables --- //
	int currArea = 0;
	int maxArea = 0;
	
	// --- Check area --- //
	while (left<right) {
		currArea = min(height[left], height[right]) * (right-left);
		maxArea = max(maxArea, currArea);

		if (height[left]<height[right]) left++;
		else right--;
	}

	return maxArea;
}

int main() {
	vector<int> height = {1,8,6,2,5,4,8,3,7};

	cout << "Max area: " << maxArea(height) << endl;

	return 0;
}
