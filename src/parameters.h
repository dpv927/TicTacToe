#pragma once

/* Prints an error message telling the user that the number of parameters 
 * given is incorrect. 
 *
 * @param numg Number of arguments given to the program.*/
void nError(const int numg);

/* Prints an error message that tells the user that a 
 * parameter/s that where given were wrong or in a incorrect order. */
void pError(void);

/* Prints a error message that tells the user that a value
 * that was given after a parameter is incorrect. 
 *
 * @param value Value given after a parameter.
 * @param parameter Self explanatory..*/
void vError(const char* value, const char* parameter);

/* Checks if two arguments are the same.
 * @param param1 User given parameter.
 * @param param2 String to compare.
 *
 * @return Returns 1 if are equals, 0 if dont.*/
int equals(const char* param1, const char* param2);
