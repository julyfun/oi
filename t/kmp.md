`pre[i]` 表示 i 失配以后，最优匹配的位置

例如 ABCDABC
那么 pre[7] = 3

```cpp
// 求 pre[i]
int j = 0;
for (int i = 1; i <= len(t); i++) {
    i 和 j 试图同时右移匹配 (t[i + 1] == t[j + 1]?)
    如果失败，则 j = pre[j]，直到匹配上或者 j = 0 就退出
}
j = 0;
for (int i = 0; i <= len(s); i++) {
    i 和 j 试图同时右移匹配 (s[i + 1] == t[j + 1]?)
    如果失败，则 j = pre[j]，直到匹配上或者 j = 0 就退出
}
```

