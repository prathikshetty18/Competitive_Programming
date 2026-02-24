#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(ll a, ll b){

    if(a == b){

        cout << 0 << " " << 0 << endl;
        return;
    }

    ll curr_gcd = gcd(a, b);

    ll diff = abs(a - b);

    if(curr_gcd > diff){

        cout << curr_gcd << " " << 0 << endl;
    }
    else{

        cout << diff << " ";

        ll rem = a % diff;

        cout << min(rem, diff - rem) << endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll a, b;
        
        cin >> a >> b;

        solve(a, b);

        t--;
    }
}

