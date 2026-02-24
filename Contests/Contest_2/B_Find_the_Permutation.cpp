
#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> topoSort(int V, vector<vector<int>> &adj) {
    
    vector<int> res;
    vector<int> indegree (V,0);
    
    for(int i = 0; i < V; i++){
        
        for(auto it : adj[i]){
            
            indegree[it]++;
        }
    }
    
    queue<int> q;
    
    for(int i = 0; i < V; i++){
    
        if(indegree[i] == 0){
        
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int node = q.front();
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


void solve(vector<string> &mat, int n){

    vector<vector<int>> adj (n);
    
    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            if(mat[i][j] == '1' && j > i){

                adj[i].push_back(j);
            }
            else if(mat[i][j] == '0' && j > i){
                adj[j].push_back(i);
            }
        }
    }

    // for(int i = 0; i < n; i++){

    //     cout << i + 1 << ": ";

    //     for(auto e : adj[i]){

    //         cout << e + 1 << " ";
    //     }

    //     cout << endl;
    // }

    // cout << endl;

    vector<int> v = topoSort(n, adj);


    for(int i = 0; i < v.size(); i++){

        cout << v[i] + 1<< " ";
    }

    cout << endl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        int n;
        
        cin >> n;

        vector<string> mat (n);

        for(int i = 0; i < n; i++){

            cin >> mat[i];
        }

        solve(mat, n);

        t--;
    }
}


/*
void solve(vector<string> &mat, int n){
    
    unordered_map<int, int> mp;

    vector<int> v;

    for(int i = 0; i < n; i++){

        v.push_back(n-i);
        mp[n-i] = i+1;
    }

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= n; j++){

            if(i != j && mat[i-1][j-1] == '1'){

                if(j > i && mp[j] < mp[i]){

                    // cout << "1swapping: " << i << " and " << j << endl;

                    swap(v[mp[i]-1], v[mp[j]-1]);
                    int temp = mp[j];
                    mp[j] = mp[i];
                    mp[i] = temp;
                }
                else if(j < i && mp[j] > mp[i]){

                    // cout << "2swapping: " << i << " and " << j << endl;


                    swap(v[mp[i]-1], v[mp[j]-1]);
                    int temp = mp[j];
                    mp[j] = mp[i];
                    mp[i] = temp;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= n; j++){

            if(i != j && mat[i-1][j-1] == '0'){

                if(j > i && mp[j] > mp[i]){

                    // cout << "1swapping: " << i << " and " << j << endl;

                    swap(v[mp[i]-1], v[mp[j]-1]);
                    int temp = mp[j];
                    mp[j] = mp[i];
                    mp[i] = temp;
                }
                else if(j < i && mp[j] < mp[i]){

                    // cout << "2swapping: " << i << " and " << j << endl;


                    swap(v[mp[i]-1], v[mp[j]-1]);
                    int temp = mp[j];
                    mp[j] = mp[i];
                    mp[i] = temp;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){

        cout << v[i] << " ";
    }

    cout << endl;

}
*/