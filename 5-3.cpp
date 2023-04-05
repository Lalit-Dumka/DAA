//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//====== Common elems in 2 arrays ======//
//====== Time Complexity : O(m+n) =====//
//===== Space Complexity : O(1) =====//

#include <iostream>
#include <vector>
using namespace std;

vector<int> findCommon(int arr1[], int m, int arr2[], int n){
    vector<int> result;
    int i=0, j=0;
    while(i<m && j<n){
        if(arr1[i] == arr2[j]){
            result.push_back(arr1[i]);
            i++; 
            j++;
        }
        else if(arr1[i]<arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    if(result.size()!=0){
        for(int index=0; index<result.size(); index++){
            cout<<result[index]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"No Common Elements"<<endl;
    }
    
    return result;
}

int main(){
    
    int n,m;
    cin>>m;
    int arr1[m];
    for(int i=0; i<m; i++){
        cin>>arr1[i];
    }
    cin>>n;
    int arr2[n];
    for (int i = 0; i < n; i++){
        cin>>arr2[i];
    }
    findCommon(arr1,m,arr2,n);
    return 0;
}
/*
Output  (sheet m glt h input...sorted array hoga srf input)
7
10 10 34 39 55 76 85
12
10 10 11 30 30 34 34 51 55 69 72 89
10 10 34 55
*/