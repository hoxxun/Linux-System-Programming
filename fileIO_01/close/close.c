/*

1. 정수 변수 filedes와 문자열 "afile"을 저장한 문자 배열 fname을 선언한다.
2. open()으로 fname의 파일을 읽기·쓰기 모드로 열고, 반환값을 filedes에 저장한다. 파일을 새로 생성하는 옵션은 사용하지 않는다.
3. 반환값이 -1이면 다음 메시지를 출력한다. 파일 이름은 fname을 이용한다.
    ㄴ afile cannot be opened.
4. 성공 여부와 관계없이 조건문 다음에서 close(filedes)를 호출한다.
5. 마지막에 return 0;으로 종료한다.

*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int filedes;
    char fname[] = "afile";

    filedes = open(fname, O_RDWR);
    if(filedes == -1)
    {
        printf("%s cannot be opened\n", fname);
    }
    close(filedes);

    return 0;
}
