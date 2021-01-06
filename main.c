#include "minishell.h"

int main()
{
	char *command_1[] = {"/bin/cat", "main.c", NULL};
	char *command_2[] = {"/bin/grep", "char", NULL};
	char *command_3[] = {"/bin/grep", "=", NULL};
	char *command_4[] = {"/bin/grep", "cat", NULL};

	char **cmd_pipe[] = {command_1, command_2, command_3, command_4, NULL};

	g_stdout_copy = dup(1);
	execute_cmd_pipe(cmd_pipe, -1);

	// if a = b ;
}