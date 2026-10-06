/*
 
다음 조건을 만족하는 dup2.c를 작성하시오.

1. main() 안에 파일 디스크립터를 저장할 정수 변수 fd를 선언한다.
2. creat() 함수를 사용하여 "afile"이라는 파일을 생성한다.
    ㄴ소유자에게 읽기 권한과 쓰기 권한을 부여한다.
    ㄴ반환된 파일 디스크립터는 fd에 저장한다.
3. 파일 생성에 실패하면 perror()를 사용하여 다음 메시지를 출력한다.
    ㄴafile
4. printf()를 사용하여 다음 문자열을 화면에 출력한다.
    ㄴThis is displayed on the screen.
5. dup2() 함수를 사용하여 fd가 가리키는 파일을
   표준 출력 파일 디스크립터가 가리키도록 한다.
    ㄴoldfd는 fd를 사용한다.
    ㄴnewfd는 STDOUT_FILENO를 사용한다.
6. 원래 "afile"을 가리키고 있던 fd를 close()로 닫는다.
7. printf()를 사용하여 다음 문자열을 출력한다.
    ㄴThis is written into the redirected file.
    ㄴ이 문자열은 화면이 아니라 "afile"에 저장되어야 한다.
8. main()은 0을 반환하여 종료한다.
9. 사용하는 함수와 상수에 필요한 헤더를 포함한다.

*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd;

    fd = creat("afile2", S_IRUSR | S_IWUSR);
    if(fd < 0)
        perror("afile");
    printf("This is displayed on the screen\n");

    dup2(fd, STDOUT_FILENO);
    close(fd);

    printf("This is written into the redirected file\n");
    
    return 0;
}