#include <bits/stdc++.h>
using namespace std;

#define ll long long


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, m;
        
        cin >> n >> m;

        ll xi, yi;

        ll peri = 4 * m;

        cin >> xi >> yi;    // ignore

        for(ll i = 0; i < n-1; i++){

            cin >> xi >> yi;

            peri += 2 * xi + 2 * yi;
        }

        cout << peri << endl;

        t--;
    }
}
