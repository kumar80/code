#!/bin/bash
# A sample Bash script, by Ryan

# g++ tgen.cpp
# ./a.out > in.txt
# cat in.txt

# g++ wo.cpp
# ./a.out < in.txt  > sol.txt
g++ $1
./a.out < input.txt  > out.txt

# if [[ $(diff sol.txt out.txt ) ]]; then
#     echo ***********************DIFFERENT ANSWER***********************
#     cat sol.txt out.txt 
# else
#     echo "Match 100%"
# fi
echo DONE!


