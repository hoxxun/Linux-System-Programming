/*
다음 조건을 만족하는 seek.c를 작성하시오.

1. main() 함수를 작성한다.
2. 표준 입력의 파일 디스크립터를 나타내는 STDIN_FILENO를 사용한다.
   ㄴ STDIN_FILENO의 값은 0이다.
3. lseek()를 사용하여 표준 입력의 현재 파일 위치를 확인한다.
4. lseek()의 반환값이 -1이면 다음 메시지를 출력한다.
   ㄴ cannot seek
5. lseek()의 반환값이 -1이 아니면 다음 메시지를 출력한다.
   ㄴ seek OK
6. 프로그램은 return 0;으로 종료한다.
7. lseek() 사용에 필요한 헤더를 포함한다.

*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    off_t pos = lseek(STDIN_FILENO, 0, SEEK_CUR);
    if(pos == -1)
        printf("cannot seek\n");
    else
        printf("seek ok\n");
    
    return 0;
}