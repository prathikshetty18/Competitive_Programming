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

void solve(set<ll> &stt){

    vll ans;

    ll p12, p23, p45, p56;

    cout << '?' << sp << 1 << sp << 2 << endl;

    cin >> p12;

    cout << '?' << sp << 2 << sp << 3 << endl;

    cin >> p23;

    cout << '?' << sp << 4 << sp << 5 << endl;

    cin >> p45;

    cout << '?' << sp << 5 << sp << 6 << endl;

    cin >> p56;

    for(auto ele : stt){

        if(p12 % ele == 0 && p23 % ele == 0){

            ll num1 = p12/ele;
            ll num2 = p23/ele;

            if(num1 != ele && num2 != ele && stt.count(num1) && stt.count(num2)){

                ans.pb(num1);
                ans.pb(ele);
                ans.pb(num2);

                stt.erase(num1);
                stt.erase(ele);
                stt.erase(num2);
                break;
            }
        }
    }


    for(auto ele : stt){

        if(p45 % ele == 0 && p56 % ele == 0){

            ll num1 = p45/ele;
            ll num2 = p56/ele;

            if(num1 != ele && num2 != ele && stt.count(num1) && stt.count(num2)){

                ans.pb(num1);
                ans.pb(ele);
                ans.pb(num2);

                stt.erase(num1);
                stt.erase(ele);
                stt.erase(num2);
                break;
            }
        }
    }

    cout << '!' << sp << flush;

    print(ans);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        set<ll> stt = {4, 8, 16, 42, 15, 23};

        solve(stt);
    }
}

