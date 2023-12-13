#include "main.h"

/**
 * sya_strcat - Concatenate two strings.
 * @dest: Char pointer to the destination of the copied string.
 * @src: Const char pointer to the source string.
 * Return: The destination string.
 */
char *sya_strcat(char *dest, const char *src)
{
    int i;
    int j;

    for (i = 0; dest[i] != '\0'; i++)
        ;

    for (j = 0; src[j] != '\0'; j++)
    {
        dest[i] = src[j];
        i++;
    }

    dest[i] = '\0';
    return dest;
}

/**
 * sya_strcpy - Copies the string pointed to by src.
 * @dest: Char pointer to the destination of the copied string.
 * @src: Char pointer to the source string.
 * Return: The destination string.
 */
char *sya_strcpy(char *dest, char *src)
{
    size_t a;

    for (a = 0; src[a] != '\0'; a++)
    {
        dest[a] = src[a];
    }
    dest[a] = '\0';

    return dest;
}

/**
 * sya_strcmp - Compares two strings.
 * @s1: String to be compared.
 * @s2: String to be compared.
 * Return: If s1 > s2, returns 1. If s1 < s2, returns -1. If equal, returns 0.
 */
int sya_strcmp(char *s1, char *s2)
{
    int i;

    for (i = 0; s1[i] == s2[i] && s1[i]; i++)
        ;

    if (s1[i] > s2[i])
        return 1;
    if (s1[i] < s2[i])
        return -1;
    return 0;
}

/**
 * sya_strchr - Locates a character in a string.
 * @s: String.
 * @c: Character.
 * Return: Pointer to the first occurrence of the character c.
 */
char *sya_strchr(char *s, char c)
{
    unsigned int i = 0;

    for (; *(s + i) != '\0'; i++)
        if (*(s + i) == c)
            return (s + i);
    if (*(s + i) == c)
        return (s + i);
    return ('\0');
}

/**
 * sya_strspn - Gets the length of a prefix substring.
 * @s: Initial segment.
 * @accept: Accepted bytes.
 * Return: The number of accepted bytes.
 */
int sya_strspn(char *s, char *accept)
{
    int i, j, bool;

    for (i = 0; *(s + i) != '\0'; i++)
    {
        bool = 1;
        for (j = 0; *(accept + j) != '\0'; j++)
        {
            if (*(s + i) == *(accept + j))
            {
                bool = 0;
                break;
            }
        }
        if (bool == 1)
            break;
    }
    return i;
}

