/*
다음 조건을 만족하는 umask.c를 작성하시오.

1. main() 함수를 정의한다.
2. creat()를 사용하여 test 파일을 생성한다.
    ㄴ 소유자: 읽기·쓰기
    ㄴ 소유 그룹: 읽기·쓰기
    ㄴ 기타 사용자: 읽기·쓰기
    ㄴ 별도로 umask()를 설정하지 않는다.
3. umask()를 사용하여 마스크 값을 0으로 설정한다.
4. creat()를 사용하여 foo 파일을 생성한다.
    ㄴ 소유자: 읽기·쓰기
    ㄴ 소유 그룹: 읽기·쓰기
    ㄴ 기타 사용자: 읽기·쓰기
    ㄴ 파일 생성에 실패하면 perror("foo")를 호출한다.
5. umask()를 사용하여 다음 권한을 제한한다.
    ㄴ 소유 그룹: 읽기·쓰기
    ㄴ 기타 사용자: 읽기·쓰기
6. creat()를 사용하여 bar 파일을 생성한다.
    ㄴ 소유자: 읽기·쓰기
    ㄴ 소유 그룹: 읽기·쓰기
    ㄴ 기타 사용자: 읽기·쓰기
    ㄴ 파일 생성에 실패하면 perror("bar")를 호출한다.
7. 모든 작업을 마치면 return 0; 으로 종료한다.
8. 사용하는 함수에 필요한 헤더 파일을 포함한다.

*/

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(void)
{
    int fd1, fd2;
    creat("test", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    umask(0);
    fd1 = creat("foo", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if(fd1 < 0)
        perror("foo");

    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    fd2 = creat("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if(fd2 < 0)
        perror("bar");
    
    return 0;
}