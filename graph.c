#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "lexya_e.tab.h"


#define MAX_NODE_TEXT_LEN 10

#define MAX_SUBNODE_COUNT 1000

#define NODE_WIDTH 4

#define MAX_NODE_COUNT 1000


#define MAX_TREE_WIDTH 200

#define MAX_TREE_DEEP 1000



struct NodePoint {

    int x;
    int y;

    char text[MAX_NODE_TEXT_LEN];
    int textoffset1;
    int textoffset2;

    int parent;
    int idx;

    Node *node;

    int oppx;
    int oppx_mid;

    int childnum;
    int child[MAX_SUBNODE_COUNT];

};

struct NodePoint G_TreeNodePoint[MAX_NODE_COUNT];

int G_iNodeCount;
int G_iNodeParent;

struct NodePoint *G_pTreeNodeOrder[MAX_TREE_DEEP][MAX_TREE_WIDTH];
int G_iTreeNodeOrderCount[MAX_TREE_DEEP];

int G_iDeepCount;
int G_iMinNodeXValue;
int G_iGraphNum = -1;



void GraphNode(Node *,int,int,int);
void GraphNode_Set(int,int,int,char *,Node *);
void GraphNode_PrintVars();

void GraphNode_Order();
void GraphNode_Adjust();
void GraphNode_FillPos();

void GraphNode_Print();

struct NodePoint *NodeFind(struct NodePoint *,struct NodePoint *);
void NodeAdjust(struct NodePoint *,int tmp);

void PrintInfo(int,char *);
void InitVars();

int GetOffset(int,int,int);

char *itoa(int,char *);


int NodeExecute(Node *p){
  
    int fd;
    fd = open("ADT_graph.txt",O_WRONLY | O_CREAT | O_TRUNC,S_IRWXU  | S_IRWXG | S_IRWXO);

    if(fd < 0)
	printf("err in open\n");

    if(dup2(fd,STDOUT_FILENO) < 0)
	printf("err in dup2\n");
    	
    G_iNodeCount = -1;
    G_iNodeParent = -1;
    G_iMinNodeXValue = 0;
    InitVars();
    GraphNode(p,0,0,G_iNodeParent);

    GraphNode_Order();
    //GraphNode_PrintVars();
    GraphNode_Adjust();
    GraphNode_FillPos();
    //GraphNode_PrintVars();

    GraphNode_Print();
	
    close(fd);
    return 0;
}


void GraphNode(Node *p,int xoffset,int yoffset,int parent) {

    char sWord[MAX_NODE_TEXT_LEN];
    char *sNodeText;
    int i;

    G_iNodeCount++;

     if(parent!=-1) {
	 G_TreeNodePoint[parent].child[G_TreeNodePoint[parent].childnum]=G_iNodeCount;
	 G_TreeNodePoint[parent].childnum++; 
     }

     switch(p->type) {

	 case TYPE_CONTENT:
	     sprintf(sWord,"c(%g)",p->content);
	     sNodeText = sWord;
	     GraphNode_Set(xoffset,yoffset,parent,sNodeText,p);
	     break;

	 case TYPE_INDEX:
	     sprintf(sWord,"idx(%s)",G_Var[p->index].mark);
	     sNodeText = sWord;
	     GraphNode_Set(xoffset,yoffset,parent,sNodeText,p);
	     break;

	 case TYPE_OP:
	     switch(p->op.name) {
		 case WHILE: sNodeText = "while";  break;
		 case IF:     sNodeText = "if";    break;
		 case FOR:    sNodeText = "for";   break;
		 case FOREACH:sNodeText = "foreach";break;
		 case BREAK:  sNodeText = "break"; break;
	   	 case CONTINUE:sNodeText= "continue";break;
		 case PRINT:  sNodeText = "print"; break;
		 case ';':    sNodeText = "[;]";   break;		 
		 case '=':    sNodeText = "[=]";   break;
		 case UMINUS: sNodeText = "[_]";   break;
		 case '+':    sNodeText = "[+]";   break;
		 case '-':    sNodeText = "[-]";   break;
		 case '*':    sNodeText = "[*]";   break;
		 case '/':    sNodeText = "[/]";   break;
		 case '<':    sNodeText = "[<]";   break;
		 case '>':    sNodeText = "[>]";   break;
	         case '[':    sNodeText = "[]";    break;
		 case GE:    sNodeText = "[>=]";   break;
		 case LE:    sNodeText = "[<=]";   break;
		 case NE:    sNodeText = "[!=]";   break;
		 case EQ:    sNodeText = "[==]";   break;
		 case AND:    sNodeText = "[&&]";   break;
		 case OR:    sNodeText = "[||]";   break;
		 case ADD_T:    sNodeText = "[++v]";   break;
		 case MUS_T:    sNodeText = "[--v]";   break;
		 case ADD_TT:    sNodeText = "[v++]";   break;
		 case MUS_TT:    sNodeText = "[v--]";   break;

	     }
	     GraphNode_Set(xoffset,yoffset,parent,sNodeText,p);

	     for (i=0; i<p->op.num; i++) {
		 GraphNode(p->op.node[i], GetOffset(p->op.num,i+1,2), yoffset+1, GetNodeIndex(p));	       
	     }
	     break;
     }

}


