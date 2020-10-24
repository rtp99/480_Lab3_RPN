To compile, run "make lab3"
To execute, "./lab3"
This program should be run in the command line.
Input may be entered when a > symbol is present.
Conclude your statement by pressing enter, the equals sign at the end of an equation is not necessary.
Inclusion of the equals
Spaces are ignored. Whitespace is for the user's benefit alone, a computer does not need it.
Example: 6+4+log5 is equivalent to 6 + 4 + log 5
Because the command line cannot process subscript, "log base 10" is shortened to "log".
The spec sheet only specified that log base 10 and e (ln) were necessary, hence the shortening
Example: log6 will give you the log base 10 of 6
Parenthesis are optional for functions (trig functions, log functions) but will help establish the operand better.
Example: tan 6 + 4 will give you the tangent of 6 and then add 4. this is because functions take precedence.
Example: tan(6+4) will give you the tangent of 6+4 or more accurately the tangent of 10.
Functions effectively hold the same level of precedence as a parenthesis.
The default value of this calculator is 0. If you just press enter, or send a lone equals sign, it will return 0.
This also means that if your statement begins with a binary operator, it will treat the first operand as 0.
This is default behavior for many of the calculators I have used in the past, so thought it would be good to include it.
If you doubt this, open up the windows default calculator and try it for yourself.
Example: +3 returns 3
Example: = returns 0
Negatives are handled similarly to the negate button on a calculator. This means multiple negative signs will stack.
Example: --3 returns 3
Example: ---3 returns -3
Exit the program by closing the command line window, CTRL+C, or whatever the equivalent is for your OS.
