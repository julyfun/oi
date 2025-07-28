Tarjan 缩点: `dfn[u] == low[u]` 区域的根.
- 注意反向边需要在栈上才更新 low.

无向图割点: 不用判是否走会父亲.
- 非根: 存在 v 使得 `dfn[u] <= low[v]`
- 根: 儿子数量 >= 2

无向图割边: `dfn[u] < low[v]`

点双: 无割点

边双: 无割边

伪代码
```py
tarjan(u)
    dfn[u] = ++cnt
    low[u] = dfn[u]
    u 入栈
    in[u] = True # 是否在 tarjan 栈上
    for v in 邻接点(u):
        if dfn[v] == 0:
            tarjan(v)
            low[u] = min(low[u], low[v])
        elif in[v]:
            # 如果不在栈上
            low[u] = min(low[u], dfn[v])
    if dfn[u] == low[u]: # 找到一个强连通分量
        弹出栈顶直到 u

for 所有点 u:
    if dfn[u] == 0: # 没访问过
        tarjan(u)
```

