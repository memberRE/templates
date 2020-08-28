### HDU2243

求超过长度不超过n，且包含至少一个词根的单词总数

题解：$ans=S_n-T_n$

和病毒那题很像，但是却要求和
$$
\begin{bmatrix} A & E \\ 0 & E \end{bmatrix} \times \begin{bmatrix} T_n \\ A \end{bmatrix} = \begin{bmatrix} T_{n+1} \\ A \end{bmatrix}
$$
A为trie图的转移

##### 注：ac自动机在匹配的时候，总是是沿着trie图走的，fail数组只是在匹配后缀，实际上trie图也是由fail数组构造的

### HDU2825

求长度为n，包含至少k个模式串的字符串数量。

子集问题，状压dp

$$dp[i + 1][trie[j][x]][K | num[trie[j][x]]] += dp[i][j][K];$$

$$dp[i][j][k]$$表示当前走到了字符串的第i位，位于trie的第j个节点上，此时已经匹配的模式串是k（子集状压）





