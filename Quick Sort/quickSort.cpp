#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

////////////////////////////////////
/// Parition Scheme - Main logic ///
////////////////////////////////////
int partition(vector<int>& arr, int low, int high) {
    // ---------------------------- //
    // Intialize starting variables //
    // ---------------------------- //
    int pivot = arr[high];				// Random element set as the last element
    int i = low-1;

    // ---------------------------------------- //
    // Elements smaller than pivot on left side // 
    // ---------------------------------------- //
    for (int j=low; j<high; j++) {
	if (arr[j] <= pivot) {
	    swap(arr[++i], arr[j]);			// This is not sorting the array
	}						// segregating into higher & lower (than pivot)
    }
    // ------------------------------------------------ //
    // 0 ... i | i+1 (insert pivot here) | i+2 ... high //
    // ------------------------------------------------ //
    swap(arr[i+1], arr[high]);				// Put the pivot where it belongs by swapping it in
    return i+1;						// Correct pivot index 
}

/////////////////////////////////
/// Select random pivot index ///
/////////////////////////////////
int randomPivot(vector<int>& arr, int low, int high) {
    // -------------------------------------------- //
    // Select random pivot and swap to end of array //
    // -------------------------------------------- //
    int pivotIndex = low + rand() % (high-low+1);	// low + [0, high-low+1] = [low, high]
    swap(arr[pivotIndex], arr[high]);

    // ---------------------- //
    // Apply partition scheme //
    // ---------------------- //
    return partition(arr,low,high);			// Returns the correct index for pivot value
}

///////////////////
/// Propagation ///
/////////////////// 
void propagateQS(vector<int>& arr, int low, int high) {
    if (low < high) {
	int p = randomPivot(arr, low, high);

	propagateQS(arr, low, p-1);			// Left sub-array
	propagateQS(arr, p+1, high);			// Right sub-array
    }
}

//////////////////
/// Initiation ///
//////////////////
void quickSort(vector<int>& arr) {
    if (arr.size() <= 1) return;

    propagateQS(arr, 0, arr.size()-1);
}

int main() {
    vector<int> array = {1,79,2,35,6,98,34,32,98,42,54,35};

    // Seed for random number
    srand(time(NULL));

    quickSort(array);
    cout << "Sorted array: ";
    for (int el : array) {
	cout << el << " ";
    }
    cout << endl;

    return 0;
}
