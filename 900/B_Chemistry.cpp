#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(string &s, int n, int k){

    unordered_map<char, int> mp;

    for(int i = 0; i < n; i++) mp[s[i]]++;

    int oddcount = 0;
    int evencount = 0;

    for(auto c : mp){

        if(c.second % 2 == 0) evencount++;
        else oddcount++;
    }

    if(n % 2 == 0 && k % 2 == 0){     // even chars will be left => Need to make all the oddcount into even counts for palindrome then after that we can remove pairwise

        if(k >= oddcount && (k - oddcount) % 2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    else if(n % 2 == 1 && k % 2 == 1){  // even chars will be left => Need to make all the oddcount into even counts for palindrome then after that we can remove pairwise

        if(k >= oddcount && (k - oddcount) % 2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    else if(n % 2 == 0 && k % 2 == 1){  // odd chars will be left => Need to make all the oddcount (except 1) into even counts for palindrome then after that we can remove pairwise

        if(k >= oddcount - 1 && (k - oddcount + 1) % 2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    else{  // (n % 2 == 0 && k % 2 == 1) odd chars will be left => Need to make all the oddcount (except 1) into even counts for palindrome then after that we can remove pairwise

        if(k >= oddcount - 1 && (k - oddcount + 1) % 2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        int n, k;
        
        cin >> n >> k;

        string s;

        cin >> s;
        
        solve(s, n, k);

        t--;
    }
}

