clear
flex lexya_e.l
bison -d lexya_e.y
gcc -g -o  graph lexya_e.tab.c lex.yy.c graph.c
gcc -g -o  parser lexya_e.tab.c lex.yy.c parser.c
gcc -g -o  gui gui2.c -lcurses
