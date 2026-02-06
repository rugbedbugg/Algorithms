#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<int> getFirstTwoSum(vector<int>& arr, int target) {
	if (arr.size() <= 1) return {};

	//////////////////////////
	/// Initialize Hashmap ///
	//////////////////////////
	unordered_map<int, int> hashmap;

	///////////////////////////////////////
	/// Find first occurence of two sum ///
	///////////////////////////////////////
	for (int i=0; i<arr.size(); i++) {
		// --- Define complement of sum --- //
		int complement = target - arr[i];

		// --- Check if complement of sum exists in hashmap --- //
		// --- .count(key) -> exists: 1 | doesnt exist: 0
		if (hashmap.count(complement)) {
			return {i, hashmap[complement]};
		}
		// --- Add new element to hashmap --- //
		hashmap[arr[i]] = i;

		//// Why check before inserting element:
		// If we do after, we end up counting the inserted element twice
		// Incase it ends up giving the target number
	}

	return {};
}

int main() {
	int target = 12;
	vector<int> arr = {1,4,7,8,9,3,7,3,5,6,1,7};

	vector<int> result = getFirstTwoSum(arr, target);

	if (result.size()) {
		cout << result[0]<<":"<<arr[result[0]] << " | " << result[1]<<":"<<arr[result[1]] << endl;
	} else {
		cout << "Target cannot be formed" << endl;
	}

	return 0;
}
