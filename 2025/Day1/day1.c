#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256


int processInput(char *filePath, int startingPoint){
    FILE *file = fopen(filePath, "r");
    if(file == NULL){
        perror("Error opening file");
        return 0;
    }

    char line[MAX_LINE_LENGTH];
    int answer = 0;
    int curr_position = startingPoint;

    while(fgets(line, sizeof(line), file)){
        // Trim newlines
        line[strcspn(line, "\r\n")] = 0; 
        
        // Skip empty lines
        if(strlen(line) < 2) continue;

        char direction = line[0];
    
        int value = atoi(line + 1);

        for(int i = 0; i < value; i++){
            if(direction == 'L'){
                curr_position++;
                // Wrap 99 -> 0
                if(curr_position == 100){
                    curr_position = 0;
                }
            }
            else if(direction == 'R'){
                curr_position--;
                // Wrap 0 -> 99
                if(curr_position == -1){
                    curr_position = 99;
                }
            }
            
            if(curr_position == 0){
                answer++;
            }
        }
    }
    
    fclose(file); 
    return answer;
}

int main(int argc, char *argv[]){
    printf("Hello, World!\n");
    int answer;

    if(argc != 2){
        fprintf(stderr, "Usage: %s <filePath>\n", argv[0]);
    }

    char *filePath = argv[1];
    printf("File path receioved: %s\n", filePath);

    int startingPoint = 50;
    answer = processInput(filePath, startingPoint);
    printf("Answer: %d\n", answer);


    return 0;
}