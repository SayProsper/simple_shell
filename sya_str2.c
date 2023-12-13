#include "main.h"

/**
 * sya_strdup - Duplicates a string in heap memory.
 * @s: Char pointer to the string.
 * Return: Duplicated string.
 */
char *sya_strdup(const char *s)
{
    char *new;
    size_t len;

    len = sya_strlen(s);
    new = malloc(sizeof(char) * (len + 1));
    if (new == NULL)
        return (NULL);
    sya_memcpy(new, s, len + 1);
    return (new);
}

/**
 * sya_strlen - Returns the length of a string.
 * @s: Char pointer to the string.
 * Return: Length of the string.
 */
int sya_strlen(const char *s)
{
    int len;

    for (len = 0; s[len] != 0; len++)
    {
    }
    return len;
}

/**
 * sya_cmp_chars - Compare characters of strings.
 * @str: Input string.
 * @delim: Delimiter.
 * Return: 1 if equal, 0 if not.
 */
int sya_cmp_chars(char str[], const char *delim)
{
    unsigned int i, j, k;

    for (i = 0, k = 0; str[i]; i++)
    {
        for (j = 0; delim[j]; j++)
        {
            if (str[i] == delim[j])
            {
                k++;
                break;
            }
        }
    }
    if (i == k)
        return 1;
    return 0;
}

/**
 * sya_strtok - Splits a string by some delimiter.
 * @str: Input string.
 * @delim: Delimiter.
 * Return: Splitted string.
 */
char *sya_strtok(char str[], const char *delim)
{
    static char *splitted, *str_end;
    char *str_start;
    unsigned int i, bool;

    if (str != NULL)
    {
        if (sya_cmp_chars(str, delim))
            return NULL;
        splitted = str;        /* Store first address */
        i = sya_strlen(str);
        str_end = &str[i]; /* Store last address */
    }
    str_start = splitted;
    if (str_start == str_end) /* Reaching the end */
        return NULL;

    for (bool = 0; *splitted; splitted++)
    {
        /* Breaking loop finding the next token */
        if (splitted != str_start)
            if (*splitted && *(splitted - 1) == '\0')
                break;
        /* Replacing delimiter for null char */
        for (i = 0; delim[i]; i++)
        {
            if (*splitted == delim[i])
            {
                *splitted = '\0';
                if (splitted == str_start)
                    str_start++;
                break;
            }
        }
        if (bool == 0 && *splitted) /* Str != Delim */
            bool = 1;
    }
    if (bool == 0) /* Str == Delim */
        return NULL;
    return str_start;
}

/**
 * sya_isdigit - Defines if a string is a number.
 * @s: Input string.
 * Return: 1 if the string is a number, 0 otherwise.
 */
int sya_isdigit(const char *s)
{
    unsigned int i;

    for (i = 0; s[i]; i++)
    {
        if (s[i] < 48 || s[i] > 57)
            return 0;
    }
    return 1;
}

