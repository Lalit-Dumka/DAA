// find i,j such that arr[i]+arr[j] = arr[k]
// //~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// time complexity of this approach is O(n^2)
vector<int> findTriplets(vector<int> arr){
    vector<int> sol;
    //using 2 pointer approach to find the pair of numbers that sum to arr[k] in O(n) time complexity 
    for(int k = 0; k<arr.size(); k++){
        int i = 0;
        int j = arr.size()-1;
        while(i<j){
            if(arr[i]+arr[j]==arr[k]){
                sol.push_back(i);
                sol.push_back(j);
                sol.push_back(k);
                return sol;
            }
            else if(arr[i]+arr[j]<arr[k]){
                i++;
            }
            else{
                j--;
            }
        }
    }
    sol.push_back(-1);
    sol.push_back(-1);
    sol.push_back(-1);
    return sol;

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
        vector<int> sol = findTriplets(arr);
        cout<<sol[0]<<" "<<sol[1]<<" "<<sol[2]<<endl; 
    }
    
    return 0;
}
/*
3
5
1 5 84 209 341
10
24 28 48 71 86 89 92 120 194 201
15
64 69 82 95 99 107 113 141 171 350 369 400 511 590 666

*/