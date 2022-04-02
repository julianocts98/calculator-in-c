#include <stdio.h>
#include "main.h"

int compareString(char *stringA, char *stringB){
    int stringLength = getStringLength(stringA) == getStringLength(stringB) ? getStringLength(stringA) : -1;
    if (stringLength == -1) return 0;

    int equalChars = 0;
    for (int i = 0; i < stringLength; i++){
        if (stringA[i] == stringB[i]) equalChars++;
    }
    return (equalChars == stringLength);
}

void checkStringArrayTestAndPrintResult(char *testName, char actual[3][100], char expected[3][100]){
    int hasDifferentElement = 0;
    for(int i = 0; i < 3; i++){
        hasDifferentElement = (!compareString(actual[i], expected[i])) ? 1 : hasDifferentElement;
    }

    if (!hasDifferentElement){
        printf("[PASS] %s\n", testName);
    }else{
        printf("[FAIL] %s\n", testName);
        printf("EXPECTED: %s%s%s\n", expected[0],expected[1],expected[2]);
        printf(" ACTUAL : %s%s%s\n", actual[0], actual[1], actual[2]);
    }
}

void checkStringTestAndPrintResult(char *testName, char *actual, char *expected){
    if (compareString(actual, expected)){
        printf("[PASS] %s\n", testName);
    }else{
        printf("[FAIL] %s\n", testName);
        printf("EXPECTED: %s\n", expected);
        printf(" ACTUAL : %s\n", actual);
    }
}

void checkIntTestAndPrintResult(char *testName, int actual, int expected){
    if (actual == expected){
        printf("[PASS] %s\n", testName);
    }else{
        printf("[FAIL] %s\n", testName);
        printf("EXPECTED: %i\n", expected);
        printf(" ACTUAL : %i\n", actual);
    }
}

/*******************************************************************************
 * Returns absolute difference between two double values.
 ******************************************************************************/
double dabs(double a, double b){
    return (b > a) ? b-a : a-b;
}
/*******************************************************************************
 * Compares if two double or floating numbers are equal, taking an uncertainty
 * `epsilon` in account.
 ******************************************************************************/
int compareDoubleValues(double a, double b, double epsilon){
    return (dabs(a,b) < epsilon);
}

void checkDoubleTestAndPrintResult(char *testName, double actual, double expected){
    if (compareDoubleValues(actual, expected, 0.1f)){
        printf("[PASS] %s\n", testName);
    }else{
        printf("[FAIL] %s\n", testName);
        printf("EXPECTED: %0.2f\n", expected);
        printf(" ACTUAL : %0.2f\n", actual);
    }
}

void testCaseGetNumberByString(char *testName, char *string, int expected){
    int actual = getNumberByString(string);
    checkIntTestAndPrintResult(testName, actual, expected);
}

void testGetNumberByString(){
    printf("%s\n", __func__);
    testCaseGetNumberByString("\"150\" is 150", "150",150);
    testCaseGetNumberByString("\"951516512\" is 951516512", "951516512", 951516512);
    testCaseGetNumberByString("\"0\" is 0", "0", 0);
    testCaseGetNumberByString("\"abcde\" is -1", "abcde", -1);
}

void testCaseGetDigitByChar(char *testName, char numChar, int expected){
    int actual = getDigitByChar(numChar);
    checkIntTestAndPrintResult(testName, actual, expected);
}

void testGetDigitByChar(){
    printf("%s\n", __func__);
    testCaseGetDigitByChar("\"0\" is 0", '0', 0);
    testCaseGetDigitByChar("\"5\" is 5", '5', 5);
    testCaseGetDigitByChar("\"9\" is 9", '9', 9);
    testCaseGetDigitByChar("\"a\" is -1", 'a', -1);
    printf("--------------------------------------\n");
}

void testCasePower(char *testName, int base, int expoent, int expected){
    int actual = power(base, expoent);
    checkIntTestAndPrintResult(testName, actual, expected);
}

void testPower(){
    printf("%s\n", __func__);
    testCasePower("10 power 2 is 100", 10, 2, 100);
    testCasePower("10 power 0 is 1", 10, 0, 1);
    testCasePower("2 power 5 is 32", 2, 5, 32);
    testCasePower("11111 power 2 is 123454321", 11111, 2, 123454321);
    printf("--------------------------------------\n");
}

void testCaseGetTypeOfChar(char *testName, char token, int expected){
    int actual = getTypeOfChar(token);
    checkIntTestAndPrintResult(testName, actual, expected);
}

