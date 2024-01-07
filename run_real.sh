# Only proper implementations, no hacky hardcoding

printf "\e[1;34mImplementations sorted by fastest first\e[0m\n\n"

printf "\e[1;32mRust\e[0m\n"
time ./rust/target/release/rust hi file.txt
echo

printf "\e[1;32mC\e[0m\n"
time ./c/2 hi file.txt
echo

printf "\e[1;32mC - Old implementation\e[0m\n"
time ./c/1 hi file.txt
echo

printf "\e[1;32mC++\e[0m\n"
time ./c++/1 hi file.txt
echo

printf "\e[1;32mC++ - 2nd implementation\e[0m\n"
time ./c++/2 hi file.txt
echo

printf "\e[1;32mGo\e[0m\n"
time ./go/1 hi file.txt
echo

printf "\e[1;32mC++ - Stream implementation\e[0m\n"
time ./c++/3 hi file.txt
echo

printf "\e[1;32mPython\e[0m\n"
time python3 ./python/main.py hi file.txt
echo
