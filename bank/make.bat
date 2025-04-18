cd /d %~dp0
g++ -fexec-charset=cp932 -g main.cpp -o main.exe -static -lgcc -lstdc++ -lwinpthread
main

