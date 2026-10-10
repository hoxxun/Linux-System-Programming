/*
다음 조건을 만족하는 프로그램을 작성하시오.

echo "ABCDEFGHIJ" > test.txt
    ㄴ 5바이트보다 긴 파일 하나 만들기
1. "test.txt" 파일의 크기를 5바이트로 변경한다.
2. 파일 크기 변경에는 truncate() 함수를 사용한다.
3. truncate() 호출이 실패하면 perror("truncate")를 호출한다.
4. 성공하면 별도의 출력 없이 프로그램을 종료한다.
5. 필요한 헤더 파일을 포함한다.
6. 모든 작업을 마치면 return 0;으로 종료한다.
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    if(truncate("test.txt", 5) < 0)
        perror("turncate");
    
    return 0;
}