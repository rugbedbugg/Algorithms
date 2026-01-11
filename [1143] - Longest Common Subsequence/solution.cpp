// 1143. Longest Common Subquence
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int longestCommonSubsequence(string a, string b) {
	int n = a.length();
	int m = b.length();

	// --- Create 0-initialized 2D array to build LCS --- //
	// --- vector<int> inner(m+1, 0); ------------------- //
	// --- vector<vector<int>> dp(n+1, inner); ---------- //
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	// --- LCS Algorithm --- //
	for (int i=1; i<n+1; i++) {
	for (int j=1; j<m+1; j++) {
		// --------------------------- //
		// --- Check element match --- //
		// --------------------------- //
		if (a[i-1] == b[j-1]) {
			// ----------------- DEBUG Statements ------------ //
			// cout << endl << "Element match:" << endl; ----- //
			// cout << dp[i][j] << endl; --------------------- //
			// cout << dp[i-1][j-1] << endl; ----------------- //
			// ----------------------------------------------- //
			dp[i][j] = 1 + dp[i-1][j-1];
		} else {
			// ----------------- DEBUG Statements ------------ //
			// cout << endl << "Element mismatch:" << endl; -- //
			// cout << dp[i][j] << endl; --------------------- //
			// cout << dp[i][j-1] << endl; ------------------- //
			// cout << dp[i-1][j] << endl; ------------------- //
			// ----------------------------------------------- //
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}}
	
	return dp[n][m];
}

int main() {
	string a = "wrtvertubryvcwrybutruibvctyret";
	string b = "wqercfw6vtetubervycwetyebvc";

	cout << "Length of Longest Common Subqeuence: " << longestCommonSubsequence(a,b);
	cout << endl;

	return 0;
}
