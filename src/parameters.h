#ifndef PARAMETERS_H
#define PARAMETERS_H

/**
 * Prints an error message indicating that the number of parameters given is incorrect.
 *
 * @param numg The number of arguments given to the program.
 */
void nError(const int numg);

/**
 * Prints an error message indicating that the parameters provided were incorrect or in the wrong order.
 */
void pError(void);

/**
 * Prints an error message indicating that a value provided after a parameter is incorrect.
 *
 * @param value The value given after a parameter.
 * @param parameter The parameter itself.
 */
void vError(const char* value, const char* parameter);

/**
 * Checks if two arguments are the same.
 *
 * @param param1 A user-given parameter.
 * @param param2 A string to compare.
 * @return Returns 1 if the strings are equal, 0 otherwise.
 */
int equals(const char* param1, const char* param2);

#endif // !PARAMETERS_H
