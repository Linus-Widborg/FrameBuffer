CXXFLAGS =	-O2 -g -Wall -std=c++11 -fmessage-length=0
SRC_DIR =	src
OBJS =		$(SRC_DIR)/FrameBuffer.o $(SRC_DIR)/ImageHandle.o $(SRC_DIR)/Frame.o

LIBS =

TARGET =	FrameBuffer

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

TESTDIR = test
TEST_TARGET =	$(TESTDIR)/TestFrameBuffer
TEST_OBJS = $(TESTDIR)/TestFrameBuffer.o
TEST_LIBS = -lcunit
$(TEST_TARGET):	$(TEST_OBJS) $(OBJS)
	$(CXX) -o $(TEST_TARGET) $(TEST_OBJS) $(OBJS) $(TEST_LIBS)
	
test:	$(TEST_TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
