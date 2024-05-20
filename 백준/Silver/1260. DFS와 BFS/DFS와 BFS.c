#include <stdio.h>

#define MAX_SIZE_VERTEX 1002
int visited[MAX_SIZE_VERTEX];
typedef struct{
    int stack[20000];
    int top;
}StackType;
typedef struct{
    int queue[20000];
    int front , rear;
}QueueType;
typedef struct{
    int adj_mat[MAX_SIZE_VERTEX][MAX_SIZE_VERTEX];
    int n;
}GraphType;

void init_stack(StackType *s){
    s -> top = -1;
}
void push(StackType *s, int v){
    s -> stack[++s->top]=v;
}
int stack_empty(StackType *s){
    return s -> top == -1;
}
int pop(StackType *s){
    return s -> stack[s->top--];
}

void init_queue(QueueType *q){
    q -> front = q -> rear = -1;
}
int queue_empty(QueueType *q){
    return q -> rear == q -> front;
}
void enqueue(QueueType *q , int v){
    q -> queue[++q->rear] = v;
}
int dequeue(QueueType *q){
    return q -> queue[++q->front];
}

void insert_vertex(GraphType *g, int n){
    g -> n = n;
}
void init_graph(GraphType *g , int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            g->adj_mat[i][j]=0;
        }
    }
}
void insert_edge(GraphType *g , int v , int w){
    g->adj_mat[v][w] = 1;
    g->adj_mat[w][v] = 1;
}

void init_visited(int n){
    for(int i=0; i<n; i++){
        visited[i] = 0;
    }
}

void dfs(GraphType *g, int v){
    StackType s;
    init_stack(&s);
    push(&s,v);
    while(!stack_empty(&s)){
        v = pop(&s);
        if(!visited[v]){
            visited[v] = 1;
            printf("%d ",v+1);
            for(int w=g->n-1;w>=0;w--){
                if(!visited[w] && g->adj_mat[v][w]){
                    push(&s,w);
                }
            }
        }
    }
}
void bfs(GraphType *g, int v){
    QueueType q;
    init_queue(&q);
    enqueue(&q, v);
    while (!queue_empty(&q))
    {
        v = dequeue(&q);
        if(!visited[v]){
            visited[v] = 1;
            printf("%d ", v + 1);
            for (int w = 0; w < g->n; w++)
            {
                if (!visited[w] && g->adj_mat[v][w])
                {
                    enqueue(&q, w);
                }
            }
        }
    }
}

int main(){
    int N,M,V;
    int a,b;
    scanf("%d %d %d",&N,&M,&V);
    GraphType g;
    insert_vertex(&g,N);
    for(int i=0; i<M; i++){
        scanf("%d %d",&a,&b);
        insert_edge(&g,a-1,b-1);
    }
    init_visited(N);
    dfs(&g,V-1);
    printf("\n");
    init_visited(N);
    bfs(&g,V-1);
    return 0;
}