#
#		Targets zum Bauen des Tests
#

# Linken der Object-files, abhaengig von ParserTarget und TestParserTarget
# flag:
# -g --> debug Informationen erzeugen
# -o --> name des output-files

makeTestParser: ParserTarget TestParserTarget  
	g++ --std=c++0x -g debug/Parser.o debug/TestParser.o -o debug/ParserTest
	

# compilieren des Files Parser.cpp zu Parser.o, 
# das Objekt-File ist abhängig von src/Parser.cpp und src/Parser.h
# flag:
# -c --> compilieren
# -Wall --> alle meldungen erzeugen

ParserTarget :  src/Parser.cpp src/Parser.h 
	g++ --std=c++0x  -g  -c -Wall src/Parser.cpp -o debug/Parser.o  


# TestParser.o ist abhängig von src/TestParser.cpp und src/Parser.h
TestParserTarget :  src/TestParser.cpp src/Parser.h
	g++ --std=c++0x  -g  -c -Wall src/TestParser.cpp  -o debug/TestParser.o  



# loeschen aller files im verzeichnis obj und lib und neu bauen

cleanParser:
	rm -rf obj/*
	rm -rf lib/*
	$(MAKE) makeTestParser
	
	
#
# erstellen der shared library
#

ParserLib: ParserLibTarget
		g++ --std=c++0x  -shared lib/Parser.o  -o ../sharedlib/libParser.so 

	
# compilieren des Files Parser.cpp zu Parser.o mit dem Flag -fPIC (Position Independant Code)
ParserLibTarget :  src/Parser.cpp src/Parser.h
	g++ --std=c++0x  -g  -c -fPIC  src/Parser.cpp -o lib/Parser.o   



