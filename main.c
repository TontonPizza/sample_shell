#include "minishell.h"

int main()
{
	char *cm_1[] = {"/bin/cat", "main.c", NULL};
	char *cm_2[] = {"/bin/grep", "if", NULL};
	char *cm_3[] = {"/bin/grep", "=", NULL};
	char *cm_4[] = {"/bin/grep", ";", NULL};
	char **cmd_pipe[] = {cm_1, cm_2, cm_3, cm_4, NULL};

	g_stdout_copy = dup(1);
	execute_cmd_pipe(cmd_pipe, -1);
}