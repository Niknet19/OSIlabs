#include <stdio.h>

int main(){
        FILE *pipe;
        char* text[4] = {"TEsT", ", " , "teXt", "!\n"};
        int i;

        pipe = popen("./lab26osi_2", "w");

        for(i = 0; i < 4; i++){
                fputs(text[i], pipe);
        }

        pclose(pipe);
}
