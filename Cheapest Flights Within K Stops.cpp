class Solution {
public:
    int minCost=INT_MAX;
    int visited=0;
    void fun(int src,int dst,unordered_map<int,vector<pair<int,int>>> &graph,int k,int cost){
        if(src==dst){
            minCost=min(minCost,cost);
            visited=1;
            return;
        }
        if(cost>=minCost || k<0){
            return;
        }
            // for(int i=0;i<graph[src].size();i++){
            //     fun(graph[src][i].first,dst,graph,k-1,cost+graph[src][i].second);
        for(pair<int,int> p: graph[src])
            fun(p.first, dst, graph, k-1, cost+p.second);
            
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int,vector<pair<int,int>>>graph;
        for(int i=0;i<flights.size();i++){
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        int cost=0;
        fun(src,dst,graph,K,cost);
        if(!visited){
            return -1;
        }
        return minCost;
    }
};



//Alternative
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
    unordered_map<int, vector<pair<int,int>>> g;

    for (const auto& e : flights)

      g[e[0]].emplace_back(e[1], e[2]);

    

    int ans = INT_MAX;

    queue<pair<int,int>> q;

    q.push({src, 0});

    int steps = 0;

    

    while (!q.empty()) {

      int size = q.size();

      while (size--) {

        int curr = q.front().first;

        int cost = q.front().second;

        q.pop();

        if (curr == dst) 

          ans = min(ans, cost);

        for (const auto& p : g[curr]) {

          if (cost + p.second > ans) continue;

          q.push({p.first, cost + p.second});

        }

      }

      if (steps++ > K) break;

    }

    return ans == INT_MAX ? - 1 : ans;

  }
};
