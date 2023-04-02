//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//====== Binary Search (already sorted array) (Iterative Method) ======//
//====== Time Complexity : O(log(n)) =====//
//===== Space Complexity : O(1) =====//

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int start, int end, int key){
    int comparisons = 0;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(++comparisons && arr[mid]==key){
            cout<<"Present "<<comparisons<<endl;
            return mid;
        }
        else if(arr[mid]>key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    cout<<"Not Present "<<comparisons<<endl;
}

int main(){
    
    int n;
    cin>>n;

    while(n--){
        int size, temp, key;
        cin>>size;
        vector<int> arr;
        while(size--){
            cin>>temp;
            arr.push_back(temp);
        }
        cin>>key;
        binarySearch(arr,0,arr.size()-1,key);
    }

    // vector<int> arr = {1,2,3,4,5,6,7};
    // binarySearch(arr,0,arr.size()-1,1);    
    
    return 0;
}