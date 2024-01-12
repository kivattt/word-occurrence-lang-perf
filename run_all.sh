TIMEFORMAT=%R

printf "\e[1;34mImplementations sorted by fastest first\e[0m\n\n"

printf "\e[1;32mC++ - Sketchiest hardcoded to match \"i\"\e[0m\n"
time ./c++/5 file.txt
echo

printf "\e[1;32mGo - Hardcoded to match \"i\"\e[0m\n"
time ./go/3 file.txt
echo

printf "\e[1;32mGo - Read into buffer, hardcoded to match \"hi\"\e[0m\n"
time ./go/2 file.txt
echo

printf "\e[1;32mC - Hardcoded to match \"hi\"\e[0m\n"
time ./c/3 hi file.txt
echo

printf "\e[1;32mC++ - Hardcoded to match \"hi\"\e[0m\n"
time ./c++/4 hi file.txt
echo

printf "\e[1;32mtr + wc - Matching \"i\"\e[0m\n\e[0;36m"
time tr -c -d 'i' < file.txt | wc -c
printf "\e[0m\n"

printf "\e[1;32mRust\e[0m\n"
time ./rust/target/release/rust hi file.txt
echo

printf "\e[1;32mC\e[0m\n"
time ./c/2 hi file.txt
echo

printf "\e[1;32mC - Old implementation\e[0m\n"
time ./c/1 hi file.txt
echo

printf "\e[1;32mJava - Hardcoded to match \"hi\"\e[0m\n"
pushd java > /dev/null
time ~/.jdks/openjdk-21.0.1/bin/java Main hi ../file.txt
popd > /dev/null
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

printf "\e[1;32mPython - Hardcoded to match \"hi\"\e[0m\n"
time python3 ./python/2.py file.txt
echo

printf "\e[1;32mPython\e[0m\n"
time python3 ./python/1.py hi file.txt
echo
