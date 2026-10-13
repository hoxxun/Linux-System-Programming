/*

현재 작업 디렉터리를 변경하고, 변경된 디렉터리의 절대 경로를 출력하는 프로그램을 작성하시오.
1. 필요한 헤더 파일을 포함한다.
2. 매크로 PATH_MAX를 정의하고 값은 1024로 지정한다.
3. main() 함수를 정의한다.
4. 현재 작업 디렉터리의 경로를 저장할 문자 배열 path를 선언한다.
   - 배열 크기는 PATH_MAX + 1로 설정한다.
5. 현재 작업 디렉터리를 /tmp로 변경한다.
   - 변경에 실패하면 perror()를 이용해 "error chdir" 오류 메시지를 출력한다.
6. 디렉터리 변경에 성공했다면 getcwd()를 이용하여 현재 작업 디렉터리의 절대 경로를 가져온다.
   - 첫 번째 인자는 path를 사용한다.
   - 두 번째 인자는 PATH_MAX를 사용한다.
   - 실패하면 perror()를 이용해 "error getcwd" 오류 메시지를 출력한다.
7. getcwd()가 성공했다면 다음 형식으로 변경된 디렉터리의 경로를 출력한다.
   - Current working directory changed to 경로

*/

#include <stdio.h>
#include <unistd.h>
#include <error.h>

#define PATH_MAX 1024

int main(void)
{
    char path[PATH_MAX + 1];

    int dir = chdir("/tmp");
    
    if(dir < 0)
        perror("error chdir");
    else
    {
        char * result = getcwd(path, PATH_MAX); 
        if(result == NULL)
            perror("error getcwd");
        else    
            printf("Current working directory changed to %s\n", path);
    }
}