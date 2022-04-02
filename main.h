#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
enum Type {INVALID = 0, OPERATOR = 1, VALUE = 2};
/*******************************************************************************
 * Returns a power operation from a a `base` and an `expoent`.
 ******************************************************************************/
int power(int base, int expoent);
/*******************************************************************************
 * Returns an int enum that represents whether the received token is a VALUE, an
 * OPERATOR or an INVALID token, such as a letter or a whitespace.
 ******************************************************************************/
int getTypeOfChar(char args);
/*******************************************************************************
 * Verifies if `numchar` is within the range of numerical valuse from 0-9 in
 * ASCII returning 1 for true and 0 for false.
 ******************************************************************************/
int isValidDigit(char numChar);
/*******************************************************************************
 * Receives a char, check if it is a valid digit and then returns an integer of
 * the numerical decimal digit.
 ******************************************************************************/
int checkAndGetDigitByChar(char numChar);
/*******************************************************************************
 * Receives a string and return its length. Null character '\0' is not taken in
 * account.
 ******************************************************************************/
int getStringLength(char *p);
/*******************************************************************************
 * Receives a string to be parsed into three strings, being both the first and
 * the last of them the math terms and the middle one the operator.
 * Each element parsed is used to populate the `parsedExpression` array.
 ******************************************************************************/
void getParsedExpression(char *expression, char parsedExpression[3][100]);
/*******************************************************************************
 * Populate `indexes` with both starting and ending indexes for both math terms
 * and operator in the math `expression` string.
 *
 * It uses an loop that in each iteration recognizes if it found a valid
 * character. If so, it sets its index as an starting index and keeps verifying
 * in each iteration if the current char of the expression is from the same
 * category as the next char and keeps iterating until reaching a point where
 * the next char of the iteration is from a different category of the actual
 * char, thus assigning the ending index for that term or operator.
 ******************************************************************************/
void getTermsAndOperatorIndexes(char *expression, int indexes[3][2]);
/*******************************************************************************
 * It receives an expression and slice it from the `firstIndex` up to the
 * `secondIndex` received as arguments. It stores the result in the `substring`.
 ******************************************************************************/
void getSubstringByIndex(char *expression, char *substring, int firstIndex, int secondIndex);
/*******************************************************************************
 * Takes the parsed expression, extract each of its components and then execute
 * the math operation.
 ******************************************************************************/
double evaluateParsedExpression(char parsedExpression[3][100]);
/*******************************************************************************
 * Extracts both math terms and operator of the `parsedExpression` array and
 * uses them to return the result of the math operation.
 ******************************************************************************/
double getOperationResult(double firstValue, char operator, double secondValue);
/*******************************************************************************
 * Receives a string that represents a natural number and returns it as a int by
 * representing it in a decimal base.
 ******************************************************************************/
int getNumberByString(char *string);
/*******************************************************************************
 * Print on screen the result of the math operation expressed as a string in the
 * `expression` argument.
 ******************************************************************************/
void evaluteExpression(char *expression);
#endif //MAIN_H

