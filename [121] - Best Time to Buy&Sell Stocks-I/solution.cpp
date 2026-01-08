#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int>& prices) {
	//////////////////////////////////
	/// Initialize starting values ///
	//////////////////////////////////
	int minPrice = INT_MAX;
	int maxProfit = 0;

	////////////////////////////////////////
	/// Insufficient no. of price points ///
	////////////////////////////////////////
	if (prices.size() <= 1) return maxProfit;

	////////////////////////////////////
	/// Check for profit more than 0 ///
	////////////////////////////////////
	for (int currPrice : prices) {
		minPrice = min(minPrice, currPrice);
		maxProfit = max(maxProfit, currPrice-minPrice);
	}
	return maxProfit;
}

int main() {
	vector<int> prices = {5,9,3,7,8};

	cout << "Maximum Profit: " << maxProfit(prices) << endl;

	return 0;
}

