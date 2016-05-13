# Program Settings
PROGRAM := snake.out

# Compiler variables
CC = g++

# VPATH directories
VPATH = src

# Directories variables
BINDIR := bin
BUILDDIR := build
INCLUDEDIR :=include
LIBDIR := lib
SRCDIR := src

# Source files extensions
SRCEXT := cpp

# PHONY targets
.PHONY: clean, run

# flags
CPPFlLAGS := -std=c++11 -L$(LIBDIR) -I$(INCLUDEDIR)

SOURCES := $(shell find $(SRCDIR) -type f -name	*.$(SRCEXT) -printf "%f\n")
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

$(BINDIR): $(BUILDDIR)/$(OBJECTS)
	@echo "Linking..."
	$(CC) $^ -o $(BINDIR)/$(PROGRAM)

$(BUILDDIR)/%.o: %.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(BINDIR)
	$(CC) $(CPPFlLAGS) -c -o $@ $<

clean:
	@echo "Cleaning the project..."
	$(RM) -r $(BUILDDIR) $(BINDIR)