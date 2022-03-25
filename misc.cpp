#include "defs.h"
#include "data.h"
#include "decl.h"
#include <iostream>
void match(int t, std::string what)
{   
    if (Token.token == t)
    {
        scan(&Token);
    }
    else
    {
        fatals("Expected " ,what);
    }
}

// Match a semicolon and fetch the next token
void semi(void)
{
    match(T_SEMI, ";");
}

// Match a left brace and fetch the next token
void lbrace(void)
{
    match(T_LBRACE, "{");
}

// Match a right brace and fetch the next token
void rbrace(void)
{
    match(T_RBRACE, "}");
}

// Match a left parenthesis and fetch the next token
void lparen(void)
{
    match(T_LPAREN, "(");
}

// Match a right parenthesis and fetch the next token
void rparen(void)
{
    match(T_RPAREN, ")");
}

// Match an identifier and fetch the next token
void ident(void)
{
    match(T_IDENT, "identifier");
}

// Print out fatal messages
void fatal(std::string s)
{
    fprintf(stderr, "%s on line %d\n", s, Line);
    exit(1);
}

void fatals(std::string s1, std::string s2)
{
    fprintf(stderr, "%s %s on line %d\n", s1.c_str(), s2.c_str(), Line);
    exit(1);
}

void fatald(std::string s, int d)
{
    fprintf(stderr, "%s:%d on line %d\n", s, d, Line);
    exit(1);
}

void fatalc(std::string s, int c)
{
    fprintf(stderr, "%s:%c on line %d\n", s, c, Line);
    exit(1);
}