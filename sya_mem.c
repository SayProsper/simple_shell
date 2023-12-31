#include "main.h"

/**
 * sya_memcpy - Copies information between void pointers.
 * @newptr: Destination pointer.
 * @ptr: Source pointer.
 * @size: Size of the new pointer.
 *
 * Return: No return.
 */
void sya_memcpy(void *newptr, const void *ptr, unsigned int size)
{
    char *char_ptr = (char *)ptr;
    char *char_newptr = (char *)newptr;
    unsigned int i;

    for (i = 0; i < size; i++)
        char_newptr[i] = char_ptr[i];
}

/**
 * sya_realloc - Reallocates a memory block.
 * @ptr: Pointer to the memory previously allocated.
 * @old_size: Size, in bytes, of the allocated space of ptr.
 * @new_size: New size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * If new_size == old_size, returns ptr without changes.
 * If malloc fails, returns NULL.
 */
void *sya_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    void *newptr;

    if (ptr == NULL)
        return (malloc(new_size));

    if (new_size == 0)
    {
        free(ptr);
        return (NULL);
    }

    if (new_size == old_size)
        return (ptr);

    newptr = malloc(new_size);
    if (newptr == NULL)
        return (NULL);

    if (new_size < old_size)
        sya_memcpy(newptr, ptr, new_size);
    else
        sya_memcpy(newptr, ptr, old_size);

    free(ptr);
    return (newptr);
}

/**
 * sya_reallocdp - Reallocates a memory block of a double pointer.
 * @ptr: Double pointer to the memory previously allocated.
 * @old_size: Size, in bytes, of the allocated space of ptr.
 * @new_size: New size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * If new_size == old_size, returns ptr without changes.
 * If malloc fails, returns NULL.
 */
char **sya_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
    char **newptr;
    unsigned int i;

    if (ptr == NULL)
        return (malloc(sizeof(char *) * new_size));

    if (new_size == old_size)
        return (ptr);

    newptr = malloc(sizeof(char *) * new_size);
    if (newptr == NULL)
        return (NULL);

    for (i = 0; i < old_size; i++)
        newptr[i] = ptr[i];

    free(ptr);

    return (newptr);
}

