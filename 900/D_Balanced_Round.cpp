#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<int> &v, int n, int k){

    sort(v.begin(), v.end());

    stack<int> st;

    st.push(v[0]);

    int maxStackSize = 1;

    for(int i = 1; i < n; i++){

        if(st.empty() || abs(st.top() - v[i]) <= k){

            st.push(v[i]);
            maxStackSize = max(maxStackSize, (int)st.size());
        }
        else{
            st.pop();
            i--;
        }
    }

    cout << n - maxStackSize << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        int n, k;
        
        cin >> n >> k;

        vector<int> v (n);

        for(int i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, k);

        t--;
    }
}

