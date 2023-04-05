//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//====== Jump Search ======//
//====== Time Complexity : O(√n) =====//
//===== Space Complexity : O(1) =====//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int min(int a, int b){
    return a<b?a:b;
}

int jumpSearch(vector<int> arr, int key){
    int comparisons = 0;
    int step = 0;
    int prev = 0;
    int k=0;
    while (++comparisons && arr[min(step, arr.size()-1)] < key) {
      prev = step;
      k++;
      step = pow(2,k);
      if (prev >= arr.size()){
        cout<<"Not Present "<<comparisons<<endl;
        return -1;
      }
    }
    for (int i = prev; i <= min(step, arr.size()-1); i++) {
      if ( arr[i] == key){
        cout<<"Present "<<comparisons<<endl;
        return i;
      }
    }
    cout<<"Not Present "<<comparisons<<endl;
    return -1;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,key,temp;
        cin>>n;
        vector<int> arr;
        while(n--){
            cin>>temp;
            arr.push_back(temp);
        }
        cin>>key;
        jumpSearch(arr,key);
    }
    return 0;
}
/*
output
3
5
12 23 36 39 41
41
Present 3
8
21 39 40 45 51 54 68 72
69
Not Present 4
10
101 246 438 561 796 896 899 4644 7999 8545
7999
Present 4
*/