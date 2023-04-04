//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//============ Check Duplicate using Sorting   ==============//
// using quick sort because it is given the array is unsorted and quick sort have T.C. nlog(n) for unsorted array
//============   Time Complexity : O(nLog(n))  =============//
//============   Space Complexity : O(n)       =============//

#include <iostream>
using namespace std;

// function to find the partition position
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<j)
            swap(arr[i],arr[j]);
    }
    swap(arr[j],arr[low]);
    return j;
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

bool checkDuplicates(int arr[], int n){
    quickSort(arr,0, n-1);  
    for(int i=1; i<n; i++){  // n*log(n) + n = n*log(n)
        if(arr[i]==arr[i-1]){
            cout<<"YES"<<endl;
            return true;
        }
    }
    cout<<"NO"<<endl;
    return false;
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
        checkDuplicates(arr,n);
    }
    return 0;
}

/*
OUTPUT
3
5
28 52 83 14 75
NO
10
75 65 1 65 2 6 86 2 75 8
YES
15
75 35 86 57 98 23 73 1 64 8 11 90 61 19 20
NO
*/