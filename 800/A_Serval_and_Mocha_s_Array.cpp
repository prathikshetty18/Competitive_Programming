#include <bits/stdc++.h>
using namespace std;

#define ll long long

int gcd(int a, int b){

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

void solve(vector<int> &v, int n){

    for(int i = 0; i < n; i++){

        for(int j = i+1; j < n; j++){

            if(gcd(v[i], v[j]) <= 2){

                // cout << "v[i]: " << v[i] << " v[j]: " << v[j] << " gcd: " << gcd(v[i], v[j]);

                cout << "Yes\n";
                return;
            }
        }
    }

    cout << "No\n";

}

int main(){

    int t;
    cin >> t;

    while(t > 0){

        int n;

        cin >> n;

        vector<int> v (n);

        for(int i = 0; i < n; i++){

            cin >> v[i];    
        }

        solve(v, n);

        t--;
    }
}

// if you find a pair whose gcd <= 2 => Array is beautifyl after you put this in front