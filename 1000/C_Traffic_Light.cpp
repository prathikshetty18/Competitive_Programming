#include <bits/stdc++.h>
using namespace std;

#define ll long long


ll findNext(char c, ll i, ll &n, string &s){

    while(i < n && s[i] != c){

        i++;
    }

    return i;
}

void solve(string &s, ll &n, char &c){

    if(c == 'g'){

        cout << 0 << endl;
        return;
    }

    ll greenInd = findNext('g', 0, n, s);   // only modified if g comes before starting colour

    ll start = findNext(c, 0, n, s);
    ll end;

    ll maxi = 1;

    while(start < n){

        end = findNext('g', start + 1, n, s);

        // cout << "start: " << start << " end: " << end << endl;

        if(end < n) maxi = max(end - start, maxi);
        else maxi = max(end - start + greenInd, maxi);

        start = findNext(c, end + 1, n, s);

        // cout << "start: " << start << endl;
    }

    cout << maxi << endl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        char c;
        
        cin >> n >> c;

        string s;

        cin >> s;

        solve(s, n, c);

        t--;
    }
}

