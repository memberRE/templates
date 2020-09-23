# bitset

## 原理

​	其每一位只占用1bit，相当于空间压缩，并且提供了一些方便的方法，因为用32位u_int进行空间压缩，所以各种操作的时间复杂度都除以了32，仅此而已。

##　方法

```cpp
#include<bitset>
// init
bitset<128> b;//即每个bitset占用128bit
bitset<128> b(u);//u为u_int型或者u_ll型，就是把u作为初值赋给b
bitset<128> b(s);//s 是string型，需要保证s的每个字符都是0或者1
//------------------
&|^
bit.size()       返回大小（位数）
bit.count()     返回1的个数
bit.any()       返回是否有1
bit.none()      返回是否没有1
bit.set()       全都变成1
bit.set(p)      将第p + 1位变成1（bitset是从第0位开始的！） 
bit.set(p, x)   将第p + 1位变成x
bit.reset()     全都变成0
bit.reset(p)    将第p + 1位变成0
bit.flip()      全都取反
bit.flip(p)     将第p + 1位取反
bit.to_ulong()  返回它转换为unsigned long的结果，如果超出范围则报错
bit.to_ullong() 返回它转换为unsigned long long的结果，如果超出范围则报错
bit.to_string() 返回它转换为string的结果
```

