#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int n){

    for(int i = 0; i < n; i++){

        cout << n - arr[i] + 1 << " ";
    }
    
    cout << endl;
}

int main(){

    int t;
    cin >> t;

    while(t > 0){

        int n;

        cin >> n;

        vector<int> arr(n);

        for(int i = 0; i < n; i++){

            cin >> arr[i];
        }

        solve(arr, n);

        t--;
    }
}