#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(string &s, int n){

    int l = 0;
    int r = n-1;

    while(l < r){

        if(s[l] != s[r]){

            l++;
            r--;
        }
        else{

            break;
        }
    }

    cout << r - l + 1 << endl;

}

int main(){

    int t;
    cin >> t;

    while(t > 0){

        int n;

        cin >> n;

        string s;

        cin >> s;

        solve(s, n);

        t--;
    }
}