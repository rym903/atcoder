#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template <class T>
void print(T& x){printf("%d\n", x);}

void insert(vector<int>& vec, int x){
    vec.emplace_back(x);
    return;
}

void splice(vector<int>& vec_s, vector<int>& vec_t){
    int tsize = vec_t.size();
    REP(i, vec_s.size()){
        vec_t.emplace_back(vec_s[i]);
    }
    vec_s.clear();
}
 
int main()
{
    int id, q, x, s, t;
    vector<vector<int>> lists(1000) ;
    cin >> id >> q;

    REP(i, q){
        scanf("%d", &id);
        if(id==0){ // lists[t] に xを挿入
            scanf("%d %d", &t, &x);
            // printf("list[%d]に%dを挿入\n", t, x);
            insert(lists[t], x);
        }else if(id==1){ // list[t]を全て表示
            scanf("%d", &t);
            // printf("lists[%d]を表示\n", t);
            if(lists[t].size() != 0){
                printf("%d", lists[t][0]);
                FOR(j, 1, lists[t].size()){
                    printf(" %d", lists[t][j]);
                }
            } 
            printf("\n");
        }else if(id==2){ // list[t]にlist[s]をくっつける。list[s]を空にする。
            scanf("%d %d", &s, &t);
            // printf("lists[%d]にlists[%d]をくっつける。\n", t, s);
            splice(lists[s], lists[t]);
        }
    }
    return 0;
}