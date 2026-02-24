#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(ll n){

    double a = log2(n);

    if(a == ceil(a)){

        cout << "NO\n";
    }
    else{

        cout << "YES\n";
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        
        cin >> n;

        solve(n);

        t--;
    }
}

