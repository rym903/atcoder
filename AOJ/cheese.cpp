#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (1e9)
#define INFL (1e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>using arr=vector<vector<T>>;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

using P = pair<int, int>;
void prp(P& p) {cout << p.first << " " << p.second << endl;}
struct root{
    P p;
    int cnt;
};

int H, W, N;
vector<string> field;

P s;

int bfs(P& s,int g){
    queue<root> que;
    arr<bool> seen(H, vector<bool>(W, false));
    seen[s.first][s.second] = true;
    que.push({s, 0});
    bool flag = false;

    while(!que.empty()){
        root rt = que.front(); que.pop();
        P pos = rt.p;
        // prp(pos);
        rep(i, 4){
            int x = pos.first + dx[i];
            int y = pos.second + dy[i];
            if(x < 0 || x >= H || y < 0 || y >= W) continue;
            if(seen[x][y]) continue;
            seen[x][y] = true;

            if(field[x][y]=='X') continue;
            if('1' <= field[x][y] && field[x][y] <= '9'){
                if(field[x][y] - '0' == g){
                    flag = true;
                    s.first = x;
                    s.second = y;
                    return rt.cnt+1;
                }else{
                    que.push({{x, y}, rt.cnt+1});
                }
            }else que.push({{x, y}, rt.cnt+1});
        }
        if(flag) break;
    }
    return -1;
}

int main()
{
    cin >> H >> W >> N;
    rep(i, H) {
        string a; cin >> a;
        field.push_back(a);
        rep(j, W){
            if(a[j] == 'S') s = {i, j};
        }
    }
    int ans = 0;
    rep(i, N){
        ans += bfs(s, i+1);
        // pr(ans);
    }
    
    pr(ans);
    return 0;}