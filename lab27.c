#include <stdio.h>

int main(){
        FILE *count;
        FILE *pipe;
        char ch[128];

        count = fopen("testfile.txt", "r");
        if(count == NULL){
                printf("File open error!\n");
                return 1;
        }

        pipe = popen("wc -l", "w");
        while(fgets(ch, 128, count) != NULL){
                if(ch[0] == '\n'){
                        fputs(ch, pipe);
                }
        }

        fclose(count);
        pclose(pipe);

        return 0;
}
