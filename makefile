#
#	baut das komplette Scanner Projekt
#


AUTOMATDIR = Automat

BUFFERDIR = Buffer

SYMBOLTABLEDIR = Symboltable

SCANNERDIR = Scanner

PARSERDIR = Parser

SHAREDLIB = sharedlib


all:	automatLib bufferLib symboltableLib scannerLib parser
	@echo "target all"

	

clean:
	rm -rf $(AUTOMATDIR)/lib/*
	rm -rf $(BUFFERDIR)/lib/*
	rm -rf $(SYMBOLTABLEDIR)/lib/*
	rm -rf $(SHAREDLIB)/*
	rm -rf $(SCANNERDIR)/debug/*
	rm -rf $(SCANNERDIR)/lib/*
	

parser: 
	$(MAKE) -C $(PARSERDIR) makeTestParser
	
scanner: 
	$(MAKE) -C $(SCANNERDIR) makeTestScanner

automatLib:
	$(MAKE) -C $(AUTOMATDIR) AutomatLib
	
bufferLib:
	$(MAKE) -C $(BUFFERDIR) BufferLib

scannerLib:
	$(MAKE) -C $(SCANNERDIR) ScannerLib
	
symboltableLib:
	$(MAKE) -C $(SYMBOLTABLEDIR) SymboltableLib
