#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TEXTLEN 512
#define NSYMBOLS 1024
enum
{
    T_EOF,
    T_PLUS,
    T_MINUS,
    T_STAR,
    T_SLASH,
    T_EQ,
    T_NE,
    T_LT,
    T_GT,
    T_LE,
    T_GE,
    T_INTLIT,
    T_SEMI,
    T_ASSIGN,
    T_IDENT,
    T_LBRACE,
    T_RBRACE,
    T_LPAREN,
    T_RPAREN,
    // Keywords
    T_DISPLAY,
    T_INT,
    T_IF,
    T_ELSE,
    T_BEGIN,
};

struct token
{
    int token;
    int intvalue;
};
// AST node types
enum
{
    A_ADD = 1,
    A_SUBTRACT,
    A_MULTIPLY,
    A_DIVIDE,
    A_EQ,
    A_NE,
    A_LT,
    A_GT,
    A_LE,
    A_GE,
    A_INTLIT,
    A_IDENT,
    A_LVIDENT,
    A_ASSIGN,
    A_DISPLAY,
    A_GLUE,
    A_IF
};

// Abstract Syntax Tree structure
struct ASTnode
{
    int op;               // "Operation" to be performed on this tree
    struct ASTnode *left; // Left, middle and right child trees
    struct ASTnode *mid;
    struct ASTnode *right;
    union
    {
        int intvalue; // For A_INTLIT, the integer value
        int id;       // For A_IDENT, the symbol slot number
    } v;
};
struct symtable
{
    char *name; // Name of a symbol
};