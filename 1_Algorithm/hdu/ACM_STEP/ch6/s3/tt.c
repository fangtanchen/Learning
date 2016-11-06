#include<stdio.h>
//#define scanf scanf_s
char s1[1000];
char s2[1000];
char ss[2000];
int main()
{
int i, j;
scanf("%s", s1);
scanf("%s", s2);
for (i = 0; s1[i] != '\0'; i++) ss[i] = s1[i];
for (j = 0; s2[j] != '\0'; j++) ss[i + j] = s2[j];
ss[i + j] = '\0';
printf("%s\n", ss);
return 0;
}

