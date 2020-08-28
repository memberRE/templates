int waiter = 0; //等待人数
int comeid = 0, totid = 1;//当前已经上车的id和下一位乘客的id
int readytot = 0;//已经准备好的人数
semaphore mux = 1;  //对waiter访问的锁
semaphore come = 0; //巴士是否来了，0没来，1来了
semaphore ready = 0;//乘客是否已经上车

void bus()
{
    P(mux);
    if(waiter == 0)
    {
        depart();
        V(mux);
    }
    else
    {
        comeid += 50;
        V(come)
        V(mux)
        P(ready)
        depart();
    }   
}
void people()
{
    int id = totid++;
    while(true)
    {
        P(come)
        if(id <= comeid)
        {
            P(mux)
            waiter--;
            readytot++;
            boardBus();
            if(readytot == 50)
            {
                V(ready)
            }
            else
            {
                V(come)
            }
            V(mux)
        }
        else
            V(come)
    }
    
}