#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<int> &arr, int n){

    int ans = 0;

    for(int i = 0; i < n; i++){

        ans = ans ^ arr[i];
    }

    if(n % 2 == 0 && ans != 0){

        cout << -1 << endl;
        return;
    }

    cout << ans << endl;
}

int main(){

    int t;
    cin >> t;

    while(t > 0){

        int n;

        cin >> n;

        vector<int> arr (n);

        for(int i = 0; i < n; i++) cin >> arr[i];

        solve(arr, n);

        t--;
    }
}