#include <stdio.h>
#include <string.h>

void string();
void stringCopy();
void stringConcatenate();
void stringConcatenate();
void stringLength();
void stringSubstring();
void stringToken();

int main()
{
    printf("---- a string ----\n");
    string();

    printf("---- Copy a String ----\n");
    stringCopy();

    printf("---- Concatenate a String ----\n");
    stringConcatenate();

    printf("---- Length of a String ----\n");
    stringLength();

    printf("---- Substring ----\n");
    stringSubstring();

    printf("---- String Token ----\n");
    stringToken();

    return 0;
}

void string()
{
    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    printf("Greeting message: %s\n", greeting);
}

void stringCopy()
{
    char str1[12] = "Hello";
    char str3[12];

    /* Copy str1 into str3 */
    //in strcpy(this is what recieves the copy, this gets the copy)
    strcpy(str3, str1);
    printf("strcpy ( str3, str1 ) : %s\n", str3 );
}

void stringConcatenate()
{
    char str1[12] = "Hello";
    char str2[12] = "World";

    /* Concatenates str1 an str2 */
    // str1 will hold the contents of str1 and str2
    strcat(str1, str2);
    printf("strcat(str1, str2): %s\n", str1);
}

void stringLength() 
{
    char str1[12] = "Hello";
    int len;

    /* total length of str1 after concatenation */
    len = strlen(str1);
    printf("strlen(str1) : %d\n", len);
}

void stringSubstring()
{
    char str[] = "This is a sample string";
    printf("%s\n", str);

    char * pch;
    pch = strstr (str, "sample");
    //FIXME what is the difference between strcpy and strncpy?
    if (pch != NULL) {
    strncpy (pch, "simple", 6);
    }

    printf("str updated to \n%s\n", str);
}

void stringToken()
{
    char str[] = "- This, a sample string.";
    char * pch;
    printf("Splitting string \"%s\" into tokens:\n", str);
    pch = strtok (str, " ,.-");

    while (pch != NULL) 
    {
        printf ("%s\n", pch);
        pch = strtok (NULL, " ,.-");
    }
}



