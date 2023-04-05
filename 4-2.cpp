//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//============           Quick Sort             ==============//
//============   Time Complexity : O(nLog(n))   =============//
//===== Worst case: O(n^2) when array is already sorted =====//
//============   Space Complexity : O(log(n))    =============//

#include <iostream>
using namespace std;

// function to rearrange array (find the partition point)
int partition(int array[], int low, int high, int &comparisons, int &swaps) {
    
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (++comparisons && array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swaps++;
      swap(array[i], array[j]);
    }
  }
  
  // swap pivot with the greater element at i
  swaps++;
  swap(array[i + 1], array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high, int &comparisons, int &swaps) {
  if (low < high) {
      
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partition(array, low, high, comparisons, swaps);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1, comparisons, swaps);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high, comparisons, swaps);
  }
}


int main(){
    
    int T;
    cin>>T;

    while(T--){
        int n, temp;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int comparisons = 0, swaps =0;
        quickSort(arr, 0, n-1, comparisons, swaps);
        for(int index =0; index<n; index++){
            cout<<arr[index]<<" ";
        }
        cout<<endl;
        cout<<"comparisons = "<<comparisons<<endl;
        cout<<"swaps = "<<swaps<<endl;
    }
    return 0;
}

/*
OUTPUT
3
8
23 65 21 76 46 89 45 32
21 23 32 45 46 65 76 89 
comparisons = 14
swaps = 10
10
54 65 34 76 78 97 46 32 51 21
21 32 34 46 51 54 65 76 78 97
comparisons = 29
swaps = 21
15
63 42 223 645 652 31 324 22 553 12 54 65 86 46 325
12 22 31 42 46 54 63 65 86 223 324 325 553 645 652
comparisons = 45
swaps = 39
*/