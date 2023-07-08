#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

void findDistinctChars(char arr[], int n) {
    unordered_map<char, int> hashTable;
    for (int i = 0; i < n; i++) {
        hashTable[arr[i]]++;
    }
    vector<pair<char, int>> freqVec(hashTable.begin(), hashTable.end());
    sort(freqVec.begin(), freqVec.end());
    for (auto it = freqVec.begin(); it != freqVec.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int main() {
    int n;
    cin >> n;
    char arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    findDistinctChars(arr, n);
    return 0;
}