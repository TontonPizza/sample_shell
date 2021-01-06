#include "minishell.h"


int 	exec_cmd(char **cmd);
int 	execute_cmd_pipe(char ***cmds, int source);

int main()
{
	char *command_1[] = {"/bin/cat", "main.c", NULL};
	char *command_2[] = {"/bin/grep", "if", NULL};
	char *command_3[] = {"/bin/grep", "==", NULL};
	char *command_4[] = {"/bin/grep", "0", NULL};

	char **cmd_pipe[] = {command_1, command_2, command_3, command_4, NULL};

	g_stdout_copy = dup(1);
	execute_cmd_pipe(cmd_pipe, -1);

	// if a = b ;
}

int 	exec_cmd(char **cmd)
{
	// replace ENV, treat redirections and stuff, look for built in...
	execve(cmd[0], cmd, 0);
	return (0);
}

int 	execute_cmd_pipe(char ***cmds, int source)
{
	pid_t		pid;
	int 		pipe_fd[2];

	if (cmds[0] == NULL && close(source) == 0)
		return 0;
	if (pipe(pipe_fd) < 0)
		return (-1);
	if (cmds[1] == NULL) // if it's the last command of the list => output = stdout
	{
		dup2(g_stdout_copy, 1);
		close(g_stdout_copy);
	}
	else
		dup2(pipe_fd[1], 1);
	dup2(source, 0);
	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == CHILD_PROCESS && close(pipe_fd[0]) == 0)
		exec_cmd(cmds[0]);
	wait(0);
	close(pipe_fd[1]);
	close(source);
	return (execute_cmd_pipe(cmds + 1, pipe_fd[0]));
}