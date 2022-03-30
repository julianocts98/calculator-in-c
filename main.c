#include "main.h"
#include "tests.h"

//11111*11111 why doesn't it work
int main(int argc, char *argv[]){
    if (argc == 2){
        if (compareString(argv[1], "-t")){
            testSuite();
            return 0;
        }
        char parsedExpression[3][100];
        getParsedExpression(argv[1], parsedExpression);
        printf("Result: %0.2f", getOperationResultByParsedExpression(parsedExpression));
    } else if(argc > 2){
        printf("More than one argument was passed.\nProgram end.");
    } else{
        printf("No argument passed.\nProgram end.");
    }
    return 0;
}

//REFACTOR
//try to work with conditions and arithmetics dealing with char : '1' - '0' = 49 - 48 = 1;
int getDigitByChar(char numChar){
    return ((int)numChar >= 48 && (int)numChar <=57) ? (int)numChar-48 : -1;
}

//REFACTOR
//returns int but the return is never used
int getParsedExpression(char *expression, char parsedExpression[][100]){
    int startingIdx = -1;
    int endingIdx = -1;
    int expressionLength = getStringLength(expression);
    int parsedExpressionIdx = 0;

    for (int i = 0; i < expressionLength; i++){
        char actualChar = expression[i];
        int typeOfActualChar = getTypeOfChar(actualChar);
        char nextChar = expression[i+1];
        int typeOfNextChar = getTypeOfChar(nextChar);

        //TODO check what happens if more than 3 tokens in arguments of the expression
        if(startingIdx == -1 && typeOfActualChar != INVALID){
            startingIdx = i;
            if(typeOfNextChar != typeOfActualChar){
                endingIdx = i;
                getSubstringByIndex(expression, parsedExpression[parsedExpressionIdx], startingIdx, endingIdx);
                parsedExpressionIdx++;
                startingIdx = -1;
                endingIdx = -1;
            }
        }else if(startingIdx != -1 && typeOfNextChar != typeOfActualChar){
            endingIdx = i;
            getSubstringByIndex(expression, parsedExpression[parsedExpressionIdx], startingIdx, endingIdx);
            parsedExpressionIdx++;
            startingIdx = -1;
            endingIdx = -1;
        }
    }
    return 0;
}

void getSubstringByIndex(char *expression, char *substring, int firstIndex, int secondIndex){
    int substringIdx = 0;

    for (int i = firstIndex; i <= secondIndex; i++){
        substring[substringIdx] = expression[i];
        substringIdx++;
    }
    substring[substringIdx] = '\0';
}

int getTypeOfChar(char expressionChar){
    char ACCEPTED_VALUES[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};
    char ACCEPTED_OPERATORS[] = {'+','-','*','/'};

    for(int i = 0; i < sizeof(ACCEPTED_OPERATORS); i++){
        if (expressionChar == ACCEPTED_OPERATORS[i]){
            return OPERATOR;
        }
    }
    for(int i = 0; i < sizeof(ACCEPTED_VALUES); i++){
        if (expressionChar == ACCEPTED_VALUES[i]){
            return VALUE;
        }
    }
    return INVALID;
}

int getStringLength(char *p){
    int count = 0;
    while (*p != '\0'){
        count++;
        p++;
    }
    return count;
}

int power(int base, int expoent){
    if (expoent != 0){
        return (base * power(base, expoent-1));
    }else{
        return 1;
    }
}

//REFACTOR
int getNumberByString(char *string){
    int number = 0;
    int length = getStringLength(string);
    int result = 0;

    for (int i = 0, expoent = length-1; i < length; i++, expoent--){
        result += getDigitByChar(string[i]) * power(10,expoent);
    }
    return result;
}

//study for 11111*11111;
float getOperationResultByParsedExpression(char parsedExpression[][100]){
    int firstValue = getNumberByString(parsedExpression[0]);
    char operand = parsedExpression[1][0];
    int secondValue = getNumberByString(parsedExpression[2]);

    switch (operand){
        case '+':
            return firstValue + secondValue;
        case '-':
            return firstValue - secondValue;
        case '*':
            return firstValue * secondValue;
        case '/':
            return firstValue / secondValue;
    }
}