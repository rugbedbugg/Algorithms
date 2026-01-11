// 217. Contains Duplicate
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seenElements;

	for (int num: nums) {
		// Check if element is present
		// If yes, exit early
		if (seenElements.count(num)) return true;
		
		// If reaches here, insert element
		seenElements.insert(num);
	}

	return false;
}


int main() {
	vector<int> nums = {1,1,1,3,3,4,3,2,4,2};

	cout << "contains duplicate [T=1|F=0]: " << containsDuplicate(nums) << endl;

	return 0;
}
