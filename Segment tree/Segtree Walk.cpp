// Author : An Dương

void build()
{
    for(int id = N + 1; id <= (N<<1); ++id) ST[id] = 1;
    for(int id = N; id; --id) ST[id] = ST[(id<<1)] + ST[(id<<1)|1];
}

void kill(int pos)
{
    for(int id = pos; id; id >>= 1) --ST[id];
}

int cdbgv(int k) //kth alive
{
    for(int id = 1; id <= N;)
    {
        if(ST[(id<<1)] >= k) id <<= 1;
        else k -= ST[(id<<1)]; id = (id<<1)|1;
    }
    return id - N;
}
