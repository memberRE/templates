#include <stdio.h>   
#include <string.h>   
   
typedef unsigned long dwrd;   
   
char cmd[32][4]={ {"$0"}, {"$at"}, {"$v0"}, {"$v1"}, {"$a0"}, {"$a1"}, {"$a2"}, {"$a3"}, {"$t0"}, {"$t1"}, {"$t2"}, {"$t3"},   
                {"$t4"}, {"$t5"}, {"$t6"}, {"$t7"}, {"$s0"}, {"$s1"}, {"$s2"}, {"$s3"}, {"$s4"}, {"$s5"}, {"$s6"}, {"$s7"},   
                {"$t8"}, {"$t9"}, {"$k0"}, {"$k1"}, {"$gp"}, {"$sp"}, {"$fp"}, {"$ra"}};   
int main()   

{   
    dwrd code, firstsix, lastsix, rs, rt, rd;   
    int i, j, now, immediate, l, label;   
    char mips[200], number[20];   
    scanf("%x",&code);   
    while (code != 0){
        firstsix = code >> 26;   
        lastsix = (code << 58) >> 58;   
/* add */       
        if (firstsix == 0 && lastsix == 32){   
            strcpy(mips, "add");   
            mips[3]=' ';   
            rd = (code >> 11) & 0x1F;   
            rt = (code >> 16) & 0x1F;   
            rs = (code >> 21) & 0x1F;   
   
            now = 4;   
            strcpy(&mips[now], cmd[rd]);   
   
            now += 3;   
            mips[now++] = ',';   
            strcpy(&mips[now], cmd[rs]);   
   
            now += 3;   
            mips[now++] = ',';   
            strcpy(&mips[now], cmd[rt]);   
   
            now += 3;   
            mips[now] = '\0';   
   
        }   
/* sub */          
        else if (firstsix == 0 && lastsix == 34){   
            strcpy(mips, "sub");   
            mips[3]=' ';   
            rd = (code >> 11) & 0x1F;   
            rt = (code >> 16) & 0x1F;   
            rs = (code >> 21) & 0x1F;   
   
            now = 4;   
            strcpy(&mips[now], cmd[rd]);   
   
            now += 3;   
            mips[now++] = ',';   
            strcpy(&mips[now], cmd[rs]);   
   
            now += 3;   
            mips[now++] = ',';   
            strcpy(&mips[now], cmd[rt]);   
   
            now += 3;   
            mips[now] = '\0';   
   
        }   
/* slt */          
        else if (firstsix == 0 && lastsix == 42){   
            strcpy(mips, "slt");   
            mips[3]=' ';   
            rd = (code >> 11) & 0x1F;   
            rt = (code >> 16) & 0x1F;   
            rs = (code >> 21) & 0x1F;   
   
            now = 4;   
            strcpy(&mips[now], cmd[rd]);   
   
            now += 3;   
            mips[now++] = ',';   
            strcpy(&mips[now], cmd[rs]);   
   
            now += 3;   
            mips[now++] = ',';   
            strcpy(&mips[now], cmd[rt]);   
   
            now += 3;   
            mips[now] = '\0';   
   
        }   
/* lw */           
        else if (firstsix == 35){   
            strcpy(mips, "lw");   
            mips[2] = ' ';   
               
            immediate = code & 0xFFFF;   
            rt = (code >> 16) & 0x1F;   
            rs = (code >> 21) & 0x1F;   
   
            l = 0;   
            while (immediate > 0){   
                number[l] = (immediate % 10) + 48;   
                l++;   
                immediate /= 10;   
            }   
            number[l] = '\0';   
   
            now = 3;   
            strcpy(&mips[now], cmd[rt]);   
   
            now += 3;   
            mips[now++] = ',';   
            for (i = l - 1; i >= 0; i--){   
                mips[now] = number[i];   
                now++;   
            }   
   
            mips[now++] = '(';   
            strcpy(&mips[now], cmd[rs]);   
   
            now += 3;   
            mips[now++] = ')';   
            mips[now] = '\0';   
       
        }   
/* sw */           
            else if (firstsix == 43){   
            strcpy(mips, "sw");   
            mips[2] = ' ';   
   
            immediate = code & 0xFFFF;   
            rt = (code >> 16) & 0x1F;   
            rs = (code >> 21) & 0x1F;   
   
            l = 0;   
            while (immediate > 0){   
                number[l] = (immediate % 10) + 48;   
                l++;   
                immediate /= 10;   
            }   
            number[l] = '\0';   
   
            now = 3;   
            strcpy(&mips[now], cmd[rt]);   
   
            now += 3;   
            mips[now++] = ',';   
            for (i = l - 1; i >= 0; i--){   
                mips[now] = number[i];   
                now++;   
            }   
   
   
            mips[now++] = '(';   
            strcpy(&mips[now], cmd[rs]);   
   
            now += 3;   
            mips[now++] = ')';   
            mips[now] = '\0';   
        }   
/* beq */          
        else if (firstsix == 4){   
            strcpy(mips, "beq");   
            mips[3] = ' ';   
   
            label = code & 0xFFFF;   
            rt = (code >> 16) & 0x1F;   
            rs = (code >> 21) & 0x1F;   
           
            l = 0;   
            while (label > 0){   
                number[l] = (label % 10) + 48;   
                l++;   
                label /= 10;   
            }   
            number[l] = '\0';   
   
            now = 4;   
            strcpy(&mips[now], cmd[rs]);   
   
            now += 3;   
            mips[now++] = ',';   
            strcpy(&mips[now], cmd[rt]);   
   
            now += 3;   
            mips[now++] = ',';   
            for (i = l - 1; i >= 0; i--){   
                mips[now] = number[i];   
                now++;   
            }   
   
            mips[now] = '\0';   
   
        }   
/* j */        
        else if (firstsix == 2){   
             strcpy(mips, "j");   
             mips[1] = ' ';   
                
             label = code & 0x3FFFFFF;   
                
             l = 0;   
             while (label > 0){   
                number[l] = (label % 10) + 48;   
                l++;   
                label /= 10;   
             }   
             number[l] = '\0';   
   
             now = 2;   
             for (i = l - 1; i >= 0; i--){   
                mips[now++] = number[l];   
             }   
             mips[now] = '\0';   
                
        }   
        printf("%s\n",mips);   
        scanf("%x",&code);   
    }   
    return 0;   
}   
