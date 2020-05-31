#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void print(T x){cout << x << endl;}
template<class T>void printvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int main()
{
    string t, p;
    cin >> t >> p;

    vector<int> csum;
    csum.push_back(1); csum.push_back(1);
    {
        int k=1;
        FOR(i, 1, p.length()){
            if(p[i]==p[i-1]) csum[k]++;
            else {csum.push_back(csum[k]+1); k++;}
        }
    }
    // printvec(csum);


    vector<int> ans;
    int l;

    for(int i=0; i<=t.length()-p.length();){
        l=0;
        print(i);
        while(l<p.length() && t[i+l]==p[l]) l++;
        if(l==p.length()) {
            ans.push_back(i);
            
        }
    }
    printvec(ans);
    return 0;
}