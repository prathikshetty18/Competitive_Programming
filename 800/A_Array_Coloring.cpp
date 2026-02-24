#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int n){

    int oddcount = 0;

    for(auto it : arr){

        if(it % 2 == 1) oddcount++;
    }

    if(oddcount % 2 == 0) cout << "YES\n";
    else cout << "NO\n";
}

int main(){

    int t;
    cin >> t;

    while(t > 0){

        int n;

        cin >> n;

        vector<int> arr;

        for(int i = 0; i < n; i++){

            int temp;

            cin >> temp;

            arr.push_back(temp);
        }

        solve(arr, n);

        t--;
    }
}