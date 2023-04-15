Simple Shell
Introduction
This repository is a alx School Project. The school project consisted in writing a shell like sh (Bourne Shell) by Stephen Bourne , in C, using a limited number of standard library functions.

The goal in this project was to make us understand how a shell works. To single out some items: what is the environment, the difference between functions and system calls, how to create processes using execve...

Usage
In order to run this program,

Clone This Repo

git clone https://github.com/Lpharome/simple_shell

compile it with

gcc 4.8.4 -Wall -Werror -Wextra -pedantic *.c -o sh.
You can then run it by invoking ./sh in that same directory.

How to use it
In order to use this shell, in a terminal, first run the program:
prompt$ ./s
which will wait to take user input command
$ 
A command will be of the type $ command
This shell can handle two types of commands: builtins and normal program.

List of built-ins
Currently the list of built-ins are:

cd [directory]
Switch to the specified directory (path).
env
Displays the environment variable
exit [exitstatus]
Exit from the program with exitstatus value. 0 by default.
getenv NAME
Return the value of the NAME variable if it is in the environment
help [command]
Displays the syntax for the command, or all commands.
history
Displays the last typed user .
echo [$$] or [$?] or [$PATH] Return pid and exit statue and PATH.
Command
Basicly Every Program in $PATH It Support Single Word like ls

It Handle Path ls /tmp

it Handle Options Like ls -l

it Handle All Three Togther Like ls -l /var 

it Handle Command Path Also Like /bin/ls And All The Option And Path Like /bin/ls -l /var

it Handle Comments # 