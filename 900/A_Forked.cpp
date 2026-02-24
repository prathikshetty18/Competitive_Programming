#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(int a, int b, int xk, int yk, int xq, int yq){

    unordered_map<int, unordered_map<int, int>> mp;

    vector<int> dx  = {1, 1, -1, -1};
    vector<int> dy = {1, -1, -1, 1};

    for(int i = 0; i < 4; i++){

            int newx1, newy1;
            int newx2, newy2;


            newx1 = xk + dx[i] * a;
            newy1 = yk + dy[i] * b;


            newx2 = xk + dx[i] * b;
            newy2 = yk + dy[i] * a;

            mp[newx1][newy1]++;
            mp[newx2][newy2]++;

            // cout << "Points: {" << newx1 << " , " << newy1 << " } \n";
            // cout << "Points: {" << newx2 << " , " << newy2 << " } \n";

    }

    int count = 0;

    for(int i = 0; i < 4; i++){

        int newx1, newy1;
        int newx2, newy2;


        newx1 = xq + dx[i] * a;
        newy1 = yq + dy[i] * b;


        newx2 = xq + dx[i] * b;
        newy2 = yq + dy[i] * a;

        if(mp[newx1][newy1]){
            count++;
            mp[newx1].erase(newy1);
        }
        if(mp[newx2][newy2]){
            count++;
            mp[newx2].erase(newy2);
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

    int t;
    cin >> t;

    while(t > 0){

        int a, b, xk, yk, xq, yq;

        cin >> a >> b >> xk >> yk >> xq >> yq;

        solve(a, b, xk, yk, xq, yq);

        t--;
    }
}

