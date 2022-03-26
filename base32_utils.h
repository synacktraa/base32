#ifndef BASE32_UTILS /* Include guard */
#define BASE32_UTILS

//Function declarations
int isLower(int ch);
int Strlen(const char* string);
int insert(char*data, int index, int element, int uSize, int tSize);
int delete(char*data, int index, int len);
void reverse(char*str);
int power(int base, int exp);
char* decToBin(int n);
int binToDec(char* bin);
char *basename(char const *path);

#endif
