#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(ll x0, ll n){

    if(n == 0){

        cout << x0 << endl;
        return;
    }

    ll curr = x0;

    if(curr % 2){   // starting at odd

        curr += 1;  // first step

        curr += 4 * ((n-1)/4);

        int rem = (n-1) % 4;

        for(int i = rem - 1; i >= 0; i--){

            if(curr % 2){

                curr += n-i;
            }
            else{

                curr -= n-i;
            }
        }

    }
    else{   // starting at even

        curr -= 1;  // first step

        curr -= 4 * ((n-1)/4);

        int rem = (n-1) % 4;

        for(int i = rem - 1; i >= 0; i--){

            if(curr % 2){

                curr += n-i;
            }
            else{

                curr -= n-i;
            }
        }
    }

    cout << curr << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll x0, n;
        
        cin >> x0 >> n;

        solve(x0, n);

        t--;
    }
}

