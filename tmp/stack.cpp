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

int operate(string c, int x, int y){
    if (c=="+")
    {
        return x+y;
    }else if(c=="-"){
        return x-y;
    }else if(c=="*"){
        return x*y;
    }
}
 
int main()
{
    stack<int> stk;

    char c[10];
    int ic;
    string s;
    int x, y;

    while(cin >> c){
        s = c;
        if(!(s == "+" || s == "-" || s=="*")){
            ic = atoi(c);
            stk.push(ic);
        }else{
            y = stk.top();
            stk.pop();
            x = stk.top();
            stk.pop();
            stk.push(operate(s, x, y));
        }
    }

    print(stk.top());
    return 0;
}