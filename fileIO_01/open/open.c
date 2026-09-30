/*
1. 현재 작업 디렉터리의 example.txt를 읽기·쓰기용으로 연다.
2. 파일이 없으면 새로 생성한다.
3. 새 파일의 권한은 다음과 같이 지정한다.
    ㄴ소유자 : 읽기, 쓰기
    ㄴ소유 그룹 : 읽기
    ㄴ기타 사용자 : 없음
4. 파일이 이미 있으면 기존 내용을 지우지 않는다.
5. 열기에 실패하면 열기 실패를 출력하고 return 1;로 종료한다.
6. 성공하면 반환받은 fd를 출력
*/

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("example.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP);
    if(fd == -1)
    {
        printf("열기 실패\n");
        return 1;
    }
    printf("%d\n", fd);

    return 0;
}