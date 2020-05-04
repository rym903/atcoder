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
    int x;
    Node *prev;
    Node *next;
};

Node *last_ = NULL;

Node *nodeloc(void){
    Node *node;
    node = (Node*)malloc(sizeof(Node));

    if(node == NULL){
        printf("allocate error\n");
        exit(0);
    }

    return node;
}

Node *insert(int x, Node *head, Node *last, int *len){
    Node *nd;
    nd = nodeloc();
    nd->x = x;
    if(head==NULL){
        head = nd;
        last_ = nd;
        head->next = NULL;
        last_->prev = NULL;
        last_->next = NULL;
    }else{
        nd->next = head;
        head->prev = nd;
        head = nd;
    }
    *len += 1;
    if(*len==2){
        last_->prev = head;
    }
    return head;
}

Node *del(int x, Node *head, Node *last, int *len){
    Node *nd = head;

    while(nd != NULL){

        if(nd->x == x){
            if(nd->next == NULL && nd->prev == NULL){
                last_ = NULL;
                head = NULL;
            }else if(nd->next == NULL){
                (nd->prev)->next = NULL;
                last_ = last_->prev;
            }else if(nd->prev == NULL){
                head = head->next;
                head->prev = NULL;
            }else{
                (nd->prev)->next = (nd->next);
                (nd->next)->prev = (nd->prev);
            }
            *len -= 1;
            break;
        }
        nd = nd->next;
    }
    return head;
}

Node *deleteFirst(Node *head, Node *last, int *len){
    // printf("1. head->next->x=%d\n", head->next->x);
    if(head->next == NULL){
        head = NULL;
        last_ = NULL;
        return head;
    }
    head = head->next;
    // printf("1. head->next->x=%d\n", head->next->x);
    head->prev = NULL;
    *len -= 1;
    // printf("2. head->next->x=%d\n", head->next->prev->x);
    return head;
}

Node *deleteLast(Node *head, Node *last, int *len){
    // Node *nd = head;
    if(last_->prev == NULL){
        last_ = NULL;
        head = NULL;
    }else{
        (last_->prev)->next = NULL;
        last_ = last_->prev;
    }
    return head;
}
 
int main()
{
    int n;
    scanf("%d", &n);

    Node *head=NULL, *last;
    char ope[15];
    int x;
    int len=0;
    FOR(i,0,n){
        scanf("%s", ope);
        // printf("%s\n", ope);
        Node *tmp = head;
        // while(tmp!=NULL){
        //     printf("%d ", tmp->x);
        //     tmp = tmp->next;
        // }
        // printf("\n");
        if(strcmp(ope, "insert")==0){
            scanf("%d", &x);
            // printf("%s %d\n", ope, x);
            head = insert(x, head, last, &len);
            
        }
        if(strcmp(ope, "delete")==0){
            scanf("%d", &x);
            // printf("%s %d\n", ope, x);
            head = del(x, head, last, &len);
        }
        if(strcmp(ope, "deleteFirst")==0){
            // printf("%s\n", ope);
            head = deleteFirst(head, last, &len);
            
        }
        if(strcmp(ope, "deleteLast")==0){
            // printf("%s\n", ope);
            head = deleteLast(head, last, &len);
        }

    }
    if(head!=NULL) {
        printf("%d", head->x);
        head = head->next;
    }
    while(head!=NULL){
        printf(" %d", head->x);
        head = head->next;
    }
    printf("\n");
    return 0;
}