# Definition der Variablen

SRCDIR = src
SRCDIR2 = ../

OBJDIR = debug
OBJDIR2 = ../

BINDIR = debug

LIBDIR = lib

SHAREDLIB = ../sharedlib

## hier alle Object Files eintragen
## darauf achten, dass letzte Zeile ohne "\" eingetragen wird
EXTOBJS = $(OBJDIR)/Token.o \
	$(OBJDIR)/String.o 
OBJS = $(OBJDIR)/Symboltable.o \
	$(OBJDIR)/TokenNode.o \
	$(OBJDIR)/TokenLinkedList.o \
	$(OBJDIR)/HashMap.o
	#$(OBJDIR)/ILinkedList.o 
	#$(OBJDIR)/ILinkedList.o
	#$(OBJDIR)/xx1.o \
	#$(OBJDIR)/xxn.o
	
MAIN_TEST_SYMBOLTABLE = $(OBJDIR)/TestSymboltable.o

MAIN_TEST_HASHMAP = $(OBJDIR)/TestHashMap.o

OBJSFORSYMBOLTABLELIB =  \
	$(LIBDIR)/Symboltable.o \
	$(LIBDIR)/TokenNode.o \
	$(LIBDIR)/TokenLinkedList.o \
	$(LIBDIR)/HashMap.o

EXTOBJSFORSYMBOLTABLELIB =  \
	$(LIBDIR)/Token.o \
	$(LIBDIR)/String.o 
	

#
#		Targets zum Bauen des Tests
#

# Variante mit geringen Makefile-Kenntnissen

## Linken der Object-Files
#makeTestSymboltable: $(OBJDIR)/Symboltable.o $(OBJDIR)/TestSymboltable.o
#	g++ -g $(OBJDIR)/Symboltable.o $(OBJDIR)/TestSymboltable.o -o $(BINDIR)/SymboltableTest
#
#	
## compilieren der Source-files
#
#$(OBJDIR)/Symboltable.o :  $(SRCDIR)/Symboltable.cpp 
#	@echo "g++ $*.cpp"
#	g++ -g  -c -Wall  -o $(OBJDIR)/Symboltable.o  $(SRCDIR)/Symboltable.cpp
#
#
#$(OBJDIR)/TestSymboltable.o :  $(SRCDIR)/TestSymboltable.cpp $(SRCDIR)/Symboltable.h
#	@echo "g++ $*.cpp"
#	g++ -g  -c -Wall  -o $(OBJDIR)/TestSymboltable.o  $(SRCDIR)/TestSymboltable.cpp
#

# Variante mit guten Makefile-Kenntnissen

makeTestSymboltable: SymboltableTest
makeTestHashMap: HashMapTest


SymboltableTest: $(OBJS) $(EXTOBJS) $(MAIN_TEST_SYMBOLTABLE)
	g++ -g $^ -o $(BINDIR)/SymboltableTest
	
HashMapTest: $(OBJS) $(EXTOBJS) $(MAIN_TEST_HASHMAP)
	g++ -g $^ -o $(BINDIR)/HashMapTest
	
# $^ liste der abhaengigkeiten


$(OBJDIR)/%.o :  $(SRCDIR)/%.cpp
	@echo "g++ $*.cpp"
	g++ -g  -c -Wall  -o $@  $<
	
$(OBJDIR)/%.o : $(SRCDIR2)/%.cpp
	@echo "g++ $*.cpp"
	g++ -g  -c -Wall  -o $@  $<

# 
# $@ name des object files
# $< erste abhaengigkeit


# loeschen aller files im verzeichnis $(OBJDIR)

cleanSymboltable:
	rm -rf $(OBJDIR)/*
	rm -rf $(LIBDIR)/*
	$(MAKE) makeTestSymboltable
	
cleanSymboltable_HashMap:
	rm -rf $(OBJDIR)/*
	rm -rf $(LIBDIR)/*
	$(MAKE) makeTestHashMap
	
#	
# erstellen der shared library
#

#SymboltableLib:$(LIBDIR)/Symboltable.o
#		g++ -shared  -o $(SHAREDLIB)/libSymboltable.so $(LIBDIR)/Symboltable.o 
#
#	
#$(LIBDIR)/Symboltable.o :  $(SRCDIR)/Symboltable.cpp 
##	@mkdir -p `dirname $(OBJDIR)/$*.o`
#	@echo "g++ $*.cpp"
#	g++ -g  -c -fPIC  -o $(LIBDIR)/Symboltable.o  $(SRCDIR)/Symboltable.cpp 
#


SymboltableLib:$(OBJSFORSYMBOLTABLELIB) $(EXTOBJSFORSYMBOLTABLELIB)
		g++ -shared  -o $(SHAREDLIB)/libSymboltable.so $^ 

	
$(LIBDIR)/%.o :  $(SRCDIR)/%.cpp 
#	@mkdir -p `dirname $(OBJDIR)/$*.o`
	@echo "g++ $*.cpp"
	g++ -g  -c -fPIC  -o $@  $<
	
$(LIBDIR)/%.o :  $(SRCDIR2)/%.cpp 
#	@mkdir -p `dirname $(OBJDIR)/$*.o`
	@echo "g++ $*.cpp"
	g++ -g  -c -fPIC  -o $@  $<

