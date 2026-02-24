#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(string &s){

    if(s.size() == 1){

        cout << 1 << endl;
        return;
    }

    ll zeros = 0, ones =  0;

    for(int i = 0; i < s.size(); i++){

        zeros += s[i] == '0';
        ones += s[i] == '1';
    }

    ll ans = s.size();
    ll count = 0;

    if(ones <= zeros){

        ll mini = ones;

        for(int i = 0; i < s.size(); i++){

            if(s[i] == '0') count++;

            if(count == mini + 1){

                ans = i;    // index of (mini + 1)th zero which cannot be matched
                break;
            }
        }
    }
    else{

        ll mini = zeros;

        for(int i = 0; i < s.size(); i++){

            if(s[i] == '1') count++;

            if(count == mini + 1){

                ans = i;    // index of (mini + 1)th one which cannot be matched
                break;
            }
        }
    }

    cout << (ll)s.size() - ans << endl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        string s;
        
        cin >> s;

        solve(s);

        t--;
    }
}

