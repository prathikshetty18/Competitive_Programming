#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> topoSort(ll V, vector<vector<ll>> &adj) {
    
    vector<ll> res;
    vector<ll> indegree (V,0);
    
    for(ll i = 0; i < V; i++){
        
        for(auto it : adj[i]){
            
            indegree[it]++;
        }
    }
    
    queue<ll> q;
    
    for(ll i = 0; i < V; i++){
    
        if(indegree[i] == 0){
        
            q.push(i);
        }
    }
    
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        res.push_back(node);
        
        for(auto it : adj[node]){
            indegree[it]--;
            
            if(indegree[it] == 0){
                q.push(it);
            }
        }
        
    }
    
    return res;
    
}

void solve( vector<vector<ll>> &mat, ll cows, ll cards){

    vector<vector<ll>> adj (cows);

    for(int i = 0; i < cows; i++){

        for(int j = i + 1; j < cows; j++){

            int firstgreater = 0, secondgreater = 0;

            for(int k = 0; k < cards; k++){

                if(mat[i][k] > mat[j][k]) firstgreater++;
                else secondgreater++;
            }

            if(firstgreater == cards) adj[j].push_back(i);
            else if(secondgreater == cards) adj[i].push_back(j);
            else{

                cout << -1 << endl;
                return;
            }
        }
    }

    vector<ll> order = topoSort(cows, adj);

      for(int i = 1; i < cards; i++){

        for(int j = 0; j < cows; j++){

            if(j == 0 && (mat[order[j]][i] < mat[order.back()][i-1])){     // first cow of this round

                cout << -1 << endl;
                return;
            }
            else if(j != 0 && (mat[order[j]][i] < mat[order[j-1]][i])){

                cout << -1 << endl;
                return;
            }
        }
    }

    if(order.size() == cows){

        for(int i = 0; i < order.size(); i++){

            cout << order[i] + 1 << " ";
        }

        cout << endl;
    }
    else{

        cout << -1 << endl;
        return;
    }
}

// void solve( vector<vector<ll>> &mat, ll cows, ll cards){

//     // for(int i = 0; i < cows; i++){

//     //     cout << "cow: " << i + 1 << " : ";

//     //     for(int j = 0; j < cards; j++){

//     //         cout << mat[i][j] + 1 << " ";
//     //     }

//     //     cout << endl;
//     // }

//     priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

//     for(int i = 0; i < cows; i++){

//         vector<int> temp (2);

//         temp[0] = mat[i][0];
//         temp[1] = i;
        
//         pq.push(temp);
//     }

//     vector<int> order;

//     while(!pq.empty()){

//         order.push_back(pq.top()[1]);
//         pq.pop();
//     }

//     for(int i = 1; i < cards; i++){

//         for(int j = 0; j < cows; j++){

//             if(j == 0 && (mat[order[j]][i] < mat[order.back()][i-1])){     // first cow of this round

//                 cout << -1 << endl;
//                 return;
//             }
//             else if(j != 0 && (mat[order[j]][i] < mat[order[j-1]][i])){

//                 cout << -1 << endl;
//                 return;
//             }
//         }
//     }

//     for(int i = 0; i < cows; i++){

//         cout << order[i] + 1 << " ";
//     }

//     cout << endl;

// }

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll cows, cards;
        
        cin >> cows >> cards;

        vector<vector<ll>> mat(cows, vector<ll>(cards));

        for(int i = 0; i < cows; i++){

            for(int j = 0; j < cards; j++){

                cin >> mat[i][j];
            }

            sort(mat[i].begin(), mat[i].end());
        }

        solve(mat, cows, cards);

        t--;
    }
}

