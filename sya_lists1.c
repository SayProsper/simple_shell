#include "main.h"

/**
 * sya_add_sep_node_end - Adds a separator found at the end
 * of a sep_list.
 * @head: Head of the linked list.
 * @sep: Separator found (; | &).
 * Return: Address of the head.
 */
sep_list *sya_add_sep_node_end(sep_list **head, char sep)
{
    sep_list *new, *temp;

    new = malloc(sizeof(sep_list));
    if (new == NULL)
        return (NULL);

    new->separator = sep;
    new->next = NULL;
    temp = *head;

    if (temp == NULL)
    {
        *head = new;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }

    return (*head);
}

/**
 * sya_free_sep_list - Frees a sep_list.
 * @head: Head of the linked list.
 * Return: No return.
 */
void sya_free_sep_list(sep_list **head)
{
    sep_list *temp;
    sep_list *curr;

    if (head != NULL)
    {
        curr = *head;
        while ((temp = curr) != NULL)
        {
            curr = curr->next;
            free(temp);
        }
        *head = NULL;
    }
}

/**
 * sya_add_line_node_end - Adds a command line at the end
 * of a line_list.
 * @head: Head of the linked list.
 * @line: Command line.
 * Return: Address of the head.
 */
line_list *sya_add_line_node_end(line_list **head, char *line)
{
    line_list *new, *temp;

    new = malloc(sizeof(line_list));
    if (new == NULL)
        return (NULL);

    new->line = line;
    new->next = NULL;
    temp = *head;

    if (temp == NULL)
    {
        *head = new;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }

    return (*head);
}

/**
 * sya_free_line_list - Frees a line_list.
 * @head: Head of the linked list.
 * Return: No return.
 */
void sya_free_line_list(line_list **head)
{
    line_list *temp;
    line_list *curr;

    if (head != NULL)
    {
        curr = *head;
        while ((temp = curr) != NULL)
        {
            curr = curr->next;
            free(temp);
        }
        *head = NULL;
    }
}

