/*

다음 조건을 만족하는 creat.c를 작성하시오.

1. 매크로 PERMS를 정의하고 값은 **8진수 0644**로 지정한다.
    ㄴ소유자: 읽기·쓰기
    ㄴ소유 그룹: 읽기
    ㄴ기타 사용자: 읽기
2. 전역 변수로 문자 포인터 filename을 선언하고 "newfile"을 가리키도록 한다.
3. main() 안에 파일 디스크립터를 저장할 정수 변수 fd를 선언한다.
4. open()으로 다음 조건에 맞게 파일을 연다.
    ㄴ파일 이름은 filename을 사용한다.
    ㄴ읽기·쓰기가 가능해야 한다.
    ㄴ파일이 없으면 생성한다.
    ㄴ생성 권한은 PERMS를 사용한다.
    ㄴ반환된 파일 디스크립터는 fd에 저장한다.
5. 열기에 실패하면 파일 이름을 이용해 다음 메시지를 출력하고, **exit(1)**로 종료한다.
    ㄴCannot create newfile
6. 성공하면 출력 없이 **exit(0)**으로 종료한다.
7. 사용하는 함수에 필요한 헤더를 포함한다.

*/

#include <stdio.h>
#include <stdlib.h> //exit()
#include <fcntl.h>

#define PERMS 0644

char * filename = "newfile";

int main(void)
{
    int fd;
    fd = open(filename, O_RDWR | O_CREAT , PERMS);
    if(fd == -1)
    {
        printf("cannot create %s\n", filename);
        exit(1);
    }
    exit(0);
}