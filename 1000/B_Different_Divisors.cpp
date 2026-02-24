#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

bool is_prime(ll x){

    for(ll i = 2; i*i <= x; i++){

        if(x % i == 0) return false;
    }

    return true;
}


ll findNextPrime(ll x){

    while(!is_prime(x)){

        x++;
    }

    return x;
}

void solve(ll &d){

    ll p = findNextPrime(1+d);
    ll q = findNextPrime(p + d);

    cout << q*p << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll d;
        
        cin >> d;

        solve(d);

        t--;
    }
}

