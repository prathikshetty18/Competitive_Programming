#include <bits/stdc++.h>
using namespace std;

void solve(int n){

    int digits = log10(n)+1;

    int ans = 0;

    int last_digit = n / pow(10, digits-1);

    ans += last_digit;

    ans += 9*(digits-1);

    cout << ans << "\n";

    return;
}

int main(){

    int t;
    cin >> t;

    while(t > 0){

        int n;

        cin >> n;

        solve(n);

        t--;
    }
}