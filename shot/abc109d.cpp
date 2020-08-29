#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (2e9)
#define INFL (2e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
using vint=vector<int>;
using vll=vector<ll>;
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
    int h, w; cin >> h >> w;
    arr<int> a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    vint b;
    rep(i, h-1) rep(j, w){
        if(a[i][j]%2==1){
            b.push_back(i+1);
            b.push_back(j+1);
            b.push_back(i+2);
            b.push_back(j+1);
            a[i][j]--;
            a[i+1][j]++;
        }
    }

    rep(j, w-1){
        if(a[h-1][j]%2==1){
            b.push_back(h);
            b.push_back(j+1);
            b.push_back(h);
            b.push_back(j+2);
            a[h-1][j]--;
            a[h-1][j+1]++;
        }
    }

    cout << (int)b.size()/4 << endl;
    rep(i, (int)b.size()/4){
        cout << b[i*4] << " " << b[i*4 + 1] << " " << b[i*4 + 2] << " " << b[i*4 +3] << endl;
    }
    return 0;
}





// int dy[] = {-1, 1, 0, 0, 1, 1, -1, -1};
// int dx[] = {0, 0, -1, 1, 1, -1, 1, -1};

// using P = pair<int, int>;
// void prp(P& p) {cout << p.first << " " << p.second << endl;}

// int h, w;
// arr<int> G;
// vector<P> p;
// arr<bool> seen;
// int ans = 0;

// void search(int a, int b){
//     queue<P> que;
//     que.push({a, b});
//     // seen[a][b] = true;

//     while(!que.empty()){
//         int x, y;
//         tie(x, y) = que.front(); que.pop();
//         if(seen[x][y]) continue;
//         seen[x][y] = true;

//         bool flg = false;
//         rep(i, 4){
//             int nx = x + dx[i];
//             int ny = y + dy[i];
//             if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
//             if(seen[nx][ny]) continue;
            
//             if(G[nx][ny]%2==1){
//                 flg = true;
//                 seen[nx][ny] = true;
//                 p.push_back({a*w + b, nx*w + ny});
//                 break;
//             }
//             que.push({nx, ny});
//         }
//         if(flg) break;
//     }
// }

// int main()
// {
//     cin >> h >> w;
//     G.resize(h, vector<int>(w));
//     rep(i, h) rep(j, w) cin >> G[i][j];

//     seen.resize(h, vector<bool>(w, false));
//     rep(i, h) rep(j, w){
//         if(G[i][j]%2==0) continue;
//         if(seen[i][j]) continue;
//         search(i, j);
//     }

//     // rep(i, p.size()){
//     //     cout << p[i].first << " " << p[i].second << endl;
//     // }
//     rep(i, p.size()){
//         int a, b, x, y;
//         if(p[i].first > p[i].second) swap(p[i].first, p[i].second);
//         a = p[i].first / w;
//         b = p[i].first % w;
//         x = p[i].second / w;
//         y = p[i].second % w;

//         int kx =  x - a;
//         int ky =  y - b;
//         ans += abs(kx) + abs(ky);
//     }
    
//     cout << ans << endl;
//     rep(i, p.size()){
//         int a, b, x, y;
//         if(p[i].first > p[i].second) swap(p[i].first, p[i].second);
//         a = p[i].first / w;
//         b = p[i].first % w;
//         x = p[i].second / w;
//         y = p[i].second % w;

//         int kx =  x - a;
//         int ky =  y - b;
//         rep(j, kx){
//             int c = 1;
//             if(kx<0) c = -1;
//             cout << a+1 << " " << b+1 << " " << a+c+1 << " " << b+1 << endl;
//             a+=c;
//         }
//         rep(j, ky){
//             int c = 1;
//             if(ky<0) c = -1;
//             cout << a+1 << " " << b+1 << " " << a+1 << " " << b+c+1 << endl;
//             b+=c;
//         }
//     }
//     return 0;}