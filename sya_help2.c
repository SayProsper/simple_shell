#include "main.h"

/**
 * sya_help - Display help information for the built-in help.
 * Return: No return
 */
void sya_help(void)
{
    char *help = "help: help [-dms] [pattern ...]\n";

    write(STDOUT_FILENO, help, _strlen(help));
    help = "\tDisplay information about builtin commands.\n ";
    write(STDOUT_FILENO, help, _strlen(help));
    help = "Displays brief summaries of builtin commands.\n";
    write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * sya_help_alias - Display help information for the built-in alias.
 * Return: No return
 */
void sya_help_alias(void)
{
    char *help = "alias: alias [-p] [name[=value]...]\n";

    write(STDOUT_FILENO, help, _strlen(help));
    help = "\tDefine or display aliases.\n ";
    write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * sya_help_cd - Display help information for the built-in cd.
 * Return: No return
 */
void sya_help_cd(void)
{
    char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

    write(STDOUT_FILENO, help, _strlen(help));
    help = "\tChange the shell working directory.\n ";
    write(STDOUT_FILENO, help, _strlen(help));
}

