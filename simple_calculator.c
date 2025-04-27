#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getAccumulator(int *accumulator, int number, char operator){
  switch(operator){
  case 43: /* add */
    *accumulator += number;
    break;
  case 45: /*subtract*/
    *accumulator -= number;
    break;
  case 42: /*multi*/
    *accumulator *= number;
    break;
  case 47: /*div*/
    *accumulator /= number;
    break;
  }
}

void getResult(const char *line){
  
  int accumulator = 0; /*luu ket qua sau khi xu ly*/
  char operator = '+'; /*toan tu*/
  int isInt_Exist = 0;
  int number = 0;
  
  for(size_t i = 0; i < strlen(line); i++){
    /*co dau = thi dung*/
    if(line[i] == '='){
      break;
    }
    /*kiem so*/
    if(atol(&line[i]) > 0){
      number = atol(&line[i]);
      isInt_Exist = 1;
    }
    /*kiem operator*/
    if(line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/'){
      operator = line[i];
    }

    if(isInt_Exist && operator){
      getAccumulator(&accumulator, number, operator);
      isInt_Exist = 0;
      operator = '\0';
    }
  }

  printf("%d \n", accumulator);
  
}

int main(){

  char *line = NULL;
  size_t len;
  ssize_t read;

  /*nhap*/
  read = getline(&line, &len, stdin);

  /*da nhan str an toan?*/
  if(read < 1){
    fprintf(stderr, "Read ko doc dc?");
    free(line);
    return EXIT_FAILURE;
  }

  line[strcspn(line, "\n")] = 0;

  getResult(line);
  
  free(line);
  
  return EXIT_SUCCESS;
}
