STLIB 	= ar -cr
RANLIB  = ranlib
INCLUDE = -I./src -I/usr/local/include
CPP 	= g++
LIBRARY = -L. -L/usr/local/lib
SYSLIBS = -lPocoFoundation -ltimer

#modules
obj-x += src/RunTimePlatform.o
obj-x += src/Event.o

#test
obj-HelloWorld += test/HelloWorld.o
