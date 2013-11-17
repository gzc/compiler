#include <curses.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INTERVAL 2
#define MAX_FILE_N 10
int N_FILES = 0;
char* files[MAX_FILE_N];

void lex_analysis();
void syn_analisis();
void sem_check();
void gene_code();

void choosefile(const int line);

void file_init(WINDOW * win);
void showstar(WINDOW * win, const int line);
int main(void)
{
    int key;
    int quit = 0;
    MEVENT mouse;
    WINDOW * win;

    initscr();
    raw();
    start_color();
    init_pair(1,COLOR_BLACK,COLOR_BLUE);
    init_pair(2,COLOR_MAGENTA,COLOR_BLUE); 

    win = newwin(30, 100, 5, 3);/*this must do before keypad*/
    keypad(win, TRUE);         /*then use win.*/

    attron(COLOR_PAIR(1));
    mousemask(BUTTON1_CLICKED | BUTTON2_CLICKED, 0); /*set actions*/
    box(win, '|', '-');
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    file_init(win);
    mvwaddstr(win, 1, 37, "my compiler");
    mvwaddstr(win, 3, 73, "Lexical Analysis");
    mvwaddstr(win, 5, 73, "Syntax Analysis");
    mvwaddstr(win, 7, 73, "Semantic Check");
    mvwaddstr(win, 9, 73, "Generate Code");
    wrefresh(win);

    while (!quit)
    {
	key = wgetch(win);
	switch(key)
	{
	    case KEY_MOUSE :
		getmouse(&mouse); /*get mouse action*/

		if (!wenclose(win, mouse.y, mouse.x))
		    break; /*do nothing if not in window*/

		wmouse_trafo(win, &mouse.y, &mouse.x, FALSE);

		if ((73 <= mouse.x && mouse.x <= 80)
			&& (3 <= mouse.y && mouse.y <= 9))
		    showstar(win, mouse.y);

		if ( 10 <= mouse.x && mouse.x <= 18 )
		    choosefile(mouse.y);

		if (1 == mouse.y && 48 == mouse.x) /*Clicked 'X'*/
		    quit = 1;

		break;
	    case 'q' :
		quit = 1;
		break;
	    default :
		break;
	}
    }

    delwin(win);
    endwin();
    return 0;
}

void showstar(WINDOW * win, const int line)
{
    mvwaddch(win, line, 72, '*');

    switch(line)
    {
	case 3:
 	    lex_analysis();
	    break;

	case 5:
	    syn_analisis();
	    break;

	case 7:
	    sem_check();
	    break;

	case 9:
	    gene_code();
	    break;

	default:
	    break;

    }

    wrefresh(win);

}

void choosefile(const int line)
{
    int index = (line-3)/2;
    if(N_FILES < (index+1))
	return;

    char cmd[30] = "./mylang.sh ";
    strcat(cmd ,files[index]);
    system(cmd);
}


void file_init(WINDOW * win)
{
    system("./ls.sh");

    FILE *fp;
    fp = fopen("files.txt","r");

    if(!fp){
	printf("can't open files.txt");
	exit(-1);
    }

    int k = 0;
    while(k < MAX_FILE_N){
	char buf[20];
	fscanf(fp,"%s\n",buf);
	if( k!=0 && (strcmp(buf,files[k-1]) == 0))
	    break;
	if(strlen(buf) <= 0)
	    break;
	files[k] = (char*)malloc(strlen(buf));
	strcpy(files[k],buf);
	k++;
	N_FILES++;
    	mvwaddstr(win, 1+2*k, 10, buf);
    }

    fclose(fp);
    wrefresh(win);
}


void lex_analysis()
{
	


    return;
}


void syn_analisis()
{

    return;
}


void sem_check()
{

    return;
}


void gene_code()
{

    return;
}
