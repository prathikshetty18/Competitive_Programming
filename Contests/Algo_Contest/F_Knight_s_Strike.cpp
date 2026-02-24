#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
void solve(ll a, ll b, ll xk, ll yk, ll xq, ll yq){
 
    set<pair<ll, ll>> s;
 
    vector<ll> dx  = {1, 1, -1, -1};
    vector<ll> dy = {1, -1, -1, 1};
 
    for(ll i = 0; i < 4; i++){
 
            ll newx1, newy1;
            ll newx2, newy2;
 
 
            newx1 = xk + dx[i] * a;
            newy1 = yk + dy[i] * b;
 
 
            newx2 = xk + dx[i] * b;
            newy2 = yk + dy[i] * a;

            s.insert({newx1, newy1});
            s.insert({newx2, newy2});
 
            // cout << "Polls: {" << newx1 << " , " << newy1 << " } \n";
            // cout << "Polls: {" << newx2 << " , " << newy2 << " } \n";
 
    }
 
    ll count = 0;
 
    for(ll i = 0; i < 4; i++){
 
        ll newx1, newy1;
        ll newx2, newy2;
 
 
        newx1 = xq + dx[i] * a;
        newy1 = yq + dy[i] * b;
 
 
        newx2 = xq + dx[i] * b;
        newy2 = yq + dy[i] * a;
 
        if(s.count({newx1, newy1})){
            count++;
            s.erase({newx1, newy1});
        }
        if(s.count({newx2, newy2})){
            count++;
            s.erase({newx2, newy2});
        }
    }
 
    cout << count << endl;
 
 
    // for(auto ele1 : mp){
 
    //     // cout << ele.first << " , " << ele.second[0] << endl;
 
    //     for(auto ele2 : mp[ele1.first]){
 
    //         cout << "{ " << ele1.first << " , " << ele2.first << " } : " << ele2.second << "\n";
    //     }
    // }
 
 
    // if(mp[1].find(-2) != mp[1].end())  cout << "FOUND!!\n";
 
 
}
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while(t > 0){
 
        ll a, b, xk, yk, xq, yq;
 
        cin >> a >> b >> xk >> yk >> xq >> yq;
 
        solve(a, b, xk, yk, xq, yq);
 
        t--;
    }
}
 