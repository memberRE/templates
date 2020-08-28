#include <stdio.h>
#include <memory.h>
 
#define MAXN 100000
 
char s[MAXN+1], t[MAXN+1];
char *ps, *pt;
 
int main(void)
{
    char look;
    int say, i;
 
    memset(s, 0, sizeof(s));
    memset(t, 0, sizeof(t));
 
    s[0] = '1';
    for(i=0; i<18; i++) {
        if(i & 1) {
            ps = t;
            pt = s;
        } else {
            ps = s;
            pt = t;
        }
 
        printf("%s\n", ps);
 
        look = *ps;
        say = 1;
        while(*(++ps)) {
            if(*ps == look)
                say++;
            else {
                *pt++ = '0' + say;
                *pt++ = look;
 
                look = *ps;
                say = 1;
            }
        }
        *pt++ = '0' + say;
        *pt++ = look;
    }
 
    return 0;
}

