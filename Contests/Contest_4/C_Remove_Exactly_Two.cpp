#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(unordered_map<int, vector<int>> &mp, ll n){

    // for(auto it : mp){

    //     cout << it.first << ": ";

    //     for(int i = 0; i < it.second.size(); i++){

    //         cout << it.second[i] << " ";
    //     }

    //     cout << " size: " << it.second.size();

    //     cout << endl;
    // }

    int components = 1; // because tree

    int maxi = 0;
    int maxiKey;
    int miniiEdgeSum = 0;

    for(auto it : mp){

        if(it.second.size() > maxi){

            maxi = it.second.size();
            maxiKey = it.first;

            miniiEdgeSum = 0;

            for(int i = 0; i < it.second.size(); i++){

                miniiEdgeSum += mp[it.second[i]].size();
            }
        }
        else if(it.second.size() == maxi){

            int tempEdgeSum = 0;

            for(int i = 0; i < it.second.size(); i++){

                tempEdgeSum += mp[it.second[i]].size();
            }

            if(tempEdgeSum < miniiEdgeSum){

                miniiEdgeSum = tempEdgeSum;
                maxiKey = it.first;
            }
        }  
    }

    // cout << "maxiKey: " << maxiKey << endl;


    components = components + (maxi - 1);

    for(int i = 0; i < mp[maxiKey].size(); i++){

        int removeEdge = mp[maxiKey][i];

        auto pos = find(mp[removeEdge].begin(), mp[removeEdge].end(), maxiKey);

        // cout << "In " << removeEdge << " pos: " << pos << endl;

        if(pos != mp[removeEdge].end()){

            mp[removeEdge].erase(pos);
        }
    }

    mp.erase(maxiKey);

    maxi = 0;
    miniiEdgeSum = 0;

    for(auto it : mp){

        if(it.second.size() > maxi){

            maxi = it.second.size();
            maxiKey = it.first;

            miniiEdgeSum = 0;

            for(int i = 0; i < it.second.size(); i++){

                miniiEdgeSum += mp[it.second[i]].size();
            }
        }
        else if(it.second.size() == maxi){

            int tempEdgeSum = 0;

            for(int i = 0; i < it.second.size(); i++){

                tempEdgeSum += mp[it.second[i]].size();
            }

            if(tempEdgeSum < miniiEdgeSum){

                miniiEdgeSum = tempEdgeSum;
                maxiKey = it.first;
            }
        }  
    }

    components = components + (maxi - 1);

    cout << components << endl;


}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        
        cin >> n;

        unordered_map<int, vector<int>> mp;   // node : {connected nodes} whose size = edge count

        for(int i = 0; i < n-1; i++){

            int node, adjnode;

            cin >> node >> adjnode;

            mp[node].push_back(adjnode);
            mp[adjnode].push_back(node);
        }

        solve(mp, n);

        t--;
    }
}

