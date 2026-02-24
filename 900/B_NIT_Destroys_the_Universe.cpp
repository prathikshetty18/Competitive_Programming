#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<int> &v, int n){

    int nonZeroFlag = 0;
    int start = -1;

    for(int i = 0; i < n; i++){

        if(v[i] != 0){
            
            nonZeroFlag = 1;
            start = i;
            break;
        }
    }

    if(nonZeroFlag == 0){

        cout << 0 << endl;
        return;
    }

    int seenZero = 0;

    for(int i = start;  i < n; i++){

        if(v[i] == 0) seenZero = 1;

        if(v[i] != 0 && seenZero == 1){

            cout << 2 << endl;
            return;
        }
    }

    cout << 1 << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        int n;
        
        cin >> n;

        vector<int> v (n);

        for(int i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);

        t--;
    }
}

