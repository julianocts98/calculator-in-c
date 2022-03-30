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
 * It uses an loop that in each iteration recognizes if it found a valid
 * character, if so, it sets its index as an starting index and keeps verifying
 *  for each iteration if the current char of the expression is  from the same
 * category as the next char and if so, it keeps iterating until reaching a
 * point where the next char of the iteration is from a different category of
 * the actual char, thus assigning the ending index for getting a substring.
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
int getNumberByString(char *string);
#endif //MAIN_H

