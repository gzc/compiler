#include <stdio.h>
#include "node.h"
#include "lexya_e.tab.h"

float NodeExecute(Node *p) {

    if (!p) return 0;
    
    switch(p->type) {
	
	case TYPE_CONTENT: return p->content;
			   
	case TYPE_INDEX:   return G_Var[p->index].val;
			
	case TYPE_OP:

			   switch(p->op.name) {
			
			       case WHILE:  while(NodeExecute(p->op.node[0]))NodeExecute(p->op.node[1]);
						
						return 0;
					
			       
			       case FOR:    NodeExecute(p->op.node[0]);
					
					    while(NodeExecute(p->op.node[1])) {
						
						NodeExecute(p->op.node[3]);
						
						NodeExecute(p->op.node[2]);
						
					    }
					
					    return 0;


					
			       case IF:     if (NodeExecute(p->op.node[0]))
	
						NodeExecute(p->op.node[1]);
					
					    else
						
						if (p->op.num>2)

						    NodeExecute(p->op.node[2]);
					
					    return 0;
					
			       case PRINT:  printf("%g\n", NodeExecute(p->op.node[0]));
					    
					    return 0;


			       case ';':    NodeExecute(p->op.node[0]);
					
					    return NodeExecute(p->op.node[1]);

					
			       case '=':    return G_Var[p->op.node[0]->index].val = NodeExecute(p->op.node[1]);

					
			       case UMINUS: return NodeExecute(p->op.node[0]);

					
			       case '+':    return NodeExecute(p->op.node[0]) + NodeExecute(p->op.node[1]);

					
			       case '-':    return NodeExecute(p->op.node[0]) - NodeExecute(p->op.node[1]);

					
			       case '*':    return NodeExecute(p->op.node[0]) * NodeExecute(p->op.node[1]);

					
			       case '/':    return NodeExecute(p->op.node[0]) / NodeExecute(p->op.node[1]);

					
			       case '<':    return NodeExecute(p->op.node[0]) < NodeExecute(p->op.node[1]);

					
			       case '>':    return NodeExecute(p->op.node[0]) > NodeExecute(p->op.node[1]);

					
			       case GE:     return NodeExecute(p->op.node[0]) >= NodeExecute(p->op.node[1]);

					
			       case LE:     return NodeExecute(p->op.node[0]) <= NodeExecute(p->op.node[1]);

					
			       case NE:     return NodeExecute(p->op.node[0]) != NodeExecute(p->op.node[1]);

					
			       case EQ:     return NodeExecute(p->op.node[0]) == NodeExecute(p->op.node[1]);

					
			       case AND:    return NodeExecute(p->op.node[0]) && NodeExecute(p->op.node[1]);

					
			       case OR:     return NodeExecute(p->op.node[0]) || NodeExecute(p->op.node[1]);  

					
			       case ADD_T:  return ++G_Var[p->op.node[0]->index].val;

					
			       case MUS_T:  return --G_Var[p->op.node[0]->index].val;

					
			       case ADD_TT: return G_Var[p->op.node[0]->index].val++;

					
			       case MUS_TT: return G_Var[p->op.node[0]->index].val--;

					
			   }

    
    }
    

    return 0;
}


