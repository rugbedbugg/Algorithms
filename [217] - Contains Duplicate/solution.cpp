// 217. Contains Duplicate
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seenElements;

	for (int num: nums) seenElements[num]++;
	for (int num: nums) {
		if (seenElements[num]>1) return true;
	}

	return false;
}


int main() {
	vector<int> nums = {1,1,1,3,3,4,3,2,4,2};

	cout << "contains duplicate [T=1|F=0]: " << containsDuplicate(nums) << endl;

	return 0;
}
