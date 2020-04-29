#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template <class T>
void print(T& x){printf("%d\n", x);}

struct Node{
    vector<int> edges_index; //エッジ先のインデックス
    vector<int> edges_cost; //エッジのコスト

    bool done;
    int min_cost;
};
 
void dijkstra(int size, Node nodes[], int start){
    nodes[start].min_cost = 0;

    Node *doneNode;
    int done_num;

    doneNode->min_cost = INT32_MAX;
    while(1){
        // doneされていないNodesの中から、doneできるnodeを見つける
        done_num = 0;
        REP(i, size){
            if(nodes[i].done || nodes[i].min_cost<0) continue;
            if(doneNode->min_cost < nodes[i].min_cost){
                doneNode = &nodes[i];
                done_num++;
            }
        }

        if(done_num==0) break;
        doneNode->done = true;
        // doneNodeからの伸びているエッジ先ノードのmin_cost更新
        FOR(i, 0, (doneNode->edges_index).size()) {
            Node to_node = nodes[doneNode->edges_index[i]];
            int new_cost = doneNode->min_cost + doneNode->edges_cost[i];
            if(to_node.min_cost < 0 || new_cost < to_node.min_cost){
                to_node.min_cost = new_cost;
            }
        }

    }
}