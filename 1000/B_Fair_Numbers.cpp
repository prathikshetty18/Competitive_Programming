#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

bool is_fair(ll n){

    string num = to_string(n);
    int digits = num.size();

    for(int i = 0; i < digits; i++){

        char c = num[i];
        int d = c - '0';


        if(d != 0 && n % d != 0){

            return false;
        }
    }

    return true;
}

void solve(ll &n){

    ll super_fair = 2520;   // divisible by 1, 2, ... 9

    ll mod = n % super_fair;
    ll rem = 2520 - mod;

    for(int i = 0; i <= rem; i++){

        if(is_fair(n + i)){

            cout << n + i << nl;
            return;
        }
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

