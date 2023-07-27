# pipex

Self implementation of pipes and here_doc. The program is behaving like shell pipes. I'm using "pipe" command from the standard C library
and also some functions I wrote myself (which are similar alike to the standard ones).

## Get started

First of all you should git clone the repo in your terminal. And then enter the folder you've created. Do it in the following way:

```console
git clone https://github.com/MilenaKhalil/pipex pipex
cd pipex
```

Build the project by running "make" or "make bonus":

```console
make
```

```console
make bonus
```
>NOTE! If you are running _make_ the name of the executable will be _pipex_. If you run _make bonus_ it is going to be _pipex_bonus_.

## Running the project

Run the executable with following parameters: input file, command one, command two, output file. If you are running the bonus part you can
use as many commands as you want. Here are some examples:

```console
./pipex_bonus Makefile cat cat cat cat "grep al" out
cat out
```
And then it should output some lines in the Makefile containing "al" in it.
>NOTE! If the function has parameters, like in this example, put it inside brackets together. Otherwise the program will try to find command "al",
>and throw an error

If you want to run with here_doc, use it as the first parameter and then put the keyword. The key word is the end and the beginning of the here_doc.
```console
./pipex_bonus here_doc haha cat cat out
this
is
amazing
!
haha
```
If you run `cat out` it's gonna say:
`
this
is
amazing
!
`
separated by a new line.
You can pass more commands with the here_doc but there should be at least two.
## Last thing, really...
Enjoy pipes and let me know if there are any issues with my code!
