
# Change this to reflect you assets
MINGW=E:/mingw64
PATH=$PATH;E:\mingw64\bin
CC=${MINGW}/bin/g++
FALCON_HOME="C:/Falcon\ BMS\ 4.33\ U1"

all : testshared.exe

# $@ matches the target, $< matches the first dependancy
testshared.exe : bms.cpp bms.h
	${CC} -m64 -I"${FALCON_HOME}\Tools\SharedMem" -O0 -g3 -Wall -c -fmessage-length=0 -o testshared.exe $<

clean :
	rm testshared.exe
