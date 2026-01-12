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
	// -------------------------- //
	// --- Print matrix names --- //
	// -------------------------- //
	if (i==j) { cout << "A" << i;
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
		const vector<int>& dims,
		vector<vector<int>>& split) {
	// ------------------------------------------------------------ //
	// --- Represents number of matrices to be multiplied --------- //
	// ------------------------------------------------------------ //
	int n = dims.size() - 1;


	// --- Initialising split & multRes arrays --- //
	// --- 1. split[i][j] = k
	//        - k lies b/w  i & j
	//        - denotes where parenthesization split takes place
	//        - .. (Ai .. Ak)(Ak+1 .. Aj) ..
	// --- 2. multReqd[i][j] = no. of mult. reqd. for Ai*A(i+1)...Aj
	// --- 3. multReqd_partial = same as above but is a generalised variable
	// --------------------------------------------------------------------- // 
	vector<vector<int>> multReqd(n, vector<int>(n, 0));		         // 0-matrix of n*n
	split.assign(n, vector<int>(n, 0));		 		         // replace w/ 0-matrix of n*n

	// --------------------------------------------------------------------- //
	// --- gap = no. of matrices present in smallest Sub-chain ------------- //
	//     Ex:- abc = a(bc)
	for (int gap=1; gap < n; gap++) {
	for (int start=0; start < n; start++) {
		int end = start + gap;
		if (end >= n) break;

		// --- Assuming no. of mult. reqd. to compute Ai*A(i+1)...Aj to be very high
		// --- Such that it covers the highest possible as well
		multReqd[start][end] = INT_MAX;

		// --- 'k' is always between 'start' & 'end'
		for (int k=start; k<end; k++) {
			int multReqd_partial = 
					multReqd[start][k]			// no. of mult. reqd. to compute 'Sub-chain #1'
				 	+ multReqd[k+1][end]			// no. of mult. reqd. to compute 'Sub-chain #2'
				 	+ dims[start]*dims[k+1]*dims[end+1];	// no. of mult. reqd. to compute (Sub-chain #1)*(Sub-chain #2)

			// --- Choose matrix grouping with least no. of mult. reqd. to compute --- //
			if (multReqd_partial < multReqd[start][end]) {
				multReqd[start][end] = multReqd_partial;
				split[start][end] = k;
			}
		}
	}}
	int minMultReqd_chain = multReqd[0][n-1];

	return minMultReqd_chain;
}

int main() {
	vector<int> dims = {10, 30, 5, 60};
	vector<vector<int>> split;

	int minCost = matrixChainMultiply(dims, split);

	cout << "Minimum cost: " << minCost << endl; 
	cout << "Optimal parenthesization: ";
	printOptimalParenthesization(split, 0, dims.size()-2);
	cout << endl;

	return 0;
}
