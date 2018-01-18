TARGET=find-nonascii

$(TARGET): $(TARGET).o

$(TARGET).o: $(TARGET).cpp

install:
	install $(TARGET) /usr/local/bin

clean:
	$(RM) $(TARGET) $(TARGET).o

