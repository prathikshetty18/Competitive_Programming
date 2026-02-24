#include <bits/stdc++.h>
using namespace std;

#define ll long long

int gcd(int a, int b){

    int count = 0;

    while(a >= 0 && b >= 0){

        if(a == 0) return b;
        else if(b == 0) return a;
        else if(a >= b){
            a = a % b;
        }
        else if(b > a){
            b = b % a;
        }
    }

    return 0;
}

void solve(){

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        

        solve();

        t--;
    }
}

