#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(ll &n){

    if((n > 14) && (n % 14 <= 6) && (n % 14 > 0)){

        cout << "YES\n";
        return;
    }
    
    cout << "NO\n";
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

