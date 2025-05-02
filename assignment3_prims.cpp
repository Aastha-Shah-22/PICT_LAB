#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution{

    public:
    void solution(vector<vector<pair<int, int>>>adj, int v){
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>>pq;
        vector<int>visited(v, false);
        pq.push(make_pair(0,0));
        int sum = 0;

        while(!pq.empty()){
            auto ele = pq.top();
            pq.pop();
            if(visited[ele.second]){continue;}
            visited[ele.second] = true;
            cout<<ele.second<<"->";
            sum += ele.first;
            for(auto node : adj[ele.second]){
                pq.push(make_pair(node.second, node.first));
            }
        }

        cout<<"\nCost of MST: "<<sum<<endl;
    }
        
};

int main(){

    vector<vector<int>>graph;
    unordered_set<int>vertex;
    int src;
    int dest;
    int wt;
    while(true){
        vector<int>temp;
        cout<<"Enter src: ";
        cin>>src;

        cout<<"Enter dest: ";
        cin>>dest;

        cout<<"Enter wt: ";
        cin>>wt;

        if(src == -1 || dest == -1 || wt == -1){
            break;
        }

        temp.push_back(src);
        temp.push_back(dest);
        temp.push_back(wt);
        vertex.insert(src);
        vertex.insert(dest);
        graph.push_back(temp);
    }

    //create adj list;
    int n = vertex.size();
    vector<vector<pair<int,int>>>adj(n);
    for(auto node : graph){
        adj[node[0]].push_back(make_pair(node[1], node[2]));
        adj[node[1]].push_back(make_pair(node[0], node[2]));
    }
    cout<<"MST using Prims Algorithm: ";
    Solution s;
    s.solution(adj, n);

}