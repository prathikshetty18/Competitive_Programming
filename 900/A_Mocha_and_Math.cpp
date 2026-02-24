#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<int> &v, int n){

    int ans = v[0];

    for(int i = 1; i < n; i++){

        ans = ans & v[i];
    }

    cout << ans << endl;
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

