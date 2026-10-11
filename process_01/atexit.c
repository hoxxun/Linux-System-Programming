/*
다음 조건을 만족하는 atexit.c 프로그램을 작성하시오.

1. my_exit2() 함수를 종료 처리 함수로 등록한다.
    ㄴ등록에 실패하면 err_sys("can't register my_exit2")를 호출한다.
2. my_exit1() 함수를 종료 처리 함수로 등록한다.
    ㄴ등록에 실패하면 err_sys("can't register my_exit1")를 호출한다.
3. my_exit1() 함수를 한 번 더 등록한다.
    ㄴ등록에 실패하면 err_sys("can't register my_exit1")를 호출한다.
4. printf()를 사용하여 다음 문자열을 출력한다.
    ㄴmain is done
5. 모든 작업을 마치면 return 0;으로 종료한다.
6. my_exit1() 함수를 정의한다.
    ㄴstatic 함수로 정의한다.
    ㄴfirst exit handler를 출력한다.
7. my_exit2() 함수를 정의한다.
    ㄴstatic 함수로 정의한다.
    ㄴsecond exit handler를 출력한다.
8. err_sys() 함수를 정의한다.
    ㄴ매개변수로 const char *message를 받는다.
    ㄴfputs()를 사용하여 전달받은 메시지를 stderr에 출력한다.
    ㄴfputc()를 사용하여 줄바꿈 문자 '\n'을 stderr에 출력한다.
    ㄴexit(1)을 호출하여 종료한다.
9. 사용하는 함수에 필요한 헤더 파일을 포함한다.
*/

#include <stdio.h>
#include <stdlib.h>

static void my_exit2()
{
    printf("second exit handler\n");
}

static void my_exit1()
{
    printf("first exit handler\n");
}

void err_sys(const char * message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

int main(int argc, char * argv[])
{
    if(atexit(my_exit2) != 0)
        err_sys("can't register my exist2");
    
    if(atexit(my_exit1) != 0)
        err_sys("can't register my exist1");
    
    if(atexit(my_exit1) != 0)
        err_sys("can't register my exist1");

    printf("main is done\n");

    return 0;
}