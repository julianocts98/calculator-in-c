#ifndef TESTS_H
#define TESTS_H
int compareString(char *stringA, char *stringB);
void checkStringArrayTestAndPrintResult(char *testName, char actual[3][100], char expected[3][100]);
void checkStringTestAndPrintResult(char *testName, char *actual, char *expected);
void checkIntTestAndPrintResult(char *testName, int actual, int expected);
double dabs(double a, double b);
int compareDoubleValues(double a, double b, double epsilon);
void checkDoubleTestAndPrintResult(char *testName, double actual, double expected);
void testCaseGetNumberByString(char *testName, char *string, int expected);
void testGetNumberByString();
void testCaseGetDigitByChar(char *testName, char numChar, int expected);
void testGetDigitByChar();
void testCasePower(char *testName, int base, int expoent, int expected);
void testPower();
void testCaseGetTypeOfChar(char *testName, char token, int expected);
void testGetTypeOfChar();
void testCaseGetStringLength(char *testName, char *string, int expected);
void testGetStringLength();
void testCaseGetOperationResultByParsedExpression(char *testName, char parsedExpression[][100], double expected);
void testGetOperationResultByParsedExpression();
void testCaseGetParsedExpression(char *testName, char *expression, char expected[3][100]);
void testGetParsedExpression();
void testCaseGetSubstringByIndex(char *testName, char *expression, int firstIndex, int secondIndex, char *expected);
void testGetSubstringByIndex();
void testSuite();
#endif