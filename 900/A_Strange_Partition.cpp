#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<int> &v, int n, int x){

    ll maxi = 0, mini = 0;

    for(int i = 0; i < n; i++){

        mini += v[i];

        maxi += ceil((double)v[i]/x);
    }

    mini = ceil((double)mini/x);

    cout << mini << " " << maxi << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        int n, x;
        
        cin >> n >> x;

        vector<int> v (n);

        for(int i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, x);

        t--;
    }
}

