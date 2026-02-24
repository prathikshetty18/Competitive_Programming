#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(ll &n, ll &k, ll &b, ll &s){

    stack<ll> st;

    ll temp = min(k*(b+1) - 1, s);  // last num
    
    // cout << "temp: " << temp/k << endl;
    // cout << "   b: " << b << endl;
    // cout << "   temp/k != b: " << temp/k != b << endl;

    if(temp/k != b || (k == 1 && b != s)){

        cout << -1 << endl;
        return;
    }

    st.push(temp);

    ll rem = s - temp;
    ll reqEle = 0; 
    
    if(k > 1) reqEle = rem/(k-1);  // add k-1 as remaining ele to reach s while not changing b

    // cout << "rem: " << rem << endl;

    if(k > 1 && rem % (k-1) != 0){
        
        reqEle++;
    }

    if(reqEle + 1 > n){

        cout << -1 << endl;
        return;
    }

    if(k > 1 && rem % (k-1) != 0){
        
        reqEle--;
    }

    for(ll i = 1; i <= reqEle; i++){

        st.push(k-1);
    }

    if(k > 1 && rem % (k-1) != 0){
        
        st.push(rem % (k-1));
        reqEle++;
    }

    reqEle++;   // for last ele

    if(reqEle > n){

        cout << -1 << endl;
        return;
    }

    for(ll i = 1; i <= n - reqEle; i++){

        cout << 0 << " ";
    }

    while(!st.empty()){

        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, k, b, s;
        
        cin >> n >> k >> b >> s;

        solve(n, k, b, s);

        t--;
    }
}

