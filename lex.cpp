#include "defs.h"
#include "data.h"
#include "decl.h"
static int chrpos(char *s, int c)
{
    int i;
    for (i = 0; i < strlen(s); i++)
        if (s[i] == c)
            return (i);
    return (-1);
}

static int next(void)
{
    int c;
    if (Putback != '\n')
    {
        c = Putback;
        Putback = '\n';
        return (c);
    }
    c = getc(Infile);
    if (c == '\n')
        Line++;
    return (c);
}

static void putback(int c)
{
    if (c == '\n')
        Line--;
    Putback = c;
}


static int skip(void)
{
    int c;

    c = next();
    while (' ' == c || '\t' == c || '\n' == c || '\r' == c || '\f' == c)
    {
        c = next();
    }
    return (c);
}


static int scanint(int c)
{
    int k, val = 0;
    while (isdigit(c))
    {
        val = val * 10 + c - '0';
        c = next();
    }
    putback(c);
    return (val);
}

static int scanident(int c, char *buf, int lim)
{
    int i = 0;
    while (isalpha(c) || isdigit(c) || '_' == c)
    {
        if (lim - 1 == i)
        {
            fatal("Identifier too long");
        }
        else if (i < lim - 1)
        {
            buf[i++] = c;
        }
        c = next();
    }
    putback(c);
    buf[i] = '\0';
    return (i);
}
static int keyword(char *s)
{
    switch (*s)
    {
    case 'b':
        if (!strcmp(s, "begin"))
            return (T_BEGIN);
        break;
    case 'd':
        if (!strcmp(s, "display"))
            return (T_DISPLAY);
        break;
    case 'e':
        if (!strcmp(s, "else"))
            return (T_ELSE);
        break;
    case 'i':
        if (!strcmp(s, "if"))
            return (T_IF);
        if (!strcmp(s, "int"))
            return (T_INT);
        break;
    
    }
    return (0);
}

int scan(struct token *t)
{
    int c, tokentype;
    c = skip();
    switch (c)
    {
    case EOF:
        t->token = T_EOF;
        return (0);
    case '+':
        t->token = T_PLUS;
        break;
    case '-':
        t->token = T_MINUS;
        break;
    case '*':
        t->token = T_STAR;
        break;
    case '/':
        t->token = T_SLASH;
        break;
    case ';':
        t->token = T_SEMI;
        break;
    case '{':
        t->token = T_LBRACE;
        break;
    case '}':
        t->token = T_RBRACE;
        break;
    case '(':
        t->token = T_LPAREN;
        break;
    case ')':
        t->token = T_RPAREN;
        break;
    case '=':
        if ((c = next()) == '=')
        {
            t->token = T_EQ;
        }
        else
        {
            putback(c);
            t->token = T_ASSIGN;
        }
        break;
    case '!':
        if ((c = next()) == '=')
        {
            t->token = T_NE;
        }
        else
        {
            fatalc("Unrecognised character", c);
        }
        break;
    case '<':
        if ((c = next()) == '=')
        {
            t->token = T_LE;
        }
        else
        {
            putback(c);
            t->token = T_LT;
        }
        break;
    case '>':
        if ((c = next()) == '=')
        {
            t->token = T_GE;
        }
        else
        {
            putback(c);
            t->token = T_GT;
        }
        break;
    default:
        if (isdigit(c))
        {
            t->intvalue = scanint(c);
            t->token = T_INTLIT;
            break;
        }
        else if (isalpha(c) || '_' == c)
        {
            scanident(c, Text, TEXTLEN);
            if (tokentype = keyword(Text))
            {
                t->token = tokentype;
                break;
            }
            t->token = T_IDENT;
            break;
        }
        fatalc("Unrecognised character", c);
    }
    return (1);
}