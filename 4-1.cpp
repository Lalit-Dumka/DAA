//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//===============       Merge Sort       ===============//
//======  Time Complexity (worst, avg, best) : O(n*log(n))  =====//
//=====           Space Complexity : O(n)              =====//

#include <iostream>
using namespace std;

// void merge(int arr[], int start, int mid, int end){
//     ...
// }

void mergeSort(int arr[], int start, int end, int &comparisons, int &inversions){
    if(start<end){
        // dividing the array using recursion
        int mid = start+(end-start)/2;
        mergeSort(arr,start, mid, comparisons, inversions);
        mergeSort(arr, mid+1, end, comparisons, inversions);

        // merge(arr, start, mid, end);
        // iske neeche ke code ko alag 'merge' func. m b daal skte h
        // camparison, inversions, arr, start, mid, end itne variables ka funcn bnanae se accha mene yhi pe krwa diya
        
        // creating 2 temporary arrays 1<-arr[start..mid] and 2<-arr[mid+1..end]
        int n1 = (mid-start)+1;
        int n2 = end-mid;
        int tempArr1[n1];
        int tempArr2[n2];
        for(int i=0; i<n1; i++){
            tempArr1[i]=arr[start+i];
        }
        for(int i=0; i<n1; i++){
            tempArr2[i]=arr[mid+1+i];
        }
        // comparing values of both temp arrays one by one and pushing the right one in our original array
        int i=0, j=0, k=start;
        while(i<n1 && j <n2){
            if(++comparisons && tempArr1[i]<tempArr2[j]){
                arr[k++]=tempArr1[i++];
            }
            else{
                arr[k++]= tempArr2[j++];
            }
        }
        // for remaining values
        while(i<n1){
            arr[k++]=tempArr1[i++];
        }
        while (j<n2){
            arr[k++]= tempArr2[j++];
        }
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
        int comparisons = 0, inversions = 0; //static se kaam ni ho rha tha isly funcn m paas krwa ra hu
        mergeSort(arr,0, n-1, comparisons, inversions);   
        for(int index =0; index<n; index++){
            cout<<arr[index]<<" ";
        }
        cout<<endl;
        cout<<"comparisons = "<<comparisons<<endl;
        cout<<"inversions = "<<inversions<<endl;
    }
    return 0;
}

/*
OUTPUT
3
8
23 65 21 76 46 89 45 32
21 23 32 45 46 65 76 89
comparisons = 16
inversions = 0
10
54 65 34 76 78 97 46 32 51 21
21 32 34 46 51 54 65 76 78 97
comparisons = 22
inversions = 0
15
63 42 223 645 652 31 324 22 553 12 54 65 86 46 325
12 22 31 42 46 54 63 65 86 223 324 325 553 645 652
comparisons = 43
inversions = 0
*/