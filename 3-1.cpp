//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//====== Insertion Sort  ======//
//====== Time Complexity (worst, avg) : O(n^2) =====//
//====== Time Complexity (best case when array is already sorted) : O(n) =====//
//===== Space Complexity : O(1) =====//

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    int comparisons = 0, shifts = 0;
    for(int i= 1; i<n; i++){
        int key=arr[i];
        int j=i-1;
        
        while(j>=0 && key<arr[j] && ++comparisons){
            shifts++;
            arr[j+1]=arr[j];
            j--;
        }
        shifts++;
        arr[j+1]=key;
    }
    for(int index =0; index<n; index++){
        cout<<arr[index]<<" ";
    }
    cout<<endl;
    cout<<"comparisons = "<<comparisons<<endl;
    cout<<"shifts = "<<shifts<<endl;
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
        insertionSort(arr, n);   
    }
    return 0;
}

/*
Output
3
8
-23 65 -31 76 46 89 45 32
comparisons = 13
shifts = 20
-31 -23 32 45 46 65 76 89
10
54 65 34 76 78 97 46 32 51 21
comparisons = 28
shifts = 37
21 32 34 46 51 54 65 76 78 97
15
63 42 223 645 652 31 324 22 553 -12 54 65 86 46 325
comparisons = 54
shifts = 68
-12 22 31 42 46 54 63 65 86 223 324 325 553 645 652
*/