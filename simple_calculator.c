#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isValid(char *line){
    while(*line != '\0'){
        if((*line >= '0' && *line <= '9') || *line == '+' || *line == '-'){
            line++;
        } else{
            return 0;
        }
    }
    return 1;
}

int convert(int start, int end, char *line){
    int result = 0;
    for(int i = start; i < end; i++){
        result = result * 10 + (line[i] - '0');
    }
    return result;
}

void calculate(char operator, int num, int *accumulator){
    switch(operator){
    case 43:
        *accumulator += num;
        break;
    case 45:
        *accumulator -= num;
        break;
    }
}

int getResult(char *line){
    int accumulator = 0; /*ban dau la 0*/
    int num; /*bien nay nhan so tu ham*/
    char operator = '+'; /*luu toan tu ban dau la +*/

    int start = 0;
    size_t len = strlen(line);
    
    for(size_t i = 0; i < strlen(line); i++){
        if(line[i] == '+' || line[i] == '-'){
            num = convert(start, i, line);
            start = i + 1;
            calculate(operator, num, &accumulator);
            operator = line[i];
        }
    }

    num = convert(start, len, line);
    calculate(operator, num, &accumulator);
    return accumulator;
}
int main(){

    /*input formula*/
    char *line = NULL;
    size_t len;
    ssize_t read;

    read = getline(&line, &len, stdin);

    /*check if input failed*/
    if(read < 1){
        fprintf(stderr, "Input bi loi");
        free(line);
    }

    /*remove \n if it exist*/
    line[strcspn(line, "\n")] = 0;

    /*a simple formula doesnt have special char like "a" -> "z" and "\", "*"*/
    int isFormula_Valid = isValid(line);
    if(!isFormula_Valid){
        fprintf(stderr, "formula co char dac biet va *, \\ chua ho tro");
        free(line);
    }

    int result = getResult(line);

    printf("%d\n", result);
    
    return EXIT_SUCCESS;
}
