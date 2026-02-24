#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<int> &v, int n){

    int maxi = INT_MIN;

    // every neighbouring pair could be bought to extremes

    int prev = v[n-1];

    int diff;

    for(int i = 0; i < n; i++){

        diff = prev - v[i];

        maxi = max(maxi, diff);

        prev = v[i];
    }

    // Left End Fixed and every other ele could be bought to the Right extreme

    prev = v[0];

    for(int i = 1; i < n; i++){

        diff = v[i] - prev;

        maxi = max(maxi, diff);
    }

    // Right End Fixed and every other ele could be bought to the Right extreme

    prev = v[n-1];

    for(int i = 0; i < n-1; i++){

        diff = prev - v[i];

        maxi = max(maxi, diff);
    }

    cout << maxi << "\n";

    // int ans = -1000000007;

	// for(int i = 0; i < N; ++i){
	// 	ans = max(ans, A[(i - 1 + N) % N] - A[i]);
	// }

	// for(int i = 1; i < N; ++i){
	// 	ans = max(ans, A[i] - A[0]);
	// }

	// for(int i = 0; i < N - 1; ++i){
	// 	ans = max(ans, A[N - 1] - A[i]);
	// }

	// cout << ans << '\n';

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        int n;
        
        cin >> n;

        vector<int> v (n);

        for(int i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);

        t--;
    }
}

