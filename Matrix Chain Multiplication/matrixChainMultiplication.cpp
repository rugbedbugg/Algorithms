// Matrix Chain Multiplication
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

////////////////////////////////
/// Output: (A1(A2A3)(A4A5)) ///
////////////////////////////////
void printOptimalParenthesization(
		const vector<vector<int>>& split,
		int i, int j) {
	// ------------------------- //
	// --- Print matrix name --- //
	// ------------------------- //
	if (i==j) {
		cout << "A" << j;
		return;
	}
	// ------------------------- //
	// --- Propagation Logic --- //
	// ------------------------- //
	cout << "(";
	printOptimalParenthesization(split, i, split[i][j]);
	printOptimalParenthesization(split, split[i][j]+1, j);
	cout << ")";
}

/////////////////////////////////////////
/// Find the Optimal Parenthesization ///
/////////////////////////////////////////
// Input:-
// --- d[] -> dimnesions of arrays of size n+1
// --- d = {d0, d1, d2, d3}
// --- Matrices: A0(d0*d1), A1(d1*d2), A3(d2*d3) ...
// --- no. of mult; reqd. for A0*A1 = d0*d1*d2
// Output:-
// --- 1. return minimum number of scalar multiplications 
//        required to computed the result
// --- 2. Fills in locations for parenthesization split 
//       Ex:- ((ab).((cd).e))
//       - split location 1: b/w i=1 & i=2
//       - split location 2: b/w i=3 & i=4
int matrixChainMultiply(
		const vector<int>& d,
		vector<vector<int>>& split) {
	// ------------------------------------------------------ //
	// --- Represents number of matrices to be multiplied --- //
	int n = d.size()-1;


	// --- Initialising split & dp arrays --- //
	// --- 1. split[i][j] = k
	//        - k lies b/w  i & j
	//        - denotes where parenthesization split takes place
	//        - .. (Ai .. Ak)(Ak+1 .. Aj) ..
	// --- 2. dp[i][j] = no. of mult. reqd. for Ai*A(i+1)...Aj
	// --- 3. cost = same as above but is a generalised variable
	// -------------------------------------- // 
	split.assign(n+1, vector<int>(n+1, 0));		 	// replacing previous content with 0-matrix of (n+1)*(n+1)
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));	// Defining 'cost' (aka dp) 0-matrix of (n+1)*(n+1)
	

	// -------------------------------------------------------------- //
	// --- length = no. of matrices present in smallest Sub-chain --- //
	//     Ex:- abc = a(bc)
	for (int length=2; length<=n; length++) {
	for (int i=1; i<=n-length+1; i++) {
		// --- 
		int j = i+length-1;
		dp[i][j] = INT_MAX;			 	// Assuming no. of mult. reqd. to compute Ai*A(i+1)...Aj to be very high
								// Such that it covers the highest possible as well
	
		for (int k=i; k<j; k++) {
			int cost = dp[i][k]		 	// no. of mult. reqd. to compute 'Sub-chain #1'
				 + dp[k+1][j]		 	// no. of mult. reqd. to compute 'Sub-chain #2'
				 + d[i-1] * d[k] * d[j]; 	// no. of mult. reqd. to compute (Sub-chain #1)*(Sub-chains #2)

			// --- Check if current cost is greater/lesser than current cost --- //
			if (cost < dp[i][j]) {
				dp[i][j] = cost;
				split[i][j] = k;
			}
		}
	}}

	return dp[1][n];
}

int main() {
	vector<int> d = {10, 30, 5, 60};
	vector<vector<int>> split;

	int minCost = matrixChainMultiply(d, split);

	cout << "Minimum cost: " << minCost << endl; 
	cout << "Optimal parenthesization: ";
	printOptimalParenthesization(split, 1, d.size()-1);
	cout << endl;

	return 0;
}
