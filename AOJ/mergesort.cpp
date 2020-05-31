#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
#define INF 1LL<<60
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void prt(T x){cout << x << endl;}
template<class T>void prtvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int cnt=0;
void merge(vector<int>& A, int left, int mid, int right){
    int n1=mid-left, n2=right-mid;
    vector<int> L(n1+1), R(n2+1);
    rep(i, n1) L[i] = A[left+i];
    rep(i, n2) R[i] = A[mid+i];
    L[n1]=INT32_MAX; R[n2]=INT32_MAX;
    int li=0, ri=0;
    FOR(i, left, right){
        cnt++;
        if(L[li] <= R[ri]){
            A[i] = L[li];
            li++;
        }else{
            A[i] = R[ri];
            ri++;
        }
    }
}
void mergeSort(vector<int>& A, int left, int right){
    if(left+1<right){
        int mid = (left+right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(){
    int n; cin>>n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    mergeSort(a, 0, a.size());

    prtvec(a);
    prt(cnt);
    return 0;
}