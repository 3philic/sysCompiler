SRCDIR = src
OBJDIR = debug

SRCDIR_NODE = src/Node
OBJDIR_NODE = $(OBJDIR)

BINDIR = debug

LIBDIR = lib


SHAREDLIB = ../sharedlib

## hier alle Object Files eintragen
## darauf achten, dass letzte Zeile ohne "\" eingetragen wird

OBJS = $(OBJDIR)/Parser.o \
	$(OBJDIR)/TestParser.o \
	$(OBJDIR)/CodeGeneratorVisitor.o \
	$(OBJDIR)/FileWriter.o \
	$(OBJDIR)/Node.o \
	$(OBJDIR)/ParseTree.o \
	$(OBJDIR)/PrintingVisitor.o \
	$(OBJDIR)/TypeCheckVisitor.o \
	$(OBJDIR)/Visitor.o \
	$(OBJDIR_NODE)/ArrayNode.o \
	$(OBJDIR_NODE)/DeclNode.o \
	$(OBJDIR_NODE)/DeclsNode.o \
	$(OBJDIR_NODE)/EpsilonNode.o \
	$(OBJDIR_NODE)/Exp2Node.o \
	$(OBJDIR_NODE)/ExpNode.o \
	$(OBJDIR_NODE)/IndexNode.o \
	$(OBJDIR_NODE)/Leaf.o \
	$(OBJDIR_NODE)/OpExpNode.o \
	$(OBJDIR_NODE)/OpNode.o \
	$(OBJDIR_NODE)/ProgramNode.o \
	$(OBJDIR_NODE)/StatementNode.o \
	$(OBJDIR_NODE)/StatementsNode.o \
	

OBJSFORPARSERLIB =  \
	$(LIBDIR)/Parser.o



#Variante  mit guten Kenntnissen
makeTestParser: $(OBJS)
	g++ -g $^ -L../sharedlib -o $(BINDIR)/ParserTest -lScanner -lAutomat -lBuffer -lSymboltable 
	
	
	
# $^ liste der abhaengigkeiten


$(OBJDIR)/%.o :  $(SRCDIR)/%.cpp 
	@echo "g++ $*.cpp"
	g++ -g  -c -Wall  -o $@  $<

# 
# $@ name des object files
# $< erste abhaengigkeit

$(OBJDIR_NODE)/%.o :  $(SRCDIR_NODE)/%.cpp 
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

	