void GraphNode_Set(int xoffset,int yoffset,int parent,char *text,Node *p) {

    int iBaseValue;

    if(parent <= -1)
	iBaseValue = 0;
    else
	iBaseValue = G_TreeNodePoint[parent].x;

    G_TreeNodePoint[G_iNodeCount].x = (iBaseValue + xoffset);
    G_TreeNodePoint[G_iNodeCount].y = yoffset;

    strcpy(G_TreeNodePoint[G_iNodeCount].text,text);

    iBaseValue = strlen(text);
    if(iBaseValue&1) {    
		G_TreeNodePoint[G_iNodeCount].textoffset1 = strlen(text)/2 ;    
		G_TreeNodePoint[G_iNodeCount].textoffset2 = strlen(text) - G_TreeNodePoint[G_iNodeCount].textoffset1 ;		    
    }    
    else {        
	G_TreeNodePoint[G_iNodeCount].textoffset1 = strlen(text)/2 - 1;	 
	G_TreeNodePoint[G_iNodeCount].textoffset2 = strlen(text) - G_TreeNodePoint[G_iNodeCount].textoffset1 ;		        
    }

     G_TreeNodePoint[G_iNodeCount].parent = parent;    
     G_TreeNodePoint[G_iNodeCount].idx = G_iNodeCount;	     
     G_TreeNodePoint[G_iNodeCount].node = p;
		         
     G_TreeNodePoint[G_iNodeCount].oppx = 0;		     
     G_TreeNodePoint[G_iNodeCount].oppx_mid = 0;
			         
     G_TreeNodePoint[G_iNodeCount].child[0] = 0;			     
     G_TreeNodePoint[G_iNodeCount].childnum = 0;


     if(G_TreeNodePoint[G_iNodeCount].x<G_iMinNodeXValue)
	 G_iMinNodeXValue=G_TreeNodePoint[G_iNodeCount].x;

}


void GraphNode_Order(){

    int i;
    int iDeep;

    G_iDeepCount = -1;

    for(i=0;i<=G_iNodeCount;i++){
	G_TreeNodePoint[i].x = G_TreeNodePoint[i].x - G_iMinNodeXValue +1;
	iDeep = G_TreeNodePoint[i].y;
	G_iTreeNodeOrderCount[iDeep]++;
	G_pTreeNodeOrder[iDeep][G_iTreeNodeOrderCount[iDeep]]=&G_TreeNodePoint[i];
	if(iDeep>G_iDeepCount)
	    G_iDeepCount=iDeep;
    }
}


