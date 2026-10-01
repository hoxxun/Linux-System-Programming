/*
문제: 메시지 출력과 쓰기 결과 확인

다음 조건을 만족하는 write.c를 작성하시오.

1. printf() 대신 **write()**를 사용한다.
2. 파일 디스크립터 **1**에 다음 문자열의 앞 27바이트를 쓴다.
    ㄴWelcome to System Programming
3. 반환값이 27과 다르면, 파일 디스크립터 **2**에 아래 문자열을 전달해 47바이트를 쓴다. 문자열 끝에는 \n을 넣는다.
    ㄴ"A write error has occurred on file descriptor 1\n"
4. 마지막에는 성공 여부와 관계없이 exit(0)으로 종료한다.
5. 사용하는 함수에 필요한 헤더를 포함한다. 별도의 open()은 사용하지 않는다.
*/

#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    ssize_t n;
    n = write(1,"Welcome to System Programming",27);
    if(n != 27)
    {
        write(2,"A write error has occurred on file descriptor 1\n", 47);
    }
    exit(0);
}