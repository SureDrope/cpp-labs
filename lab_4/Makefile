CXX = g++
CXXFLAGS = -std=c++20 -I include

# Project files
SOURCES = main.cpp classes/*
TARGET = program

# Linking rule
$(TARGET): $(SOURCES)
	$(CXX) $(SOURCES) $(CXXFLAGS) -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)

.PHONY: clean
