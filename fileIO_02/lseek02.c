/*

다음 조건을 만족하는 hole.c를 작성하시오.

1. 전역 배열 buf1을 선언하고 문자열 "abcdefghij"로 초기화한다.
2. 전역 배열 buf2를 선언하고 문자열 "ABCDEFGHIJ"로 초기화한다.
3. main() 안에 파일 디스크립터를 저장할 정수 변수 fd를 선언한다.
4. creat()를 사용하여 "file.hole" 파일을 생성한다.
    ㄴ 소유자: 읽기·쓰기
    ㄴ 소유 그룹: 읽기
    ㄴ 기타 사용자: 읽기
    ㄴ 반환된 파일 디스크립터는 fd에 저장한다.
5. 파일 생성에 실패하면 perror()를 사용하여 다음 문자열을 전달한다.
    ㄴ "file.hole"
6. write()를 사용하여 buf1의 데이터 10바이트를 파일에 쓴다.
    ㄴ 파일 디스크립터는 fd를 사용한다.
    ㄴ write()의 반환값이 10이 아니면 perror()를 호출한다.
    ㄴ perror()에 전달할 문자열은 "buf1"이다.
7. lseek()를 사용하여 파일의 현재 위치를 파일 시작점에서 40바이트 떨어진 위치로 이동한다.
    ㄴ perror()에 전달할 문자열은 "lseek"이다.
8. 이동한 위치에서 write()를 사용하여 buf2의 데이터 10바이트를 파일에 쓴다.
    ㄴ write()의 반환값이 10이 아니면 perror()를 호출한다.
    ㄴ perror()에 전달할 문자열은 "buf2"이다.
9. 프로그램은 return 0;으로 종료한다.
10. 사용하는 함수와 자료형에 필요한 헤더를 포함한다.

*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
    int fd;
    fd = creat("file.hole", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if(fd == -1)
        perror("file.hole");
    ssize_t w = write(fd, buf1, 10);
    if(w !=10)
        perror("buf1");
    off_t pos = lseek(fd, 40, SEEK_SET);
    if(pos == -1)
        perror("lseek");
    if(write(fd, buf2, 10) != 10)
        perror("buf2");
    
    return 0;
}