void GraphNode_FillPos(){

    int iInt;
    int iBlank;
    int idx;
    int i,j;

    for(j = 0;j<=G_iDeepCount;j++) {
	iBlank = 0;
	for(i = 0;i <= G_iTreeNodeOrderCount[j];i++){
	    idx=G_pTreeNodeOrder[j][i]->idx;
	    if(i!=0) {
		iInt = (G_TreeNodePoint[idx].x - G_TreeNodePoint[G_pTreeNodeOrder[j][i-1]->idx].x) * NODE_WIDTH ;    
		iBlank = iInt - G_TreeNodePoint[idx].textoffset1 - G_TreeNodePoint[G_pTreeNodeOrder[j][i-1]->idx].textoffset2;
	    }
	    else {
		iInt = (G_TreeNodePoint[idx].x) * NODE_WIDTH ;  
		iBlank = iInt - G_TreeNodePoint[idx].textoffset1;
	    }
	     G_TreeNodePoint[idx].oppx = iInt ;    
	     G_TreeNodePoint[idx].oppx_mid = iBlank ; 
	}
    }

}


void GraphNode_Adjust() {

    int i,j;
    int tmp;

    for(i=G_iDeepCount;i>=0;i--)

	for(j=0;j<=G_iTreeNodeOrderCount[i];j++)

	    if(j!=G_iTreeNodeOrderCount[i]){

		if(j==0) {
		    tmp = G_pTreeNodeOrder[i][j]->textoffset1 / NODE_WIDTH ;
		    if(tmp >= 1)
			NodeAdjust(NodeFind(G_pTreeNodeOrder[i][j], G_pTreeNodeOrder[i][j+1]), tmp);
		}

		tmp = G_pTreeNodeOrder[i][j]->x - G_pTreeNodeOrder[i][j+1]->x + ( G_pTreeNodeOrder[i][j]->textoffset2 + G_pTreeNodeOrder[i][j+1]->textoffset1 ) / NODE_WIDTH + 1;
		if(tmp >= 1)
		    NodeAdjust(NodeFind(G_pTreeNodeOrder[i][j], G_pTreeNodeOrder[i][j+1]), tmp);

	    }

}

/*
struct NodePoint *NodeFind(struct NodePoint *p) {

    while(p->parent!=-1 && G_TreeNodePoint[p->parent].child[0]==p->idx) {    
	p=&G_TreeNodePoint[p->parent];	        
    }    
    return p;

}
*/


struct NodePoint * NodeFind(struct NodePoint * p1, struct NodePoint * p2) {
	        
    while(p2->parent!=-1 && p1->parent!=p2->parent) {
	p1=&G_TreeNodePoint[p1->parent];
	p2=&G_TreeNodePoint[p2->parent];			        
    }	    
    return p2;

}


void NodeAdjust(struct NodePoint *p,int tmp) {

    int i;
    if(p->childnum == 0)
	p->x += tmp;
    else {
	p->x += tmp;
	for(i = 0;i <= p->childnum-1;i++)
	    NodeAdjust(&G_TreeNodePoint[p->child[i]], tmp);
    }

}


void GraphNode_PrintVars() {

    printf("\n");
    int i,j;
    for(i=0;i<=G_iNodeCount;i++) {   
		printf("ID:%2d x:%2d y:%2d txt:%6s ofs:%d/%d rx:%2d b:%2d pa:%2d num:%2d child:",i,G_TreeNodePoint[i].x,G_TreeNodePoint[i].y,G_TreeNodePoint[i].text,G_TreeNodePoint[i].textoffset1,G_TreeNodePoint[i].textoffset2, G_TreeNodePoint[i].oppx,G_TreeNodePoint[i].oppx_mid,G_TreeNodePoint[i].parent,G_TreeNodePoint[i].childnum);
		for(j=0;j<=G_TreeNodePoint[i].childnum-1;j++)     
		    printf("%d ",G_TreeNodePoint[i].child[j]);
		printf("\n");
    }
    printf("\n");
}













