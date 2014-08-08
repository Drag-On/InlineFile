CXXFLAGS =	-O2 -g -Wall -std=c++11 -fmessage-length=0

OBJS =		InlineFile.o

LIBS =

TARGET =	InlineFile.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
