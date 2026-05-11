#include <bits/stdc++.h>
using namespace std;

#define N 10005

struct edge {
    int next, to, w;
} e[N];

int head[N];
int cnt = 0;

void add_edge(int u, int v, int w) {
    cnt ++;
    e[cnt].to = v, e[cnt].w = w;
    e[cnt].next = head[u], head[u] = cnt;
}

int n, m;
int u, v, w;

int main() {
    memset(head, 0, sizeof(int));
    scanf("%d%d", &n, &m)
    read(n), read(m);
    for (int i = 1; i <= m; i ++) {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
    }
    for (int i = 1; i <= n; i ++)
        if (head[i])
            for (int j = head[i]; j != 0; j = e[j].next)
                printf("%d %d %d\n", i, e[j].to, e[j].c);
        else printf("\n");
    return 0;
}