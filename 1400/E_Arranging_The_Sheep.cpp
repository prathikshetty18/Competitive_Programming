#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"
#define pb push_back
#define sz size
#define ff first
#define ss second
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

void solve(string &s, ll &n){

    vpll pre (n+1);     // {cnt, sum}
    pre[0] = {0, 0};

    ll cnt = 0, sum = 0;

    for(ll i = 0; i < n; i++){
    
        if(s[i] == '*'){

            cnt++;
            sum += i+1;
        }

        pre[i+1] = {cnt, sum};
    }

    ll mini = LLONG_MAX;

    for(ll i = 0; i < n; i++){
    
        if(s[i] == '.') continue;

        // cout << "i : " << i+1 << nl;

        ll leftCnt = pre[i].ff - pre[0].ff;
        ll leftSum = pre[i].ss - pre[0].ss;
        ll rightCnt = pre[n].ff - pre[i+1].ff;
        ll rightSum = pre[n].ss - pre[i+1].ss;


        // cout << "leftSum: " << leftSum << sp << " leftCnt: " << leftCnt << nl;
        // cout << "rightSum: " << rightSum << sp << " rightCnt: " << rightCnt << nl;

        ll curr = 0;

        curr += leftCnt * (i+1) - leftSum - (leftCnt * (leftCnt + 1) / 2);
        curr += rightSum - rightCnt * (i+1) - (rightCnt * (rightCnt + 1) / 2);

        mini = min(mini, curr);
    }

    if(mini == LLONG_MAX) mini = 0;


    cout << mini << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        string s;
        cin >> s;

        solve(s, n);
    }
}

