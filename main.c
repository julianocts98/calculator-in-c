#include <stdio.h>
enum Type {INVALID = 0, OPERATOR = 1, VALUE = 2};

/*******************************************************************************
 * Returns a power operation from a a `base` and an `expoent`.                                                   
 ******************************************************************************/
int power(int base, int expoent);
int isValidChar(char args);
/******************************************************************************* 
 * Returns an int enum that represents whether the received token is a VALUE, an
 * OPERATOR or an INVALID token, such as a letter or a whitespace.                                                    
 ******************************************************************************/
int getTypeOfChar(char args);
/*******************************************************************************
 * Receives a char, veriify if its within the range of the numerical values from
 * 0-9 in ASCII, and returns an integer of the numerical decimal digit.           
 ******************************************************************************/
int getDigitByChar(char numChar);
/*******************************************************************************
 * Receives a string and return its length. Null character '\0' is not taken in
 * account.                       
 ******************************************************************************/
int getStringLength(char *p);
/******************************************************************************* 
 * Receives a string to be parsed into numerical values and operator. Each 
 * element parsed is used to populate the `parsedExpression` array.
 *                                                                   
 * It uses an loop that in each iteration verifies if the char of index i is in
 * the same category as the char of the index i+1 if so, it keeps going until 
 * reaching a point where the char of the i+1 index is from a different category
 * of the char of index i, thus assigning the ending index for getting an 
 * substring.         
 ******************************************************************************/
int getParsedExpression(char *expression, char parsedExpression[][100]);
/*******************************************************************************
 * It receives an expression and slice it from the `firstIndex` up to the 
 * `secondIndex` received as arguments. It stores the result in the `substring`.    
 ******************************************************************************/
void getSubstringByIndex(char *expression, char *substring, int firstIndex, int secondIndex);
/*******************************************************************************
 * Takes the parsed expression, extract each of its components and then execute
 * the operation returning its result.    
 ******************************************************************************/
float getOperationResultByParsedExpression(char parsedExpression[][100]);
/*******************************************************************************
 * Receives a string that represents a natural number and returns it as a int by
 * representing it in a decimal base.          
 ******************************************************************************/
int getNumberByString(char string[]);

//11111*11111 why doesn't it work
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
    int startingIdx = -1;
    int endingIdx = -1;
    int expressionLength = getStringLength(expression);
    int parsedExpressionIdx = 0;

    for (int i = 0; i < expressionLength; i++)
    {
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

void getSubstringByIndex(char *expression, char *substring, int firstIndex, int secondIndex)
{

    int substringIdx = 0;

    for (int i = firstIndex; i <= secondIndex; i++)
    {
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

    //NO LONGER USED FUNCTION
    char ACCEPTED_CHARS[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};
    int isValidChar = 0;
    for (int i = 0; i < sizeof(ACCEPTED_CHARS); i++)
    {
        if (expressionChar == ACCEPTED_CHARS[i])
        {
            isValidChar = 1;
        }
    }
    return isValidChar;
}

int getStringLength(char *p)
{
    int count = 0;
    while (*p != '\0')
    {
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
int getNumberByString(char string[]){
    int number = 0;
    int length = getStringLength(string);
    int result = 0;
    
    for (int i = 0, expoent = length-1 ; i < length; i++, expoent--){
        result += getDigitByChar(string[i]) * power(10,expoent); 
    }
    
    return result;
}

//study for 11111*11111;
float getOperationResultByParsedExpression(char parsedExpression[][100]){
    int firstValue = getNumberByString(parsedExpression[0]);
    char operand = parsedExpression[1][0];
    int secondValue = getNumberByString(parsedExpression[2]);

    switch (operand)
    {
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