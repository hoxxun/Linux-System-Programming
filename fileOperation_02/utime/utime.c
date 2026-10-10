/*
다음 조건을 만족하는 프로그램을 작성하시오
.
1. main() 함수는 명령행 인자를 사용하도록 작성
2. 반복문을 사용하여 argv[1]부터 마지막 인자까지 각 파일을 차례대로 처리한다.
3. 각 파일에 대해 stat() 함수를 사용하여 현재 파일 정보를 struct stat형 변수에 저장한다.
   ㄴ 파일의 현재 접근 시간과 수정 시간을 나중에 복원할 수 있도록 저장
   ㄴ stat() 호출에 실패하면 perror(argv[i])를 호출한다.
4. 각 파일을 open() 함수로 연다.
   ㄴ 읽기·쓰기 가능하도록 한다.
   ㄴ 플래그를 사용하여 파일의 내용을 비운다.
   ㄴ open() 호출에 실패하면 perror(argv[i])를 호출한다.
5. 파일 내용을 비운 뒤, stat()으로 저장해 둔 기존 시간 정보를 struct utimbuf형 변수에 저장한다.
   ㄴ actime에는 기존 접근 시간을 저장한다.
   ㄴ modtime에는 기존 수정 시간을 저장한다.
6. utime() 함수를 사용하여 파일의 접근 시간과 수정 시간을 원래 값으로 복원한다.
   ㄴ 실패하면 perror(argv[i])를 호출한다.
7. 모든 명령행 인자에 대한 처리가 끝나면 return 0;으로 종료한다.
8. 사용하는 함수와 자료형에 필요한 헤더 파일을 포함한다.

*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <utime.h>
#include "error.h"

int main(int argc, char * argv[])
{
    int i;
    struct stat state;
    struct utimbuf timebuf;

    for(i=1; i<argc; i++)
    {
        if(stat(argv[i], &state) < 0)
            perror(argv[i]);
    
        if(open(argv[i], O_RDWR | O_TRUNC) < 0)
            perror(argv[i]);
        
        timebuf.actime =  state.st_atime;
        timebuf.modtime = state.st_mtime;
    
        if(utime(argv[i], &timebuf) < 0)
            perror(argv[i]);
    }
    
    return 0;
}