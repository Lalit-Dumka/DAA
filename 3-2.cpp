//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//===============       Selection Sort       ===============//
//======  Time Complexity (worst, avg, best) : O(n^2)  =====//
//=====           Space Complexity : O(1)              =====//

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    int comparisons = 0, swaps = 0;
    for(int i = 0; i<n-1; i++){ // qki n-1 iteration k baad last elem jo bachega vo already largest hoga
        int min = i;
        for(int j= i+1; j<n ; j++){
            if(++comparisons && arr[min]>arr[j]){
                min = j;
            }
        }
        swaps++;
        swap(arr[i],arr[min]);
    }
    
    for(int index =0; index<n; index++){
        cout<<arr[index]<<" ";
    }
    cout<<endl;
    cout<<"comparisons = "<<comparisons<<endl;
    cout<<"swaps = "<<swaps<<endl;
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
OUTPUT
3
8
-13 65 -21 76 46 89 45 12
-21 -13 12 45 46 65 76 89
comparisons = 28
swaps = 7
10
54 65 34 76 78 97 46 32 51 21
21 32 34 46 51 54 65 76 78 97
comparisons = 45
swaps = 9
15
63 42 223 645 652 31 324 22 553 12 54 65 86 46 325
12 22 31 42 46 54 63 65 86 223 324 325 553 645 652
comparisons = 105
swaps = 14
*/