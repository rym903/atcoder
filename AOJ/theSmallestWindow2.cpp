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
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int main()
{
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    set<int> s;
    vector<int> num(k+1, 0);
    int left = 0, right=0, ans = INF;

    while(left < n && right <= n){
        while(s.size()<k){
            right++;
            if(right>n) break;
            if(a[right-1] <= k) {
                num[a[right-1]]++;
                s.insert(a[right-1]);
            }
        }
        
        if(left==0 && right==n+1 && s.size()<k){
            ans = 0;
            break;
        }
        if(s.size()<k) break;

        chmin(ans, right-left);
        // printf("left=%d right=%d, %d\n", left, right, ans);
        while(left<=right){
            left++;
            if(a[left-1] <= k){
                num[a[left-1]]--;
                if(num[a[left-1]]==0){
                    s.erase(a[left-1]);
                    break;
                }
            }
            chmin(ans, right-left);
        }
        // printf("left=%d right=%d, %d\n", left, right, ans);
    }
    pr(ans);
    return 0;}