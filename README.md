
<p align="center">
    <img src="https://game.42sp.org.br/static/assets/achievements/minishelle.png">
</p>

<p align="center">
    <img src="https://img.shields.io/badge/OS-Linux-blue" alt="OS">
    <img src="https://img.shields.io/badge/Language-C%20%7C%20C%2B%2B-orange.svg" alt="Language">
    <img src="https://img.shields.io/badge/Grade-100%2F100-brightgreen.svg" alt="Grade">
    <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

# Minishell
The ninth project from 42<br>
Minishell is a project from 42. The goal of this project is to create a simple shell, with basic functions.

## How to use

- Clone the repository
- Run `make` to compile the project
- Run `./minishell` to start the shell

## Requirements
- Readline library
- C compiler (gcc or clang)
- Make

## What should work

- The executable must not quit unexpectedly (Segmentation fault, bus error, double free, etc).
- The executable must respond to the following signals: Ctrl-C, Ctrl-\ and Ctrl-D.
- You must show a prompt when waiting for a new command.
- The prompt must be displayed again each time a command has been executed completely.
- You must correctly handle the PATH and the environment (by copying and restoring the initial envp).
- You must implement the following builtins: echo, cd, export, unset , env, exit, pwd.
- You must implement the following redirections: <, >, >>.
- You must implement the following pipes: |.
