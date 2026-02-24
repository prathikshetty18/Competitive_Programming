#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int n, int k){

    for(int i = 0; i < n; i++){

        if(arr[i] == k){

            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
    return;
}

int main(){

    int t;
    cin >> t;

    while(t > 0){

        int n, k;

        cin >> n >> k;

        vector<int> arr;

        for(int i = 0; i < n; i++){

            int temp;

            cin >> temp;

            arr.push_back(temp);
        }

        solve(arr, n, k);

        t--;
    }
}