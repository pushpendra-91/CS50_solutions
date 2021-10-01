#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
bool check_key(string s); //function prototype to validate key

int main(int argc, string argv[]) //command line arguments
{
    if (argc != 2 || !check_key(argv[1]))
    {
        printf("Usage: ./caesar key\n ");
        return 1;
    }
    int key = atoi(argv[1]); //coverts string to integer value

    string plane_txt = get_string("Plane Text: ");
    printf("ciphertext: ");

    for (int i = 0, len = strlen(plane_txt); i < len; i++)
    {
        char c = plane_txt[i];
        if (isalpha(c))
        {
            char m = 'A';
            if (islower(c))
            {
                m = 'a';
                printf("%c", (c - m + key) % 26 + m); //encrypt the text(lowercase letters)
            }
            else
            {
                printf("%c", (c - m + key) % 26 + m); //encrypt the text(uppercase letters)
            }
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}

//checks the key is valid or not
bool check_key(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i])) //checks for key contains integer only
        {
            return false;
        }
    }
    return true;
}
