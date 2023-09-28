#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<errno.h>
struct S
{
    char arr[20];
    int age;
    double score;
};
int main() {
    FILE* pf = fopen("C:\\Users\\28768\\Desktop\\新建文本文档.txt", "w");
    if (NULL == pf)
    {
        printf("%s", strerror(errno));
        return 1;
    }
    struct S s = {"余晓理",34,78};
    fprintf(pf, "%s %d %.2lf", s.arr, s.age, s.score);
    //for (char i = 'a'; i < 'z'; i++)
    //{
    //    fputc(i,pf);  
    //}
    //int ch = fgetc(pf);
    //printf("%c\n", ch);
    //int n = 0;
    //while ((n = fgetc(pf)) !=EOF)
    //{
    //    printf("%c ", n);
    //}
    //char arr[20];
    //fgets(arr,5,pf);
    //printf("%s", arr);
    fclose(pf);
    pf = NULL;
    return 0;
}