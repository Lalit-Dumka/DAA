//jump search with jump value 2^k
//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// time complexity : because we are jumping 2^k and then searching linearly the time complexity is O(sqrt(n))
int jumpSearch(vector<int> arr, int key){
    int k=0;
    int jump = pow(2,k);
    while(jump<arr.size() && arr[jump]<key){
        k++;
        jump = pow(2,k);
    }
    int n=jump;
    while(n>= jump/2){
        if(arr[n]==key){
            return n;
        }
        n--;
    }
    return -1;
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
        cout<<jumpSearch(arr,key)<<endl; 
    }
    
    return 0;
}