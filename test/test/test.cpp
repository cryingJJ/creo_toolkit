// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string.h>

#include <stdio.h>
#include <io.h>
#include <stdlib.h>
int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fp;
    char line[100]; //Ӧ�����ֻ��12���ģ�����2�Ա��Ժ���չ
    int i = 1;
	int _col = _wtoi(argv[2]);
    int _row = _wtoi(argv[3]);
    fp = fopen("D:\\mydoc\\creo_toolkit\\test\\Debug\\ReadMe.txt", "r");
    if (fp == NULL)
    {
        printf("Can not load the print file.");
        return -1;
    }

    while (!feof(fp))
    {
        printf("input line %d:",i);
        i++;
        fgets(line, 100, fp);
        printf("%s", line);
		printf("   %d\n", strlen(line));
    }
    fclose(fp);
    return 0;
}