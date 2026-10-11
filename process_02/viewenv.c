/*
전역 변수 environ을 이용하여 현재 프로세스에 전달된 모든 환경 변수를 출력하는 프로그램 viewenv.c를 작성하시오.
*/

#include <stdio.h>
#include <stdlib.h>

extern char ** environ;

int main(void)
{
    char ** env = environ;
    while(*env)
    {
        printf("%s\n", *env);
        env++;
    }
    return 0;
}