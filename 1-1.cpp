//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//===== Linear Search =====//
//===== Time Complexity : O(n) ======//
//===== Space Complexity : O(1) =====//
// worst case: when last elem is the key //

#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> arr, int key){
    int comparisons = 0;
    for(int i = 0; i<arr.size(); i++){
        if(++comparisons && arr[i]==key){
            cout<<"Present "<<comparisons<<endl;
            return i;
        }
    }
    cout<<"Not Present "<<comparisons<<endl;
    return -1;
}

int main(){

    int n;
    cin>>n;

    while(n--){
        int size,temp,key;
        cin>>size;
        vector<int> arr;
        while(size--){
            cin>>temp;
            arr.push_back(temp);
        }
        cin>>key;
        linearSearch(arr,key);
    }
    
    // vector<int> arr = {1,2,3,4,5,6,7};
    // linearSearch(arr,5);
    
    return 0;
}