void testGetTypeOfChar(){
    printf("%s\n", __func__);
    testCaseGetTypeOfChar("'a' is INVALID", 'a', INVALID);
    testCaseGetTypeOfChar("' ' is INVALID", ' ', INVALID);
    testCaseGetTypeOfChar("'1' is VALUE", '1', VALUE);
    testCaseGetTypeOfChar("'0' is VALUE", '0', VALUE);
    testCaseGetTypeOfChar("'-' is OPERATOR", '-', OPERATOR);
    testCaseGetTypeOfChar("'*' is OPERATOR", '*', OPERATOR);
    testCaseGetTypeOfChar("'+' is OPERATOR", '+', OPERATOR);
    printf("--------------------------------------\n");
}

void testCaseGetStringLength(char *testName, char *string, int expected){
    int actual = getStringLength(string);
    checkIntTestAndPrintResult(testName, actual, expected);
}

void testGetStringLength(){
    printf("%s\n", __func__);
    testCaseGetStringLength("\"123456\" has length 6", "123456", 6);
    testCaseGetStringLength("\"\" has length 0", "", 0);
    testCaseGetStringLength("\"Juliano\" has length 7", "Juliano", 7);
    testCaseGetStringLength("\"155+13-12\" has length 9", "155+13-12", 9);
    printf("--------------------------------------\n");
}

void testCaseGetOperationResultByParsedExpression(char *testName, char parsedExpression[][100], double expected){
    float actual = getOperationResultByParsedExpression(parsedExpression);
    checkDoubleTestAndPrintResult(testName, actual, expected);
}

void testGetOperationResultByParsedExpression(){
    printf("%s\n", __func__);
    testCaseGetOperationResultByParsedExpression("[\"5\",\"+\",\"6\"] is 11.00",(char[3][100]){"5","+","6"}, 11.00);
    testCaseGetOperationResultByParsedExpression("[\"100\",\"*\",\"2\"] is 200.00",(char[3][100]){"100","*","2"}, 200.00);
    testCaseGetOperationResultByParsedExpression("[\"100\",\"/\",\"2\"] is 50.00",(char[3][100]){"100","/","2"}, 50.00);
    testCaseGetOperationResultByParsedExpression("[\"11111\",\"*\",\"11111\"] is 123454321.00",(char[3][100]){"11111","*","11111"}, 123454321.00);
    testCaseGetOperationResultByParsedExpression("[\"111111\",\"*\",\"111111\"] is 12345654321.00",(char[3][100]){"111111","*","111111"}, 12345654321.00);
    printf("--------------------------------------\n");
}

void testCaseGetParsedExpression(char *testName, char *expression, char expected[3][100]){
    char actual[3][100];
    getParsedExpression(expression, actual);
    checkStringArrayTestAndPrintResult(testName, actual, expected);
}

void testGetParsedExpression(){
    printf("%s\n", __func__);
    testCaseGetParsedExpression("\"150+1\" is [\"150\",\"+\",\"1\"]", "150+1", (char[3][100]){"150","+","1"});
    testCaseGetParsedExpression("\"111   +1\" is [\"111\",\"+\",\"1\"]", "111   +1", (char[3][100]){"111","+","1"});
    testCaseGetParsedExpression("\"9584*45\" is [\"9584\",\"*\",\"45\"]", "9584*45", (char[3][100]){"9584","*","45"});
    testCaseGetParsedExpression("\"256 / 3\" is [\"256\",\"/\",\"3\"]", "256 / 3", (char[3][100]){"256","/","3"});
    //testCaseGetParsedExpression for empty string
    printf("--------------------------------------\n");
}

void testCaseGetSubstringByIndex(char *testName, char *expression, int firstIndex, int secondIndex, char *expected){
    char actual[100];
    getSubstringByIndex(expression, actual, firstIndex, secondIndex);
    checkStringTestAndPrintResult(testName, actual, expected);
}

void testGetSubstringByIndex(){
    printf("%s\n", __func__);
    testCaseGetSubstringByIndex("\"Juliano\" from index 2 to 5 is \"lian\"", "Juliano", 2, 5, "lian");
    testCaseGetSubstringByIndex("\"150+3\" from index 0 to 2 is \"150\"", "150+3", 0, 2, "150");
    testCaseGetSubstringByIndex("\"8564* 400\" from index 6 to 8 is \"400\"", "8564* 400", 6, 8, "400");
    testCaseGetSubstringByIndex("\"751*8\" from index 3 to 3 is \"*\"", "751*8", 3, 3, "*");
    printf("--------------------------------------\n");
}

void testSuite(){
    testGetNumberByString();
    testGetDigitByChar();
    testPower();
    testGetTypeOfChar();
    testGetStringLength();
    testGetOperationResultByParsedExpression();
    testGetParsedExpression();
    testGetSubstringByIndex();
}