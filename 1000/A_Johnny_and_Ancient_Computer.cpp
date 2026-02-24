#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(ll &a, ll &b){

    ll bal; 

    bool flag = false;

    if(b > a) swap(a, b);


    if(a % b != 0) flag = true;

    bal = a/b;

    while(bal % 2 == 0){
        
        bal /= 2;
    }

    if(bal != 1) flag = true;

    if(flag){

        cout << -1 << nl;
        return;
    }


    bal = a/b;

    ll steps = 0;

    while(bal >= 8){

        bal /= 8;
        steps++;
    }


    while(bal >= 4){

        bal /= 4;
        steps++;
    }

    while(bal >= 2){

        bal /= 2;
        steps++;
    }

    cout << steps << nl;
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

