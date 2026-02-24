#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<int> &v, int n){

    int minGCD = v[0] - 1;

    for(int i = 1; i < n; i++){

        int currDiff = abs(v[i] - (i + 1));     // because 1 indexing

        minGCD = gcd(minGCD, currDiff);
    }

    cout << minGCD << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int starttc = t;

    while(t > 0){

        int n;
        
        cin >> n;

        vector<int> v (n);

        for(int i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);

        t--;

        // if((starttc - t == 93) && t > 10){

        //     for(int i = 0; i < n; i++){

        //         cout << v[i] << " ";
        //     }

        //     cout << endl;
        // }


    }
}

