/*
명령행 인자로 환경 변수 이름을 전달받아 해당 환경 변수의 값을 출력하는 프로그램을 작성하시오.
1. main() 함수를 정의한다.
2. main() 함수 내부에 두 개의 문자 포인터 변수를 선언한다.
   ㄴ var: 검색할 환경 변수의 이름을 저장한다.
   ㄴ value: 검색한 환경 변수의 값을 저장한다.
3. 명령행 인자의 개수를 검사한다.
   ㄴ 인자 개수가 1 또는 3 이상이면 오류로 처리한다.
   ㄴ fprintf()를 이용하여 표준 오류(stderr)에 다음 메시지를 출력한다.
   ㄴ usage: environ var [value]
   ㄴ 오류 발생 시 exit(1)로 종료한다.
4. 명령행 인자로 전달받은 환경 변수 이름을 var에 저장한다.
5. 환경변수를 가져오는 함수를 사용하여 환경 변수를 검색한다.
   ㄴ 검색할 환경 변수 이름은 var를 사용한다.
   ㄴ 반환값은 value에 저장한다.
6. 환경 변수 검색 결과에 따라 메시지를 출력한다.
   ㄴ value가 NULL이 아니면 다음 메시지를 출력한다.
   ㄴ Variable 변수이름 has value 변수값
   ㄴ value가 NULL이면 다음 메시지를 출력한다.
   ㄴ Variable 변수이름 has no value
7. 사용하는 함수에 필요한 헤더 파일을 포함한다.

실행 예시 1
gcc getenv.c
./a.out HOME

실행 예시 2
gcc getenv.c
./a.out ABC123

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
    char * var;
    char * value;

    if(argc == 1 || argc >= 3)
    {
        fprintf(stderr, "usage: environ var [value]\n");
        exit(1);
    }

    var = argv[1];
    value = getenv(var);

    if(value != NULL)
        printf("Varialbe %s has value %s\n", var, value);
    else if(value == NULL)
        printf("Variable %s has no value\n", var);

    return 0;
}