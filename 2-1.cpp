//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//====== Binary Search  (Iterative Method) ======//
//====== (if found then count the no. of keys to it's left and right) ======//
//====== Time Complexity : O(log(n)) =====//
//===== Space Complexity : O(1) =====//

#include <iostream>
#include <vector>
using namespace std;

int countKeys(vector<int> arr, int start, int end, int key){
    int  count =0;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(arr[mid]==key){
                count++;
                int l = mid-1, r = mid+1;
                while (l >= 0 && arr[l] == key) {
                    count++;
                    l--;
                }
                while (r < arr.size() && arr[r] == key) {
                    count++;
                    r++;
                }
            cout<<key<<" - "<<count<<endl;
            return count;
        }
        else if(arr[mid]>key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    cout<<"Key Not Present "<<endl;
    return 0;
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
        countKeys(arr,0,arr.size()-1,key);
    }
    
    return 0;
}