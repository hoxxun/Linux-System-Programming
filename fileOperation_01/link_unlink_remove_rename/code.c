/*

다음 조건을 만족하는 프로그램을 작성하시오.

1. 현재 작업 디렉터리에 "tempfile"이라는 파일을 읽기·쓰기 모드로 연다.
2. 파일이 없으면 새로 생성하고, 파일이 이미 존재하면 기존 내용을 모두 지운다.
3. 새로 생성되는 파일의 권한은 0666으로 설정한다.
4. open()에 실패하면 perror()를 이용하여 오류 메시지를 출력한다.
    ㄴ open1
5. 파일을 연 직후 unlink()를 사용하여 디렉터리에서 "tempfile"의 이름을 삭제한다.
6. 열린 파일에 다음 문자열을 기록한다.
    ㄴ "How are you?"
7. write()가 실패하면 perror()를 이용하여 오류 메시지를 출력한다.
    ㄴ write
8. lseek()를 사용하여 파일의 현재 위치를 파일의 시작 위치로 이동한다.
9. read()를 사용하여 파일의 내용을 buf에 읽는다.
10. read()가 실패하면 perror()를 이용하여 오류 메시지를 출력한다.
    ㄴ read
11. 읽어온 문자열의 끝에 '\0'을 추가하여 문자열로 만든다.
12. 읽어온 내용을 printf()를 사용하여 출력한다.
13. 파일을 close()한다.
14. 다시 "tempfile"을 읽기·쓰기 모드로 open()한다.
15. 두 번째 open()에 실패하면 perror()를 이용하여 오류 메시지를 출력한다.
16. 마지막으로 close()를 호출하고 프로그램을 종료한다.

*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd;
    ssize_t len;
    char buf[20];

    fd = open("tempfile", O_RDWR | O_CREAT | O_TRUNC , 0666 );
    if(fd < 0)
        perror("open1");
    unlink("tempfile");
    ssize_t w = write(fd, "How are you?", 12);
    if(w < 0)
        perror("write");
    lseek(fd, 0, SEEK_SET);
    len = read(fd, buf, sizeof(buf));
    if(len < 0)
        perror("read");
    buf[len] = '\0';
    printf("%s", buf);

    close(fd);

    fd = open("tempfile", O_RDWR);
    if(fd < 0)
        perror("open2");
    
    close(fd);

    return 0;
}