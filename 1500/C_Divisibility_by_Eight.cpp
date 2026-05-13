#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> 
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;    // find_by_order(x) -> Elements less than x, order_of_key(x) -> xth smallest element

#define ll long long
#define ld long double
#define sp " "
#define nl "\n"
#define pb push_back
#define sz size
#define ff first
#define ss second
#define vll vector<ll>
#define vvll vector<vll>
#define vvvll vector<vvll>
#define vpll vector<pair<ll, ll>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

set<string> all3DigitMultiplesOf8;
set<string> possibleLastDigit;
set<string> possibleLast2Digit;

void solve(string &s){

    for(ll i = 0; i < 1000/8; i++){

        string currMultiple = to_string(8*i);
    
        all3DigitMultiplesOf8.insert(currMultiple);
        possibleLastDigit.insert(string(1, currMultiple.back()));
       if(currMultiple.sz() >= 2) possibleLast2Digit.insert(currMultiple.substr(currMultiple.size() - 2));
    }

    ll n = s.sz();

    set<string> dpLastDigit;
    set<string> dpLast2Digit;

    for(ll i = n-1; i >= 0; i--){
    
        string curr(1, s[i]);
        
        for(auto ele : dpLast2Digit){

            string newCandidate = curr + ele;
            if(all3DigitMultiplesOf8.count(newCandidate)){

                cout << "YES" << nl << newCandidate << nl;
                return;
            }
        }


        for(auto ele : dpLastDigit){

            string newCandidate = curr + ele;
            if(all3DigitMultiplesOf8.count(newCandidate)){

                cout << "YES" << nl << newCandidate << nl;
                return;
            }
            else if(possibleLast2Digit.count(newCandidate) && !dpLast2Digit.count(newCandidate)){
                dpLast2Digit.insert(newCandidate);
            }
        }

        if(all3DigitMultiplesOf8.count(curr)){

            cout << "YES" << nl << curr << nl;
            return;
        }
        else if(possibleLastDigit.count(curr) && !dpLastDigit.count(curr)){
                dpLastDigit.insert(curr);
        }
    }


    cout << "NO" << nl;
    return ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        string s;

        cin >> s;

        solve(s);
    }
}

