#presettings----------------------------------------
PROGRAM := ctox

PARSER_NAME := c_parser
PARSER_EXT := tab
LEXER_NAME := c_lexer
LEXER_EXT := lex

PARSER := $(PARSER_NAME).$(PARSER_EXT)
LEXER := $(LEXER_NAME).$(LEXER_EXT)
OUTPUT := ctox.output.xml
#presettings----------------------------------------

$(PROGRAM): $(LEXER).c $(PARSER).c $(PARSER).h
	gcc -o $(PROGRAM) -O3 $(LEXER).c $(PARSER).c