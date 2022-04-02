#include "main.h"
#include "tests.h"

int main(int argc, char *argv[]){
    if (argc == 2){
        if (compareString(argv[1], "-t")){
            testSuite();
            return 0;
        }
        evaluteExpression(argv[1]);
    } else if(argc > 2){
        printf("More than one argument was passed.\nProgram end.");
    } else{
        printf("No argument passed.\nProgram end.");
    }
    return 0;
}

int isValidDigit(char numChar){
    return ((int)numChar >= (int)'0' && (int)numChar <= (int)'9');
}

int checkAndGetDigitByChar(char numChar){
    return isValidDigit(numChar) ? (int)numChar - (int)'0' : -1;
}

void getTermsAndOperatorIndexes(char *expression, int indexes[3][2]){
    int startingIdx = -1;
    int endingIdx = -1;
    int expressionLength = getStringLength(expression);
    int elementIdx = 0;

    for (int i = 0; i < expressionLength; i++){
        char actualChar = expression[i];
        int typeOfActualChar = getTypeOfChar(actualChar);
        char nextChar = expression[i+1];
        int typeOfNextChar = getTypeOfChar(nextChar);

        if(startingIdx == -1 && typeOfActualChar != INVALID){
            startingIdx = i;
            if(typeOfNextChar != typeOfActualChar){
                endingIdx = i;
                indexes[elementIdx][0] = startingIdx;
                indexes[elementIdx][1] = endingIdx;
                elementIdx++;
                startingIdx = -1;
                endingIdx = -1;
            }
        }else if(startingIdx != -1 && typeOfNextChar != typeOfActualChar){
            endingIdx = i;
            indexes[elementIdx][0] = startingIdx;
            indexes[elementIdx][1] = endingIdx;
            elementIdx++;
            startingIdx = -1;
            endingIdx = -1;
        }
    }
}

void getParsedExpression(char *expression, char parsedExpression[][100]){
    int indexes[3][2];
    getTermsAndOperatorIndexes(expression, indexes);
    int parsedExpressionIdx = 0;

    for(int i = 0; i < 3; i++){
        int startingIdx = indexes[i][0];
        int endingIdx = indexes[i][1];
        getSubstringByIndex(expression, parsedExpression[i], startingIdx, endingIdx);
    }
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

int getNumberByString(char *string){
    int number = 0;
    int length = getStringLength(string);
    int result = 0;

    for (int i = 0, expoent = length-1; i < length; i++, expoent--){
        int actualDigit = checkAndGetDigitByChar(string[i]);
        if (actualDigit == -1) return -1;
        result += actualDigit * power(10,expoent);
    }
    return result;
}

double getOperationResult(double firstValue, char operator, double secondValue){
    switch (operator){
        case '+':
            return firstValue + secondValue;
        case '-':
            return firstValue - secondValue;
        case '*':
            return (double)firstValue * secondValue;
        case '/':
            return (double)firstValue / secondValue;
    }
}

double evaluateParsedExpression(char parsedExpression[][100]){
    int firstValue = getNumberByString(parsedExpression[0]);
    char operator = parsedExpression[1][0];
    int secondValue = getNumberByString(parsedExpression[2]);
    return getOperationResult(firstValue, operator, secondValue);
}

void evaluteExpression(char *expression){
    char parsedExpression[3][100];
    getParsedExpression(expression, parsedExpression);
    printf("Result: %0.2f", evaluateParsedExpression(parsedExpression));
}