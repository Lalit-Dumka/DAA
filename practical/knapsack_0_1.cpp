#include <iostream>
#include <vector>
using namespace std;

int knapsack(int wt[], int val[], int n, int k,  vector<int>& items) {
    int dp[n+1][k+1];
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < k+1; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (wt[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i-1]] + val[i-1]);
            }
        }
    }
    int maxVal = dp[n][k];
   
    return maxVal;
}

int main(){
    
    int T;
    cin>>T;

    while(T--){
        int n, k, temp;
        cin>>n;
        int wt[n], val[n];
        for (int i = 0; i < n; i++) {
            cin >> wt[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> val[i];
        }
        cin >> k;
        vector<int> items;
        cout << knapsack(wt, val, n, k , items) << endl;
    }
    
    return 0;
}

/*
1
5
2 3 3 4 6
1 2 5 9 4
10

*/