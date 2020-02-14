#include<bits/stdc++.h>
using namespace std;

typedef  pair<int, int> pii; 
  
struct Graph 
{ 
    int V, E; 
    vector< pair<int, pii> > edgeDis; 
    Graph(int V) 
    { 
        this->V = V;  
    } 
    void addEdge(int u, int v, int w) 
    { 
        edgeDis.push_back({w,{u,v}}); 
    } 

    int kruskalMST();
}; 

/*Kruskal MST code referenced from gFg*/

struct DisjointSets 
{ 
    int *parent, *rnk; 
    int n; 
    DisjointSets(int n) 
    { 
        this->n = n; 
        parent = new int[n+1]; 
        rnk = new int[n+1]; 
  
        for (int i = 0; i <= n; i++) 
        { 
            rnk[i] = 0; 
            parent[i] = i; 
        } 
    }  
    int find(int u) 
    { 
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 
    void merge(int x, int y) 
    { 
        x = find(x), y = find(y); 
        if (rnk[x] > rnk[y]) 
            parent[y] = x; 
        else 
            parent[x] = y; 
  
        if (rnk[x] == rnk[y]) 
            rnk[y]++; 
    } 
}; 
  
 /* Functions returns weight of the MST*/ 
  
int Graph::kruskalMST() 
{ 
    int mst_wt = 0; 
    // Sort edgeDis in increasing order on basis of cost 
    sort(edgeDis.begin(), edgeDis.end()); 
    DisjointSets ds(V); 
  
    // Iterate through all sorted edgeDis 
    vector< pair<int, pii> >::iterator it; 
    for (it=edgeDis.begin(); it!=edgeDis.end(); it++) 
    { 
        int u = it->second.first; 
        int v = it->second.second; 
  
        int set_u = ds.find(u); 
        int set_v = ds.find(v); 
        /*check if cycle formed*/
        if (set_u != set_v) 
        { 
            mst_wt += it->first; 
            ds.merge(set_u, set_v); 
        } 
    } 
  
    return mst_wt; 
} 

int inOpenCheck(vector<pair<int,pii>> open,int v){
    for(auto it = open.begin(); it != open.end(); ++it){
        if((*it).second.second == v){
            return (*it).first;
        }
    }
    return -1;
}

void update(vector<pair<int,pii>> &open,int tc, int pc, int v){
    for(auto it = open.begin(); it != open.end(); ++it){
        if((*it).second.second == v){
            (*it).second.first = pc;
            (*it).first = tc;
            return;
        }
    }
}

int heurH1(int *adj[], int v, vector<int> remainEle){
    int mini = remainEle.size() > 1 ? INT_MAX : 0;
    for(auto it = remainEle.begin(); it != remainEle.end(); ++it){
        if(adj[v][*it] < mini && *it != v){
            mini = adj[v][*it];
        }
    }
    return mini;
}

int heurH2(int *adj[], int v, vector<int> remainEle){
    int mini = remainEle.size() > 1 ? INT_MAX : 0;
    for(auto it = remainEle.begin(); it != remainEle.end(); ++it){
        if(adj[0][*it] < mini && *it != v){
            mini = adj[0][*it];
        }
    }
    return mini;
}

int heurFunc(int v, int *adj[], vector<int> remainEle){
    int h1, h2, h3;
    h1 = heurH1(adj,v,remainEle);
    h2 = heurH2(adj,v,remainEle);

    Graph graph(remainEle.size()-1);
    int i = 0, j = 0;
    for(auto it = remainEle.begin(); it != remainEle.end(); ++it){
        if(*it != v){
            j = i+1;
            for(auto jt = it+1; jt != remainEle.end(); ++jt){
                if(*jt != v){
                    graph.addEdge(i,j,adj[*it][*jt]);
                    ++j;
                }
            }
            ++i;
        }
    }
    h3 = graph.kruskalMST();
    return h1+h2+h3; 
}

int AStar(int **adj, int V){
    vector<pair<int,pii>> open;
    vector<int> closed;
    vector<int> remainEle;
    for(int i = 0; i < V; ++i)
        remainEle.push_back(i);
    int hc = heurFunc(0,adj,remainEle);
    int pc = 0;
    int tc = hc + pc;
    int minCost = 0;
    open.push_back({tc,{pc,0}});
    while(!remainEle.empty()){
        auto mini = std::min_element(open.cbegin(), open.cend(), [](const auto& lhs, const auto& rhs) {
            return lhs.first < rhs.first; 
        });
        pair<int,pii> storePair = *mini;
        open.erase(mini);
        int ppc = storePair.second.first;
        int city = storePair.second.second;
        closed.push_back(city);
        remainEle.erase(find(remainEle.begin(),remainEle.end(),city));
        if(remainEle.empty()){
            minCost = ppc + adj[0][city];
        }
        for(auto it = remainEle.begin(); it != remainEle.end(); ++it){
            hc = heurFunc((*it),adj,remainEle);
            pc = ppc + adj[city][*it];
            tc = pc + hc;
            int existTCO = inOpenCheck(open,(*it));
            
            if(existTCO != -1){
                update(open,tc,pc,(*it));
            }
            else{
                open.push_back({tc,{pc,(*it)}});
            }
        }
        
    }
    return minCost;
}

int main(){
    int u, v, w, V, E;
    cout << "Num. of Vertices : ";
    cin >> V;
    int **adj;
    adj = new int *[V];
    for(int i = 0; i < V; i++)
        adj[i] = new int[V];
    cout << "Cost inMatrix Form : " << endl;
    for(int i = 0; i < V; ++i){
        for(int j = 0; j < V; ++j)
            cin >> adj[i][j];
    }
    int minCost = AStar(adj,V);
    cout << "OPT Cost: " << minCost << endl;
}