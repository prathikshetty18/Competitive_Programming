#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(ll a, ll b, ll c){

    if((c + a) > 0 && (c + a) % (2*b) == 0) cout << "YES\n";
    else if((2*b - c) > 0 && (2*b - c) % a == 0) cout << "YES\n";
    else if((2*b - a) > 0 && (2*b - a) % c == 0) cout << "YES\n";
    else cout << "NO\n";

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll a, b, c;
        
        cin >> a >> b >> c;        

        solve(a, b, c);

        t--;
    }
}

