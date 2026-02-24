#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl endl

void solve(ll &n, ll &r, ll &b){

    ll maxi = r/(b+1);
    ll ex = r % (b+1);

    // cout << "n: " << n << " r: " << r << " b: " << b << " maxi: " << maxi << endl;

    ll temp;

    while(b > 0){

        temp = maxi;
        bool first = true;

        while(temp > 0){

            if(first && ex > 0){

                temp++;
                ex--;
            }

            first = false;

            cout << 'R';
            r--;
            temp--;
        }

        cout << 'B';
        b--;
    }

    while(r > 0){

        cout << 'R';
        r--;
    }

    cout << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, r, b;
        
        cin >> n >> r >> b;

        solve(n, r, b);

        t--;
    }
}

