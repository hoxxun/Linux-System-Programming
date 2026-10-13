/*

명령행 인자에 따라 하드 링크 또는 심볼릭 링크를 생성하는 프로그램을 작성하시오.

1. 필요한 헤더 파일을 포함한다.
2. main() 함수를 정의한다.
3. 명령행 인자의 개수를 확인한다.
   ㄴ 인자가 3개 미만이거나 4개를 초과하면 잘못된 입력으로 판단한다.
   ㄴ 인자가 4개라면 argv[1]이 "-s"인지 확인한다.
   ㄴ "-s"가 아니라면 잘못된 입력으로 판단한다.
   ㄴ 잘못된 입력이라면 printf()로 사용법을 출력하고 return 1;로 종료한다.
4. 명령행 인자가 4개라면 심볼릭 링크를 생성한다.
   ㄴ symlink()를 사용한다.
   ㄴ 첫 번째 인자는 argv[2]를 사용한다.
   ㄴ 두 번째 인자는 argv[3]을 사용한다.
   ㄴ symlink()의 반환값을 그대로 반환한다.
5. 명령행 인자가 3개라면 하드 링크를 생성한다.
   ㄴ link()를 사용한다.
   ㄴ 첫 번째 인자는 argv[1]을 사용한다.
   ㄴ 두 번째 인자는 argv[2]를 사용한다.
   ㄴ link()의 반환값을 그대로 반환한다.
6. 링크 생성 성공 시 별도의 메시지는 출력하지 않는다.


실행 예시
1. 하드링크 생성
    ㄴ ./a.out original.txt hardlink.txt
    ㄴ 두 파일 이름은 동일한 i-node를 가리킨다.

2. 심볼릭 링크 생성
    ㄴ ./a.out -s original.txt symlink.txt
    ㄴ symlink.txt (심볼릭 링크) ──→ original.txt

3. 잘못된 인자 입력
    ㄴ ./a.out original.txt
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char * argv[])
{
    if( (argc < 3 || argc > 4)   ||   ((argc == 4) && ((strcmp(argv[1], "-s")) != 0)))
    {
        printf("Usage: %s <orig_file> <new_file>\n", argv[0]);
        return 1;
    }
    if(argc == 4)
    {
        int result = symlink(argv[2], argv[3]);
        return result;
    }
    if(argc == 3)
    {
        int result = link(argv[1], argv[2]);
        return result;
    }
}