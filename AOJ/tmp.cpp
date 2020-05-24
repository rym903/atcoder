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
 
int main()
{
	vector<int> a = {146,54,3,4,5,7,2,4,6,6,7,9,27,64};
	int m = a.size() / 2;
	nth_element(a.begin(), a.begin()+m, a.end());

	printvec(a);

	return 0;
}