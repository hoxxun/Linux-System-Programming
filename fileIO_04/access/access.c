/*
/*
 
다음 조건을 만족하는 access.c를 작성하시오.

1. main()은 명령행 인자를 사용하도록 작성한다.
    ㄴargc와 argv를 사용한다.
2. 프로그램 실행 시 검사할 파일의 경로명을 하나 전달받는다.
    ㄴ인자의 개수가 2개가 아니면 다음 사용법을 출력한다.
    ㄴUsage: a.out <pathname>
3. access() 함수를 사용하여 전달받은 파일의 읽기 권한을 검사한다.
    ㄴ검사할 파일은 argv[1]을 사용한다.
    ㄴmode는 R_OK를 사용한다.
4. access() 호출 결과가 실패하면 perror()를 사용하여 다음 메시지를 출력한다.
    ㄴR_OK
5. access() 호출에 성공하면 다음 문자열을 출력한다.
    ㄴread access OK
6. open() 함수를 사용하여 argv[1] 파일을 읽기 전용으로 연다.
    ㄴO_RDONLY를 사용한다.
7. open() 호출에 실패하면 perror()를 사용하여 다음 메시지를 출력한다.
    ㄴO_RDONLY
8. open() 호출에 성공하면 다음 문자열을 출력한다.
    ㄴopen for reading OK
9. main()은 0을 반환하여 종료한다.
10. 사용하는 함수와 상수에 필요한 헤더를 포함한다.

*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char * argv[])
{
    int fd;

    if(argc != 2)
    {
        printf("Usage: a.out <pathname>\n");
        return -1;
    }
    
    if(access(argv[1], R_OK) == -1)
        perror("R_OK");
    else
        printf("read access OK\n");
    
    fd = open(argv[1], O_RDONLY);
    if(fd < 0)
        perror("O_RDONLY");
    else
        printf("open for reading OK\n");
    
    close(fd);
    
    return 0;
}