#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<int> &v, int n){

    // for every 1 (if n 0s)
    //     nC0 + nC1 + nC2 .. nCn (1 + 1)^n => 2^n * 1

    int ones = 0;
    int zeros = 0;

    for(int i = 0; i < n; i++){

        ones += 1 == v[i];
        zeros += 0 == v[i];
    }

    cout << (ll) pow(2, zeros) * ones << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        int n;
        
        cin >> n;

        vector<int> v (n);

        for(int i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);

        t--;
    }
}
