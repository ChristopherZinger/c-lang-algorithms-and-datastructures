#!/bin/bash

programname="quicksort";
rm "$programname";
gcc "$programname.c"  "./utils/print_array.c" -o "../bin/$programname";
"../bin/$programname";
