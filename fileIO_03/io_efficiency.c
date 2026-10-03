/*
다음 조건을 만족하는 write1.c를 작성하시오.

1. BUFFSIZE를 512바이트로 정의한다.
2. FILESIZE를 100MB로 정의한다.
   ㄴ 100 * 1024 * 1024 바이트로 계산
3. COUNT를 FILESIZE / BUFFSIZE로 정의한다.
   ㄴ COUNT는 write()를 실행할 횟수를 의미한다.
4. main() 함수를 작성한다.
5. 정수형 변수 i와 파일 디스크립터를 저장할 fd를 선언한다.
6. BUFFSIZE 크기의 문자 배열 buf를 선언한다.
7. memset()을 사용하여 buf의 모든 공간을 공백 문자(' ')로 채운다.
8. creat()을 사용하여 "file.write" 파일을 생성한다.
   ㄴ 소유자에게 읽기 권한과 쓰기 권한을 부여한다.
   ㄴ 파일 생성에 실패하면 exit(1)로 프로그램을 종료한다.
9. for문을 사용하여 COUNT 횟수만큼 반복한다.
10. 반복문 안에서 write()를 사용하여
    buf에 저장된 BUFFSIZE 바이트의 데이터를 fd에 기록한다.
11. 파일 쓰기가 끝나면 close()를 사용하여 파일을 닫는다.
12. 프로그램은 exit(0)으로 종료한다.
13. creat(), write(), close() 등의 사용에 필요한 헤더를 포함한다.
14. 코드에서 BUFSIZE를 512 → 1024 → 2048처럼 늘려가면서 time ./a.out으로 실행 시간을 비교하라.

*/

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 512 //512 byte
#define FILESIZE (100 * 1024 * 1024) //100 MB
#define COUNT (FILESIZE/BUFSIZE)

int main(void)
{
    int i, fd;
    char buf[BUFSIZE];
    memset(buf, ' ', sizeof(buf));
    fd = creat("file.write", S_IRUSR | S_IWUSR);
    if(fd < 0)
        exit(1);
    for(i=0; i<COUNT; i++)
    {
        write(fd, buf, BUFSIZE);
    }
    close(fd);

    exit(0);
}
