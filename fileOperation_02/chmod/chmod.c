/*
다음 조건을 만족하는 프로그램을 작성하시오.
1. struct stat형 변수 statbuf를 선언한다.
2. stat() 함수를 사용하여 "foo" 파일의 상태 정보를 statbuf에 저장한다.
    ㄴ stat() 호출에 실패하면 perror("stat(foo)")를 호출
3. "foo" 파일의 기존 권한을 기반으로 다음과 같이 권한을 변경한다.
    ㄴ 기존 st_mode 값에서 group의 execute 권한을 제거한다.
    ㄴ set-group-ID 비트 설정
    ㄴ 비트 연산자 &, ~를 사용한다.
    ㄴ 변경에 실패하면 perror("chmod(foo)")를 호출한다.
4. "bar" 파일의 권한을 기존 권한과 상관없이 다음과 같이 직접 설정한다.
    ㄴ 소유자(user): 읽기·쓰기
    ㄴ 그룹(group): 읽기
    ㄴ 기타 사용자(other): 읽기
5. "bar" 파일에 대한 chmod() 호출에 실패하면 perror("chmod(bar)")를 호출한다.
6. 모든 작업을 마치면 return 0;으로 종료한다.
*/

#include <stdio.h>
#include <sys/stat.h>


int main(void)
{
    struct stat statebuf;
    int state;

    state = stat("foo", &statebuf);
    if(state < 0)
        perror("stat(foo)");
    int ch = chmod("foo", (statebuf.st_mode & ~S_IXGRP) | S_ISGID);
    if(ch < 0)
        perror("chmod(foo)");
    
    if(chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
        perror("chmod(bar)");

    return 0;
}