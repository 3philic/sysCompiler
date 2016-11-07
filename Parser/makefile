SRCDIR = src
OBJDIR = debug

BINDIR = debug

LIBDIR = lib


SHAREDLIB = ../sharedlib

## hier alle Object Files eintragen
## darauf achten, dass letzte Zeile ohne "\" eingetragen wird

OBJS = $(OBJDIR)/Parser.o \
	$(OBJDIR)/TestParser.o \
	$(OBJDIR)/Node.o \
	$(OBJDIR)/ProgramNode.o

OBJSFORSCANNERLIB =  \
	$(LIBDIR)/Parser.o



#Variante  mit guten Kenntnissen
makeTestParser: $(OBJS)
	g++ -g $^ -L../sharedlib  -lAutomat -lBuffer -lSymboltable -lScanner -o $(BINDIR)/ParserTest
	
	
	
# $^ liste der abhaengigkeiten


$(OBJDIR)/%.o :  $(SRCDIR)/%.cpp 
	@echo "g++ $*.cpp"
	g++ -g  -c -Wall  -o $@  $<

# 
# $@ name des object files
# $< erste abhaengigkeit


# loeschen aller files im verzeichnis $(OBJDIR) und $(LIBDIR) und neu bauen

cleanParser:
	rm -rf $(OBJDIR)/*
	
	
	
ParserLib:$(OBJSFORPARSERLIB)
	g++ -L../sharedlib  -lAutomat -lBuffer -lSymboltable -lScanner -shared -o $(SHAREDLIB)/libParser.so $^

$(LIBDIR)/%.o :  $(SRCDIR)/%.cpp 
	@echo "g++ $*.cpp"
	g++ -g  -c -fPIC  -o $@  $<

	