/*
문제: read()로 파일 전체 크기 구하기

testfile을 반복해서 읽어 총 읽은 바이트 수를 계산하는 프로그램을 작성하시오.

1. 매크로 BUFSIZE를 512로 정의한다.
2. 다음 변수를 선언한다.
    ㄴ크기가 BUFSIZE인 문자 배열 buffer
    ㄴ파일 디스크립터를 저장할 정수 fd
    ㄴ읽은 바이트 수를 저장할 ssize_t형 nread
    ㄴ누적 바이트 수를 저장할 long형 total — 초깃값 0
3. testfile을 읽기 전용으로 연다. 실패하면 exit(1)로 종료한다.
4. while문으로 다음 작업을 반복한다.
    ㄴ한 번에 최대 BUFSIZE바이트를 buffer에 읽는다.
    ㄴ반환값을 nread에 저장한다.
    ㄴnread가 양수인 동안 실제로 읽은 바이트 수를 total에 누적한다.
5. 반복이 끝나면 파일을 닫는다.
6. 다음 형식으로 누적값을 출력한다. long의 출력 형식은 %ld를 사용한다.
    ㄴNumber of characters in testfile : 3456
7. exit(0)으로 종료하고, 필요한 헤더를 포함한다.
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFSIZE 512

int main(void)
{
    char buffer[BUFSIZE];
    int fd;
    ssize_t nread;
    long total = 0;

    fd = open("testfile", O_RDONLY);
    if(fd == -1)
        exit(1);
    while((nread = read(fd, buffer,BUFSIZE)) > 0)
    {
        total += nread;
    }
    close(fd);

    printf("Number of characters in testfile : %ld\n", total);
    exit(0);
}