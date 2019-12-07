:loop
data > read.txt
code < read.txt > out
brute < read.txt > ans
fc out ans
if errorlevel 1 pause
goto loop