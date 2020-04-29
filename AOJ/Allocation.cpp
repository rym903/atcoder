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

bool isOK(vector<int> w, int n, int k, int limit){
    int tmp_sum, w_id=0;

    FOR(i, 0, k){
        tmp_sum=0;
        while(w_id < n && tmp_sum + w[w_id] <= limit){
            tmp_sum += w[w_id];
            w_id++;
        }

        if(w_id==n) return true;
    }

    return false;
}
 
int main()
{
    int n, k, t;
    ll w_sum=0;
    vector<int> w;
    cin >> n;
    cin >> k;

    REP(i, n){
        cin >> t;
        w.emplace_back(t);
        w_sum += t;
    }

    int left=0, right=w_sum, mid=(left + right)/2;
    int ans=w_sum;
    while(left<=right){
        // print(mid);
        if(isOK(w, n, k, mid)){
            ans = mid;
            right = mid-1;
        }else{
            left = mid+1;
        }
        mid = (left + right)/2;
    }

    print(ans);
}