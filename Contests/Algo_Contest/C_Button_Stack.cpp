#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(ll &n, ll &m){

    if(m <= n && n % 2 == m % 2){

        cout << "Yes\n";
        return;
    }
    
    cout << "No\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, m;
        
        cin >> n >> m;

        solve(n, m);

        t--;
    }
}

