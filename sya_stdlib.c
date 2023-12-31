#include "main.h"

/**
 * sya_get_len - Get the length of a number.
 * @n: Type int number.
 * Return: Length of a number.
 */
int sya_get_len(int n)
{
    unsigned int n1;
    int length = 1;

    if (n < 0)
    {
        length++;
        n1 = n * -1;
    }
    else
    {
        n1 = n;
    }
    while (n1 > 9)
    {
        length++;
        n1 = n1 / 10;
    }

    return (length);
}

/**
 * sya_itoa - Function converts int to string.
 * @n: Type int number.
 * Return: String.
 */
char *sya_itoa(int n)
{
    unsigned int n1;
    int length = sya_get_len(n);
    char *buffer;

    buffer = malloc(sizeof(char) * (length + 1));
    if (buffer == 0)
        return (NULL);

    *(buffer + length) = '\0';

    if (n < 0)
    {
        n1 = n * -1;
        buffer[0] = '-';
    }
    else
    {
        n1 = n;
    }

    length--;
    do
    {
        *(buffer + length) = (n1 % 10) + '0';
        n1 = n1 / 10;
        length--;
    } while (n1 > 0);

    return (buffer);
}

/**
 * sya_atoi - Converts a string to an integer.
 * @s: Input string.
 * Return: Integer.
 */
int sya_atoi(char *s)
{
    unsigned int count = 0, size = 0, result = 0, sign = 1, multiplier = 1, i;

    while (*(s + count) != '\0')
    {
        if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
            break;

        if (*(s + count) == '-')
            sign *= -1;

        if ((*(s + count) >= '0') && (*(s + count) <= '9'))
        {
            if (size > 0)
                multiplier *= 10;
            size++;
        }
        count++;
    }

    for (i = count - size; i < count; i++)
    {
        result = result + ((*(s + i) - '0') * multiplier);
        multiplier /= 10;
    }
    return (result * sign);
}

