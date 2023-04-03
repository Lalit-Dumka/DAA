//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//====== Brute Force  ======//
//====== Time Complexity : O(n^2) =====//
//===== Space Complexity : O(1) =====//

#include <iostream>
#include <vector>
using namespace std;

int twoDifference(vector<int> arr, int key){
    int pairCount = 0;
    for(int i = 0; i< arr.size(); i++){
        for(int j = i+1; j< arr.size(); j++){
            if(arr[i]-arr[j]==key || arr[i]- arr[j]==(-1*key)){
                pairCount++;
            }
        }
    }
    return pairCount;
}

int main(){
    
    int T;
    cin>>T;

    while(T--){
        int n, temp, key;
        cin>>n;
        vector<int> arr;
        while(n--){
            cin>>temp;
            arr.push_back(temp);
        }
        cin>>key;
        cout<<twoDifference(arr,key)<<endl; 
    }
    
    return 0;
}