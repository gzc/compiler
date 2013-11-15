typedef enum { TYPE_CONTENT,TYPE_INDEX,TYPE_OP } NodeEnum;

/* operation */

typedef struct {
    int name;
    int num;
    struct NodeTag *node[1];
}OpNode;

typedef struct NodeTag {
    NodeEnum type;
    union {
	float content;
	int index;
	OpNode op;
    };
}Node;

struct VarIndex
{
    float val;
    char mark[10];
};

struct VarDefine
{
    int index;
    char *name;
};

#define USER_DEF_NUM 259
#define MAX_VARS 100
#define MAX_DEFS 20
#define MAX_BUFF_COLS 40
#define MAX_BUFF_ROWS 40

extern struct VarIndex G_Var[MAX_VARS];
extern struct VarDefine G_Def[MAX_DEFS];

extern int G_iVarMaxIndex; /* current variable numbers */
extern int G_iVarCurIndex; 

extern char G_sBuff[MAX_BUFF_ROWS][MAX_BUFF_COLS];
extern int G_iBuffRowCount;
extern int G_iBuffColCount;

// #define PARSE_DEBUG
