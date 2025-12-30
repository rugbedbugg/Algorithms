#include <iostream>
#include <vector>
using namespace std;

///////////////////
/// Merge Logic ///
///////////////////
void merge(vector<int>& arr, int left, int mid, int right) {
    // ---------------------- //
    // Define sub-array sizes //
    // ---------------------- //
    int n1 = mid - left + 1;			// Left sub-array
    int n2 = right - mid;			// Right sub-array
    
    // ----------------------- //
    // Create temporary arrays //
    // ----------------------- //
    vector<int> L(n1);				// Left sub-array
    vector<int> R(n2);				// Right sub-array

    // -------------------- //
    // Populate temp arrays //
    // -------------------- //
    for (int i=0; i<n1; i++) {			// Left sub-array
	L[i] = arr[left+i];
    }
    for (int j=0; j<n2; j++) {			// Right sub-array
	R[j] = arr[mid+1+j];
    }

    // ----------------- //
    // Merge temp arrays //
    // ----------------- //
    int i=0;					// Initial index of left sub-array
    int j=0;					// Initial index of right sub-array
    int k=left;					// Initial index of merged sub-array
    
    while (i<n1 && j<n2) {
	if (L[i] <= R[j]) { arr[k++] = L[i++]; } 
	else 		  { arr[k++] = R[j++]; }
    }

    // ----------------------- //
    // Copy remaining elements //		// This process will occur only for one array
    // ----------------------- //
    while (i<n1) { arr[k++] = L[i++]; }		// Case 1: Left sub-array has elements remaining
    while (j<n2) { arr[k++] = R[j++]; }		// Case 2: Right sub-array has elements remaining
}

//////////////////
/// Propagator ///
//////////////////
void split(vector<int>& arr, int left, int right, int level, bool isLeft) {
    if (left >= right) return;

    // ----------------------------------------------- //
    // Display current level and subarray being sorted //
    // ----------------------------------------------- //
    cout << "Level " << level << ": Sorting ";

    if (level == 0)  	{ cout << "		[ "; } 
    else if (isLeft)	{ cout << "left half 	[ "; } 
    else 	 	{ cout << "right half 	[ "; }

    for (int i=left; i<=right; i++) {
	cout << arr[i] << " ";
    }
    cout << "]" << endl;



    int mid = left + (right - left)/2;
    
    // ------------------------ //
    // Create + Sort sub-arrays //		// Front Propagation
    // ------------------------ //
    split(arr, left, mid, level+1, true);	// Left sub-array
    split(arr, mid+1, right, level+1, false);	// Right sub-array

    // ---------------- //
    // Merge sub-arrays //			// Back Propagation
    // ---------------- //
    merge(arr, left, mid, right);
}

/////////////////
/// Initiator ///
/////////////////
void mergeSort(vector<int>& arr) {
    if (arr.size() <= 1) return;

    split(arr, 0, arr.size()-1, 0, true);	// Either true/false works during initiation
}

///////////////////
/// Driver Code ///
///////////////////
int main() {
    vector<int> array = {81,27,56,98,13, 47,26,3,95,78, 26,4,57,23,52, 8,10,23,96,47, 0};

    mergeSort(array);

    cout << endl << "Final sorted array 	[ ";
    for (int val: array) {
    	cout << val << " ";
    }
    cout << "]" << endl;

    return 0;
}
