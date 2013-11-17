#include <curses.h>
#include <unistd.h>

void lex_analysis();
void syn_analisis();
void sem_check();
void gene_code();

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

    win = newwin(12, 60, 5, 3);/*this must do before keypad*/
    keypad(win, TRUE);         /*then use win.*/

    attron(COLOR_PAIR(1));
    mousemask(BUTTON1_CLICKED | BUTTON2_CLICKED, 0); /*set actions*/
    box(win, '|', '-');
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    mvwaddstr(win, 1, 27, "my compiler");
    mvwaddstr(win, 3, 3, "Lexical Analysis");
    mvwaddstr(win, 5, 3, "Syntax Analysis");
    mvwaddstr(win, 7, 3, "Semantic Check");
    mvwaddstr(win, 9, 3, "Generate Code");
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

		if ((3 <= mouse.x && mouse.x <= 8)
			&& (3 <= mouse.y && mouse.y <= 9))
		    showstar(win, mouse.y);

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
    mvwaddch(win, line, 2, '*');

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
