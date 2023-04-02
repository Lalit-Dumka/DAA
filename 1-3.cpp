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
    int step = sqrt(arr.size());
    int prev = 0;
    while (++comparisons && arr[min(step, arr.size()) - 1] < key) {
      prev = step;
      step += sqrt(arr.size());
      if (prev >= arr.size()){
        cout<<"Not Present "<<comparisons<<endl;
        return -1;
      }
    }
    for (int i = prev; i < min(step, arr.size()); i++) {
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
2
5
12 23 36 39 41
41
Present 3
8
21 39 40 45 51 54 68 72
69
Not Present 4
*/