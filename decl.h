#include<iostream>
// lex.cpp
int scan(struct token *t);

// ast.cpp
struct ASTnode *mkastnode(int op, struct ASTnode *left,struct ASTnode *mid,struct ASTnode *right, int intvalue);
struct ASTnode *mkastleaf(int op, int intvalue);
struct ASTnode *mkastunary(int op, struct ASTnode *left, int intvalue);


// expr.cpp
struct ASTnode *binexpr(int ptp);

// stmt.cpp
struct ASTnode *compound_statement(void);

// misc.cpp
void match(int t, std::string what);
void semi(void);
void lbrace(void);
void rbrace(void);
void lparen(void);
void rparen(void);
void ident(void);
void fatal(std::string s);
void fatals(std::string s1, std::string s2);
void fatald(std::string s, int d);
void fatalc(std::string s, int c);

// sym.cpp
int findglob(char *s);
int addglob(char *name);

// decl.cpp
void var_declaration(void);
//interp.cpp
int  interpretAST(struct ASTnode *n);