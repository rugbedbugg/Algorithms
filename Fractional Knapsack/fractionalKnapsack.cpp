#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

///////////////////
/// Define item ///
///////////////////
struct Item {
    int id;
    int profit;
    int weight;
    double ratio;

    // ----------- //
    // Constructor //
    // ----------- //
    Item(int id, int profit, int weight) {
        this->id = id;
        this->profit = profit;
        this->weight = weight;
        ratio = (double) profit/weight;
    }
};

//////////////////
/// Sort Logic ///
//////////////////
bool compare(Item a, Item b) {
    // --------------------------------- //
    // Greedy Choice:- Highest P:W Ratio //
    // --------------------------------- //
    return a.ratio > b.ratio;
}

//////////////////
/// Main Logic ///
//////////////////
double fractionalKnapsack(int M, vector<Item>& items) {
    // -------------------------------- //
    // Sort highest to lowest P:W ratio //
    // -------------------------------- //
    cout << "Sorting 'items' [highest to lowest P:W]..." << endl;
    sort(items.begin(), items.end(), compare);		

    double totalProfit = 0.0;
    int currentWeight = 0;

    // ------------------- //
    // Make Greedy Choices //
    // ------------------- //
    cout << "Making greedy choices..." << endl;
    for (auto& item: items) {
        if (currentWeight + item.weight <= M) {	
	    
	    // Incrementing values
	    currentWeight += item.weight;
	    totalProfit += item.profit;
        } else {
	    cout << "Taking current highest P:W item exceeds capacity. Taking fractional part..." << endl;
	    // This case is when we have to take a fractional
	    // part an item to reach max profit
	    int remaining = M - currentWeight;
	    if (remaining > 0) {
		double fraction = (double)remaining / item.weight;
		double fractionalProfit = item.profit * fraction;

		totalProfit += fractionalProfit;
	    }
	    // Break since capacity is filled
	    break;   
	}
    }
    // ------------------------------ //
    // Return maximum possible profit //
    // ------------------------------ //
    return totalProfit;
}

///////////////////
/// Driver Code ///
///////////////////
int main() {
    cout << "Initializing starting conditions..." << endl;
    int n=10;	// No. of objects
    int M=15;	// Knapsack capacity
    int profit[] = {10, 5, 15, 7, 6, 18, 3, 12, 20, 8};
    int weight[]  = { 2, 3,  5, 7, 1,  4, 1,  6,  5, 2};

    // ------------------------ //
    // Populating 'items' array //
    // ------------------------ //
    cout << "Populating 'items' array..." << endl;
    vector<Item> items;
    for (int i=0; i<n; i++) {
        items.push_back(Item(i, profit[i], weight[i]));
    }
    // ------------------------------- //
    // Apply fractional knapsack logic //
    // ------------------------------- //
    cout << "Applying Fractional Knapsack..." << endl;
    double maxProfit = fractionalKnapsack(M, items);

    cout << endl << "Maximum Profit: " << fixed << setprecision(2) << maxProfit << endl; 

    return 0;
}
