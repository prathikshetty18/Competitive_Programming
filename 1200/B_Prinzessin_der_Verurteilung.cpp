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
#define vpll vector<pair<ll, ll>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

void solve(string &s, ll &n){

    string ans = "-1";

    for(ll i = 0; i < 26; i++){
    
        char ch = 'a' + i;

        if(s.find(ch) == string::npos){

            ans = ch;
            cout << ans << nl;
            return;
        }
    }

    for(ll i = 0; i < 26; i++){
    
        char ch1 = 'a' + i;

        for(ll j = 0; j < 26; j++){

            char ch2 = 'a' + j;

            string temp = {ch1, ch2};

            if(s.find(temp) == string::npos){

                ans = temp;
                cout << ans << nl;
                return;
            }
        }
    }

    for(ll i = 0; i < 26; i++){
    
        char ch1 = 'a' + i;

        for(ll j = 0; j < 26; j++){

            char ch2 = 'a' + j;

            for(ll k = 0; k < 26; k++){

                char ch3 = 'a' + k;

                string temp = {ch1, ch2, ch3};

                if(s.find(temp) == string::npos){
    
                    ans = temp;
                    cout << ans << nl;
                    return;
                }
            }

        }
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

