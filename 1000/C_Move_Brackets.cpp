#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(string &s, ll &n){

    int l = 0;
    int r = n-1;

    stack<char> st;

    for(ll i = l; i <= r; i++){

        if(!st.empty() && s[i] == ')' && st.top() == '(') st.pop();
        else {
            
            st.push(s[i]);
        }
    }

    ll ans = st.size()/2;

    cout << ans << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        
        cin >> n;

        string s;

        cin >> s;

        solve(s, n);

        t--;
    }
}