void GraphNode_Print() {

    G_iGraphNum++;
    printf("<Graph %d>\n", G_iGraphNum);

    int idx;
    int i,j;

    for(j=0;j<=G_iDeepCount;j++) {


	for(i=0;i<=G_iTreeNodeOrderCount[j];i++) {
	    idx=G_pTreeNodeOrder[j][i]->idx;
	     PrintInfo( G_TreeNodePoint[idx].oppx_mid , G_TreeNodePoint[idx].text);
	}
	printf("\n");

	if(j==G_iDeepCount)return; 


	int iHave = 0;
	for(i=0;i<=G_iTreeNodeOrderCount[j];i++) {
	    idx=G_pTreeNodeOrder[j][i]->idx;
	    if(G_pTreeNodeOrder[j][i]->childnum) {
		if(iHave == 0)
		    PrintInfo( G_TreeNodePoint[idx].oppx , "|");
		else
		    PrintInfo( G_TreeNodePoint[idx].oppx - 1 , "|");
		iHave=1;
	    }
	    else
		PrintInfo( G_TreeNodePoint[idx].oppx , "");
	}
	printf("\n");


	for(i=0;i<=G_iTreeNodeOrderCount[j+1];i++) {
	    idx=G_pTreeNodeOrder[j+1][i]->idx;
	    int k;
	    if(i!=0 && G_pTreeNodeOrder[j+1][i]->parent==G_pTreeNodeOrder[j+1][i-1]->parent) {
		for(k=0;k<=G_pTreeNodeOrder[j+1][i]->oppx - 2; k++)
		    printf("-");
		printf("|");
	    }
	    else if(i == 0) {
		PrintInfo( G_TreeNodePoint[idx].oppx , "|");
	    }
	    else {
		PrintInfo( G_TreeNodePoint[idx].oppx - 1 , "|");
	    }
	}
	printf("\n");


	for(i=0;i<=G_iTreeNodeOrderCount[j+1];i++) {
	    idx=G_pTreeNodeOrder[j+1][i]->idx;
	    if(i==0)
		PrintInfo( G_TreeNodePoint[idx].oppx , "|");
	    else
		PrintInfo( G_TreeNodePoint[idx].oppx - 1 , "|");
	}
	printf("\n");

    }


}


int GetOffset(int count,int idx,int base) {

    if(count&1)
	return (idx-(count+1)/2)*base;
    else
	return idx*base-(count+1)*base/2;

}


int GetNodeIndex(Node *p) {

    int i;
    for(i=G_iNodeCount;i>=0;i--) {
	if(p==G_TreeNodePoint[i].node)return G_TreeNodePoint[i].idx;
    }

}


void InitVars() {


    int i,j;
    for(j=0;j<=MAX_TREE_DEEP-1;j++)
	for(i=0;i<=MAX_TREE_WIDTH-1;i++)
	    G_pTreeNodeOrder[j][i]=0;


   
    for(i=0;i<=MAX_TREE_DEEP-1;i++)
	 G_iTreeNodeOrderCount[i]=-1;
}


void PrintInfo(int val,char *str) {

    char sInt[10];
    char sPrint[20];
    itoa(val,sInt);
    strcpy(sPrint,"%");
    strcat(sPrint,sInt);
    strcat(sPrint,"s");
    printf(sPrint,"");
    printf(str);

}


char *itoa(int n,char *buffer) {

    int i=0,j=0;
    int iTemp;
    char cTemp;

    do
    {
	iTemp=n%10;
	buffer[j++]=iTemp+'0';
	n=n/10;
    }while(n>0);

    for(i=0;i<j/2;i++)
    {
	cTemp = buffer[i];
	buffer[i]=buffer[j-i-1];
	buffer[j-i-1]=cTemp;
    }
    buffer[j]='\0';
    return buffer;

}





