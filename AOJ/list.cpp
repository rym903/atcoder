#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template <class T>
void print(T& x){printf("%d\n", x);}

struct Node{
    int num;
    Node *next;
    Node *prev;
};
 
Node *nodeloc(void){
    Node *node;
    node = (Node*)malloc(sizeof(Node));

    if(node == NULL){
        printf("allocate error\n");
        exit(0);
    }

    return node;
}

Node *sethead(Node *head, int x){
    Node *p = nodeloc();
    p->num = x;

    p->next=NULL; p->prev=NULL;
    head = p;

    return head;
}

Node *insert(Node *head, Node *cursor, int x){
    Node *p = nodeloc();
    p->num = x;
    if(cursor==NULL){
        p->next = NULL; p->prev=cursor->prev;
        cursor = p;
    }else{
        p->next = cursor; p->prev=cursor->prev;
        if(cursor->prev != NULL){
            cursor->prev->next = p;
        }
        cursor->prev = p;
        cursor = p;
    }
    return cursor;
}

Node *move(Node *head, Node *cursor, int x){
    int d=abs(x);
    if(x>0){
        REP(i, d) cursor = cursor->next;
    }else if(x<0){
        REP(i, d) cursor = cursor->prev;
    }

    return cursor;
}

Node *erase(Node *head, Node *cursor){
    // printf("%d %d\n", cursor->prev->next->num, cursor->next->num);
    cursor->prev->next = cursor->next;
    // printf("done\n");
    if(cursor->next != NULL){
        cursor->next->prev = cursor->prev;
    }
    // printf("done\n");
    cursor = cursor->next;
    // printf("done\n");
    return cursor;
}


int main()
{
    int q;
    cin >> q;
    Node *head=NULL;
    Node *cursor=NULL;

    int s, t;
    REP(i, q){
        Node *tmp = head;
        while(tmp!=NULL){
            if(tmp==cursor) printf("o");
            printf("%d ", tmp->num);
            tmp = tmp->next;
        }
        printf("\n");
        scanf("%d", &s);
        if(s==0){
            scanf("%d", &t);
            printf("%dを挿入\n", t);
            if(head==NULL){
                head = sethead(head, t);
                cursor = head;
            }else{
                cursor = insert(head, cursor, t);
                if(head==cursor->next){
                    head = cursor;
                }
            }
        }else if(s==1){
            scanf("%d", &t);
            printf("%d移動\n", t);
            cursor = move(head, cursor, t);
        }else if(s==2){
            printf("削除\n");
            cursor = erase(head, cursor);
            
            if(head->next == NULL){
                head = NULL;
            }
        }
    }

    while(head!=NULL){
        printf("%d ", head->num);
        head = head->next;
    }
    return 0;
}