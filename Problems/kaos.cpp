int A = 0, B = 0; //仓库中A与B的存量
semaphore mux = 1;//对A与B变量访问开关
semaphore isFull = 1;//是否满了 1没满，0满了 
semaphore AisEmpty = 0, BisEmpty = 0 //仓库里面是否有A和B，0代表没有，1代表有

int main()
{
    cobegin
    makerA();   //车间甲
    makerB();   //车间乙
    for (int i = 1; i <= 5;i++)
    {
        cliA();//需要A产品的客户
        cliB();//需要B的客户
    }
    coend
}

void makerA()
{
    while(true)
    {
        P(isFull);
        P(mux);
        A++;
        if(A == 1)
            V(AisEmpty)
        if(A+B < 50)
            V(isFull)
        P(mux)
    }
}
void makerB()
{
    while(true)
    {
        P(isFull);
        P(mux);
        B++;
        if(B == 1)
            V(BisEmpty)
        if(A+B < 50)
            V(isFull)
        P(mux)
    }
}
void cliA()
{
    while(true)
    {
        P(AisEmpty)
        P(mux);
        A--;
        if(A != 0)
            V(AisEmpty)
        if(A+B == 49)
            V(isFull)
        V(mux)
    }
}
void cliB()
{
    while(true)
    {
        P(BisEmpty)
        P(mux);
        B--;
        if(B != 0)
            V(BisEmpty)
        if(A+B == 49)
            V(isFull)
        V(mux)
    }
}