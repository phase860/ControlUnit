CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -pedantic
BIN=ControlUnit

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)


$(BIN): Message.o ControlUnit.o MessageBase.o
	$(CXX) -o $(BIN) Message.o ControlUnit.o MessageBase.o

test: testMessage.o Message.o MessageBase.o testMessageBase.o
	$(CXX) $(CXXFLAGS) -o testMessageBase testMessageBase.o Message.o MessageBase.o
	$(CXX) $(CXXFLAGS) -o testMessage testMessage.o Message.o MessageBase.o
	./testMessageBase
	./testMessage

ControlUnit.o: ControlUnit.cpp Message.hpp
	$(CXX) $(CXXFLAGS) -c ControlUnit.cpp

testMessage.o: testMessage.cpp Message.hpp
	$(CXX) $(CXXFLAGS) -c testMessage.cpp

Message.o: Message.cpp Message.hpp MessageBase.hpp
	$(CXX) $(CXXFLAGS) -c Message.cpp

MessageBase.o: MessageBase.cpp MessageBase.hpp
	$(CXX) $(CXXFLAGS) -c MessageBase.cpp

.PHONY : clean
clean:
	-rm -- *.o $(BIN) tags testMessage $(BIN).exe testMessageBase
