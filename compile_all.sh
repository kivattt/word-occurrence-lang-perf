pushd c
gcc -Wno-unused-result -O3 1.c -o 1
gcc -Wno-unused-result -O3 2.c -o 2
gcc -Wno-unused-result -O3 3.c -o 3
popd

pushd c++
g++ -O3 1.cpp -o 1
g++ -O3 2.cpp -o 2
g++ -O3 3.cpp -o 3
g++ -O3 4.cpp -o 4
g++ -O3 5.cpp -o 5
g++ -std=c++23 -lpthread -march=native -O3 6.cpp -o 6
g++ -std=c++23 -lpthread -march=native -O3 7.cpp -o 7
g++ -std=c++23 -lpthread -march=native -O3 8.cpp -o 8
popd

pushd go
go build 1.go
go build 2.go
go build 3.go
go build 4.go
popd

pushd rust
cargo build --release # opt-level 3
popd

# :skull:
pushd java
~/.jdks/openjdk-21.0.1/bin/javac Main.java
popd
