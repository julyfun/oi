区别在哪儿？堆部分是一样的，
堆优化 SPFA 还需要判断进队次数.
但是注意普通 SPFA 需要判断是否在队列中，而堆优化 SPFA 不可加这个判断，否则会 WA.
- e.g. https://www.luogu.com.cn/record/241262920

