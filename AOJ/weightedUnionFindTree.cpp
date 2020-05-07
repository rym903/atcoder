#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template <class T>
void print(T& x){printf("%d\n", x);}
void printvec(vector<int> a){
    rep(i, a.size()-1){
        printf("%d ", a[i]);
    }
    printf("%d\n", a[a.size()-1]);
}

struct WUF{
    int p[100000];
    int w[100000];
    int r[100000];

    WUF(){
        rep(i, 100000){
            p[i] = i;
            w[0] = 0;
            r[0] = 0;
        }
    }

    int root(int x){
        if(p[x] == x){
            return x;
        }
        w[x] += w[p[x]];
        return root(p[x]);
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

	void unite(int x, int y, int c) {
        c = x + w[x] - w[y];
        x = root(x); y=root(y);
		
		if (x == y) return;
		if(r[x] < r[y]) swap(x, y); c-=c;
        if(r[x] == r[y]) r[x]++;
        p[y] = x;
        w[y] = c;
    }
};

WUF wuf;

int main(){
    int n, a;
    cin >>n >> a;

    int cmd, x, y, z, ans;
    rep(i, a){
        cin >> cmd >> x >> y;
        if(cmd==0){
            cin >> z;
            wuf.unite(x, y, z);
        }else if(cmd==1){
            if(wuf.same(x, y)){
                printf("%d\n", wuf.w[x] - wuf.w[y]);
            }else{
                printf("?\n");
            }
        }
    }
    return 0;
}

// int p[100000];
// vector<vector<int>> r(10000);
// int dist[100000][100000];

// void reset(bool *is_visit, int n){
//     rep(i, n) is_visit[i] = false;
// }

// int find(int x){
//     while(p[x]!=x){
//         x = p[x];
//     }
//     return x;
// }

// void relate(int x, int y, int z){
//     int x_id, y_id;
//     dist[x][y] = z;
//     dist[y][x] = -z;
//     r[x].emplace_back(y);
//     r[y].emplace_back(x);
//     x_id = find(x); y_id=find(y);

//     if(x_id > y_id) swap(x_id, y_id);
//     p[y_id] = x_id;
//     return;
// }
 
// void diff(int x, int y, int ans, bool *is_visit){
//     // printf("diff(%d, %d, %d)\n",x, y, ans);
//     if(x==y){
//         printf("%d\n", ans);
//     }

//     is_visit[x] = true;
//     for(auto it=r[x].begin(); it!=r[x].end();it++){
//         // printf("x=%d, *it=%d, dist=%d\n", x, *it, dist[x][*it]);
//         if(is_visit[*it]) continue;
//         diff(*it, y, ans+dist[x][*it], is_visit);
//     }
// }
 

// int main()
// {
//     int n, a;
//     cin >>n >> a;
//     rep(i, n){
//         rep(j, n){
//             dist[i][j]=0;
//         }
//     }
//     rep(i, n) p[i] = i;

//     int cmd, x, y, z, ans;
//     bool is_visit[n];
//     reset(is_visit, n);

//     rep(i, a){
//         scanf("%d", &cmd);
//         // printf("\ncmd = %d\n", cmd);
//         if(cmd==0){
//             scanf("%d %d %d", &x, &y, &z);
//             relate(x, y, z);
//             // printf("x=%d, y=%d, z=%d\n", x, y, z);
//             // printf("dist[%d][%d] = %d\n", x, y, dist[x][y]);
//             // printf("p[6] = %d\n", find(6));
//             // rep(j, r[6].size()) print(r[6][j]);
//             // printf("\n");
//         }else if(cmd==1){
//             scanf("%d %d", &x, &y);
//             if(find(x)==find(y)){
//                 diff(x, y, 0, is_visit);
//                 reset(is_visit, n);
//             }else{
//                 printf("?\n");
//             }
//             // printf("p = %d, %d", p[x], p[y]);
//         }
//     }

//     return 0;
// }