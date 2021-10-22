k = 20, i = 519;
int line_num = 0;
while (1)
{
    line[line_num] = (unsigned int)RX_Package[k][i - 1];
    line[line_num] = (line[line_num] << 8) + (unsigned int)RX_Package[k][i];
    line_num++;
    i += 8;
    if (i >= 1024)
        k++, i = 7;
    if (k == 42 || line_num == 2625)
        break;
}
//	for(int j = 0;j<line_num;j++)
//		printf("%d\n",line[j]);
int offset = 0;
line_num = 1;
i = 9;
while (1)
{
    RX_Package[k][i - 1] = (unsigned char)line_num >> 8;
    RX_Package[k][i] = (unsigned char)line_num;
    i += 8;
    if (i >= 1024)
        k++, i = 1;
    if (k >= 321)
        break;
    offset++;
    if (offset == line[line_num])
        line_num++;
}

int cpy_num = 0;
for (int j = 0; j <= 320; j++)
{
    for (int jj = 0; jj < 1024; jj++)
    {
        if (j > 20 && j < 41)
            break;
        if ((j == 20 && jj >= 512) || (j > 20 && j < 41) || (j == 41 && jj < 8))
            continue;
        //printf("%02x",RX_Package[j][jj]);
        memcpy(DmaTxBuffer + cpy_num, &RX_Package[j][jj], 1);
        cpy_num++;
        if (cpy_num >= 307576)
            break;
        //			if (jj % 8 == 7)
        //				printf("\n");
    }
}