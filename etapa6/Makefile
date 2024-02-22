etapa5: y.tab.o lex.yy.o hash.o ast.o semantic.o tac.o main.o
	gcc -Wall -o etapa5 y.tab.o lex.yy.o hash.o ast.o semantic.o tac.o main.o

main.o:
	gcc -Wall -c main.c

tac.o:
	gcc -Wall -c tac.c

semantic.o:
	gcc -Wall -c semantic.c

hash.o: hash.c
	gcc -Wall -c hash.c

ast.o: ast.c
	gcc -Wall -c ast.c

y.tab.o: y.tab.c
	gcc -Wall -c y.tab.c

y.tab.c: parser.y
	yacc -Wall -d -v parser.y

lex.yy.o: lex.yy.c
	gcc -Wall -c lex.yy.c

lex.yy.c: scanner.l
	flex --header-file=lex.yy.h scanner.l

clean:
	rm -f *.o etapa5 lex.yy.c lex.yy.h y.tab.c y.tab.h y.output