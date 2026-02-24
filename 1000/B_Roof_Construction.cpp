#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(ll &n){

    int k = 0;
    while((1 << (k + 1)) <= n - 1) ++k; // HIGHEST SET BIT = SMALLEST POWER OF 2 MORE THAN N-1


    for(int i = (1 << k) - 1; i >= 0; i--) {
        cout << i << ' ';
    }

    for(int i = (1 << k); i < n; i++) {
        cout << i << ' ';
    }

    cout << '\n';
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

