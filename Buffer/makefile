# Definition der Variablen

SRCDIR = src
OBJDIR = debug

BINDIR = debug

LIBDIR = lib

SHAREDLIB = ../sharedlib

OBJS = $(OBJDIR)/BufferHalf.o \
	$(OBJDIR)/Buffer.o \
	$(OBJDIR)/TestBuffer.o
	
OBJSFORBUFFERLIB =  \
	$(LIBDIR)/BufferHalf.o \
	$(LIBDIR)/Buffer.o

#
#		Targets zum Bauen des Tests
#


# Variante mit guten Makefile-Kenntnissen

makeTestBuffer: BufferTest

# Linken der Object-files
BufferTest: $(OBJS)
	g++ -g $^ -o $(BINDIR)/BufferTest
	
# $^ liste der abhaengigkeiten

# compilieren der Object-Files aus den Sourcen
$(OBJDIR)/%.o :  $(SRCDIR)/%.cpp
	@echo "g++ $*.cpp"
	g++ -g  -c -Wall  -o $@  $<

# 
# $@ name des object files
# $< erste abhaengigkeit


# loeschen aller files im verzeichnis $(OBJDIR) und$(LIBDIR) und neu bauen

cleanBuffer:
	rm -rf $(OBJDIR)/*
	rm -rf $(LIBDIR)/*
	$(MAKE) makeTestBuffer
	

#	
# erstellen der shared library
#

BufferLib:$(OBJSFORBUFFERLIB)
		g++ -shared -fPIC -o $(SHAREDLIB)/libBuffer.so $^ 

	
$(LIBDIR)/%.o :  $(SRCDIR)/%.cpp 
#	@mkdir -p `dirname $(OBJDIR)/$*.o`
	@echo "g++ $*.cpp"
	g++ -g  -c -fPIC  -o $@  $<	