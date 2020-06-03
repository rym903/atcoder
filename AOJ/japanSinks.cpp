#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
#define INF 1e9
#define INFL 1e12
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

struct island{
    int l, r, top, bottom;
};

vector<island> lands;
vector<int> a;
map<int, vector<int>> bmap;
int ans;

void makeislands(int l, int r, int depth){
    int top, bottom, right;
    for(int i=l; i<=r;){
        if(a[i]==depth) {
            i++;
            continue;
        }
        int left=i; top=a[i]; bottom=a[i];

        for(right=i+1; right<=r; right++){
            if(a[right]==depth){
                right--;
                break;
            }
            chmax(top, a[right]);
            chmin(bottom, a[right]);
        }
        if(right==r+1) right--;
        lands.push_back({left, right, top, bottom});
        ans++;
        bmap[bottom].push_back(lands.size()-1);
        i = right+1;
    }
    return;
}

int main()
{
    int n; cin >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];
    
    ans = 0;
    makeislands(0, n-1, 0);
    // for(auto land: lands){
    //     printf("(%d %d %d %d)", land.l, land.r, land.bottom, land.top);
    // }
    // cout << endl;
    // for(auto bm: bmap){
    //     printf("%d:", bm.first);
    //     rep(i, bm.second.size()){
    //         cout << bm.second[i] << " ";
    //     }
    //     printf("\n");
    // }

    int bottom;
    int max_ans = ans;
    for(auto b:bmap){
        bottom = b.first;
        printf("depth = %d\n", bottom);
        // int tmp = ans;
        rep(i, b.second.size()){
            ans--;
            island land = lands[b.second[i]];
            makeislands(land.l, land.r, bottom);
        }
        if(max_ans < ans) max_ans = ans;
        printf("%d\n", ans);
        int cnt=0;
        rep(i, lands.size()){
            island lll = lands[i];
            if(lands[i].bottom <= bottom) continue;
            printf("(%d: %d %d %d %d)", ++cnt, lll.l, lll.r, lll.bottom, lll.top);
        }
        printf("\n\n");
    }

    pr(max_ans);

    return 0;
}