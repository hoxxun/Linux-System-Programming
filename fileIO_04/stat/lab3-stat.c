/*
stat() 시스템 호출을 이용하여 파일의 정보를 출력한다 

주어진 하나의 파일의 inode 번호, 해당 파일의 마지막으로 업데이트 된 날짜/시간, 마지막으로 접근한 날짜/시간을 출력한다
1. struct stat 타입의 구조체 변수 buf 를 선언
2. fstat을 호출하여 해당 파일에 대한 정보를 buf 구조에 받아오기
3. 파일의 inode 정보(컨트롤 스트링 %ld 사용하여 출력), 업데이트 시간(%ld 사용), 접근 시간(%ld 사용)을 buf 구조체의 해당 field로 부터 읽어서 출력 
*/

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

//test.txt 만듦

int main(void)
{
    int fd;
    struct stat buf;
    fd = open("test.txt", O_RDONLY);

    fstat(fd, &buf);

    printf("파일의 inode 정보: %ld\n", buf.st_ino);
    printf("업데이트 시간 : %ld\n", buf.st_mtim.tv_sec);
    printf("접근 시간: %ld\n", buf.st_atim.tv_sec);

    close(fd);

    return 0;
}