#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007

// #define DEBUG_F
 
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

struct Node{
    int x;
    Node *prev;
    Node *next;
};

Node ed;
Node *cur, *head;

Node *newNode(){
    Node *p = (Node*)malloc(sizeof(Node));
    return p;
}

void insert(int x){
#ifdef DEBUG_F
    printf("insert(%d)\n", x);
#endif

    Node *p;
    p = newNode();
    p->x = x;
    p->next = cur;
    p->prev = cur->prev;
    if(cur->prev==NULL){
        head = p;
    }else{
        cur->prev->next = p;
    }
    cur->prev = p;
    cur = p;
}

void move_(int d){
#ifdef DEBUG_F
    printf("move(%d)\n", d);
#endif

    if(d>0){
        rep(i, d) cur = cur->next;
    }else if(d<0){
        rep(i, -d) cur = cur->prev;
    }
}

void erase(){
#ifdef DEBUG_F
    printf("erase()\n");
#endif
    if(cur->prev==NULL){ //先頭にいる
        cur->next->prev = NULL;
        cur = cur->next;
        head = cur;
    }else{
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        cur = cur->next;
    }
}
 
int main()
{
    ed.next = NULL;
    ed.prev = NULL;
    ed.x = INT32_MAX;
    cur = &ed;
    head = &ed;

    int q;
    cin >> q;

    int com, d;
    rep(i, q){
        cin >> com;
        if(com == 0){
            cin >> d;
            insert(d);
        }else if(com==1){
            cin >> d;
            move_(d);
        }else if(com==2){
            erase();
        }
#ifdef DEBUG_F
        Node *tmp = head;
        while(tmp->next != NULL){
            if(tmp==cur) printf(">");
            print(tmp->x);
            tmp = tmp->next;
        }
#endif
    }
#ifdef DEBUG_F
    printf("\n");
#endif
    while(head->next != NULL){
        print(head->x);
        head = head->next;
    }
    return 0;
}