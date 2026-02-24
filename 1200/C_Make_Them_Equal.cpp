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

void solve(string &s, ll &n, char &c){

    int flag =0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] != c)
        {
            flag =1;
            break;
        }
    }

    if(flag == 0)
    {
        cout<<0<<endl;
        return;
    }


    for(int i = n-1; i > n/2 - 1;i--)
    {
        if(s[i] == c)
        {
            cout<<1<<endl;
            cout<<i+1<<endl;
            return;
        }
    }

    cout<<2<<endl;
    cout<<n<<" "<<n-1<<endl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        char c;
        
        cin >> n >> c;

        string s;

        cin >> s; 

        solve(s, n, c);
    }
}

