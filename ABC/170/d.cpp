#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define FOR(i,x,n) for(ll i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (1e9)
#define INFL (1e12)
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>using arr=vector<vector<T>>;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

map<ll, ll> minimum;
vector<int> a;
arr<ll> nums;

bool isprime(ll n){
if(!(n&1)) return false;
for(ll i=3; i*i < n; i+=2){
if(n%i==0) return false;
}
return true;
}

void make(ll n){
    ll nn = n;
    vector<ll> f;
    if(n%2==0){
        f.push_back(2);
        n /= 2;
        while(n!=1 && n%2==0){
            n /= 2;
        }
    }

    for(ll i=3; i*i <= n; i+=2){
        if(n%i==0){
            f.push_back(i);
            n /= i;
            while(n!=1 && n%i==0){
                n /= i;
            }
        }
    }

    if(n!=1) f.push_back(n);

    // pr(nn);
    // prvec(f);

    ll tmp=1;
    rep(i, f.size()) tmp *= f[i];
    if(minimum[tmp]==0) minimum[tmp] = nn;
    else{
        if(minimum[tmp] > nn) minimum[tmp] = nn;
    }

    nums.push_back(f);
}

#define MAX 1000010
int main(){
    int n; cin >>n;
    a.resize(n);
    rep(i, n){
        cin >> a[i];
    }

    sort(ALL(a));

    vector<bool> dp(MAX, false);
    rep(i, n){
        if(dp[a[i]]) continue;
        if(i<n-1 && a[i] == a[i+1]) dp[a[i]] = true;
        int k = a[i]*2;
        while(k < MAX){
            dp[k] = true;
            k += a[i];
        }
    }

    int cnt=0;
    rep(i, n){
        if(dp[a[i]]==false) cnt++;
    }
    pr(cnt);
}

// int main()
// {
//     ll n; cin >> n;
//     a.resize(n);
//     rep(i, n){
//         cin >> a[i];
//         make(a[i]);
//     }

//     // for(auto p: minimum){
//     //     prllf("%d %d\n", p.first, p.second);
//     // }

//     map<ll, ll> primes;
//     ll cnt = 0, t=0;
//     rep(i, n){
//         if(isprime(a[i])){
//             // prllf("a)\n");
//             primes[a[i]]++;
//             continue;
//         }

//         bool flag = true;
//         ll size = nums[i].size();

//         for(ll j=1; j < (1<<size); i++){
//             ll k = 1;
//             rep(c, size) {
//                 if(j & (1<<c)) k *= nums[i][c];
//             }
//             if(minimum[k]==0) continue;
//             if(minimum[k]==a[i]) continue;
//             if(a[i]%minimum[k] == 0){
//                 // prllf("%d %d !\n", a[i], minimum[k]);
//                 t++;
//                 flag = false;
//                 break;
//             }
//         }

//         if(flag) cnt++;
//     }

//     for(auto p: primes){
//         if(p.second!=1) t += p.second;
//     }

//     pr(n-t);
//     return 0;}