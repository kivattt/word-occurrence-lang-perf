pushd c
gcc -O3 1.c -o 1
gcc -O3 2.c -o 2
gcc -O3 3.c -o 3
popd

pushd c++
g++ -O3 1.cpp -o 1
g++ -O3 2.cpp -o 2
g++ -O3 3.cpp -o 3
g++ -O3 4.cpp -o 4
g++ -O3 5.cpp -o 5
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
