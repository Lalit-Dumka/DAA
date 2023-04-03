//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//====== har elem k liye dhudne ka try krenge triplets;
// sorted array h isly us element se peeche wale elements m hi dhudenge ======//
//====== Time Complexity : O(n^2) =====//
//===== Space Complexity : O(1) =====//

#include <iostream>
#include <vector>
using namespace std;

void findTriplet(vector<int> arr){
    for(int i=2; i< arr.size(); i++){
        int start = 0, end = i-1;
        while(start<end){
            if(arr[start]+arr[end]==arr[i]){
                cout<<start+1<<", "<<end+1<<", "<<i+1<<endl; //assignment sheet m esa hi tha :/
                return;
            }
            else if(arr[start]+arr[end]<arr[i]){
                start++;
            }
            else{
                end--;
            }
        }
    }
    cout<<"No sequence found."<<endl;
}

int main(){
    
    int T;
    cin>>T;

    while(T--){
        int n, temp;
        cin>>n;
        vector<int> arr;
        while(n--){
            cin>>temp;
            arr.push_back(temp);
        }
        findTriplet(arr);
    }
    
    return 0;
}