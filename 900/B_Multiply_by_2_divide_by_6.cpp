#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(ll n){

    int steps = 0;

    while(n % 6 == 0){

        n /= 6;
        steps++;
    }    

     while(n % 3 == 0){

        n /= 3;
        steps += 2;
    }    

    if(n == 1){

        cout << steps << endl;
    }
    else{

        cout << -1 << endl;
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

