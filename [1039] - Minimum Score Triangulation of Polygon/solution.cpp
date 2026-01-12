#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int minScoreTriangulation(vector<int>& values) {
	// --- Initialize staring vairables ------------------- //
	int n = values.size();
	int triangleWeight = 1;
	
	// --- sides * sides dimensional matrix --------------- //
	vector<vector<int>> tScore(sides, vector<int>(n, 0));

	// --- Calculate Score --- //
	// --- 'length' is the max dist. of 'j' from 'i' 
	for (int vertexGap=2; vertexGap < n; vertexGap++) {
	for (int start=0; start < n; start++) {
		// --- 'end' should be right of 'start' ------- //
		int end = start + vertexGap;
		if (end >= n) break;
		
		// --- Assume very high triangulation score --- //
		// --- Done to surpass the actual max triangulation score --- //
		tScore[start][end] = INT_MAX;

		// --- 'split' always b/w 'start' & 'end' ----- //
		for (int split=start+1; split<end; split++) {
			triangleWeight = tScore[start][split]
					+ tScore[split][end]
					+ values[start] * values[split] * values[end];

			tScore[start][end] = min(tScore[start][end], triangleWeight);
		}
	}}
	int minTScore_Polygon = tScore[0][n-1];

	return minTScore_Polygon;
}

int main() {
	vector<int> values = {1,3,1,4,1,5};

	return 0;
}
