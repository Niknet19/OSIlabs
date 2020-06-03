#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(){
        char c;
        int file;
        int lines[101] = {0};
        int num = 1;
        char string[256];
        file = open("testfile.txt", O_RDONLY);

        while(read(file, &c, 1)){
                if(c == '\n'){
                        lines[num] = lseek(file, 0, SEEK_CUR);
                        ++num;
                }
        }
        c=num;
        char n;
        while(1){
                printf("Write N of string: ");
                scanf("%s",&n);
                if(n == '0') {
                        close(file);
                        return 0;
                }
                n=atoi(&n);
                if(n==0){
                printf("N should be a number!\n");
                continue;}
                if(n < 0) printf("N should be > 0!\n");
                else if(n >= c){
                         printf("Out of range!\n");}
                else {
                        lseek(file, lines[n - 1], SEEK_SET);
                        read(file, string, lines[n ] - lines[n - 1] - 1);
                        string[lines[n] - lines[n - 1]-1] = '\n';
                        write(1, string, lines[n] - lines[n - 1]);
                }
        }

        close(file);
 return 0;
}
