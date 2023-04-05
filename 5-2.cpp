//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//====== Two Sum ======//
//====== Time Complexity : O(n*log(n)) =====//
//===== Space Complexity : O(log(n)) =====//

#include <iostream>
using namespace std;

int partition(int arr[], int start, int end){
    int pivot = arr[end];
    int i = start-1;
    for(int j = start; j< end; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
        swap(arr[i+1],arr[end]);
    }
    return (i+1);
}

void quickSort(int arr[], int start, int end){
    if(start<end){
        int pi = partition(arr, start, end);

        quickSort(arr, start, pi-1);
        quickSort(arr, pi+1, end);
    }
}

void findPair(int arr[], int n, int key){
    quickSort(arr, 0, n-1);
    int i=0, j=n-1;
    while(i<j){
        if(arr[i]+arr[j]==key){
            cout<<arr[i]<<" "<<arr[j]<<endl;
            return;
        }
        else if(arr[i]+arr[j]<key){
            i++;
        }
        else{
            j--;
        }
    }
    cout<<"No Such Element Exist"<<endl;
}

int main(){
    
    int T;
    cin>>T;

    while(T--){
        int n, key;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        cin>>key;
        findPair(arr, n, key);

    }
    
    return 0;
}