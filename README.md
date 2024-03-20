# 42 pipex
*2022 - grade : 125/100*

The goal of this project is to implement bash pipes:
`./pipex file1 cmd1 cmd2 file2` behave like `< file1 cmd1 | cmd2 > file2`
Mutiple pipes: 
`$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2` behave like `< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`
here_doc:
`./pipex here_doc LIMITER cmd cmd1 file` behave like `cmd << LIMITER | cmd1 >> file`

## Tips
* use `bash -posix` command to enter the expected bash version you must mirror.
* [great stackoverflow post](https://stackoverflow.com/a/30714995) on dup2 and close functions.
* use the `valgrind --track-fds=yes` command to keep track of opened fds as the program terminates (the 3 first ones should remain open).
* the `echo$?` command gives you the last returned code from your last command, handy to test and understand bash return codes (not mandatory).

## Code
* The ```pied_piper``` function creates all the pipes needed for the program to perform at once.
* ```rror``` is a cool function pointer array ;)
* ```get_fd``` is choosing the correct fds to use, previousy opened with ```pied_piper```.
* Have fun with bash return codes to understand the ```rr_nulll``` function.
* Bonus : I upgraded the function ```get_next_line``` to take the string limiter in addition of the fd it reads from. This way everything can be cleaned properly when the limiter is read.

## New allowed functions
perror : the perror() function produces a message on standard error describing the last error encountered during a call to a system or library function.
```
void perror(const char *s);
```
strerror : the strerror() function returns a pointer to a string that describes the error code passed in the argument errnum
```
char *strerror(int errnum);
```
access : access() checks whether the calling process can access the file pathname. If pathname is a symbolic link, it is dereferenced.
```
int access(const char *pathname, int mode);
```
dup  : The  dup()  system call creates a copy of the file descriptor oldfd, using the lowest-numbered unused file descriptor for the new descriptor.
```
int dup(int oldfd);
```
dup2 : The  dup2() system call performs the same task as dup(), but instead of using the lowest-numbered unused file descriptor, it uses the file descriptor number specified in newfd.  If the file descriptor newfd was previously open, it is  silently closed before being reused.
```
int dup2(int oldfd, int newfd);
```
execve : execve() executes the program referred to by pathname. This causes the program that is currently being run by the calling process to be replaced with a new program, with newly initialized stack, heap, and (initialized and uninitialized) data segments.
```
int execve(const char *pathname, char *const argv[], char *const envp[]);
```
fork : fork() creates a new process by duplicating the calling process. The new process is referred to as the child process. The calling process is referred to as the parent process.
```
pid_t fork(void);
```
pipe : pipe() creates a pipe, a unidirectional data channel that can be used for interprocess communication.  The array pipefd is used to return two file descriptors referring to the ends of the pipe. pipefd[0] refers to the read end of the pipe. pipefd[1] refers to the write end of the pipe. Data written to the write end of the pipe is buffered by the kernel until it is read from the read end of the pipe.
```
int pipe(int pipefd[2]);
```

unlink : unlink - call the unlink function to remove the specified file

wait : await process completion

waitpid : All of these system calls are used to wait for state changes in a child of the calling process, and obtain information about the child whose state has changed.

-----------------
Good luck !
