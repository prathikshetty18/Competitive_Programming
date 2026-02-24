#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define pb push_back
#define sz size
#define ff first
#define ss second
#define vll vector<ll>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

void solve(string &s, ll &n){

    ll l = 0, r = n-1;

    while(l < r && s[l] == s[r]){

        l++;
        r--;
    }

    if(l >= r){

        cout << 0 << nl;
        return;
    }

    ll opt1 = s[l];
    ll opt2 = s[r];

    ll mini = LLONG_MAX;

    ll count1 = 0, count2 = 0;

    ll linit = l, rinit = r;

    l++;
    count1++;

    while(l < r){

        // cout << "l: " << l << " r: " << r << nl;

        if(s[l] == s[r]){

            l++;
            r--;
        }
        else if(s[l] == opt1){

            l++;
            count1++;
        }
        else if(s[r] == opt1){

            count1++;
            r--;
        }
        else break;
    }
    
    
    // cout << "l: " << l << " r: " << r << " count1: " << count1 << nl;                               
    
    if(l >= r){
        
        mini = min(mini, count1);
    }


    l = linit;
    r = rinit;

    r--;
    count2++;

    while(l < r){

        // cout << "l: " << l << " r: " << r << nl;

        if(s[l] == s[r]){

            l++;
            r--;
        }
        else if(s[l] == opt2){

            l++;
            count2++;
        }
        else if(s[r] == opt2){

            count2++;
            r--;
        }
        else break;
    }
    
    
    // cout << "l: " << l << " r: " << r << " count1: " << count1 << nl;                               
    
    if(l >= r){
        
        mini = min(mini, count2);
    }

    if(mini == LLONG_MAX){

        cout << -1 << nl;
    }
    else{

        cout << mini << nl;
    }

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