gcc:
	gcc -o sat sat.c

run:
	./sat ${n}

bool2cnf:
	flex ./bool2cnf-20110304/scan.l
	bison ./bool2cnf-20110304/parse.y
	cc ./bool2cnf-20110304/parse.tab.c ./bool2cnf-20110304/trans.c -lfl
	./bool2cnf-20110304/a.out < ${inputFile} > ${outputFile}

minisatSolver:
	./minisat/core/minisat ${file} -no-luby -rinc=1.5 -phase-saving=0 -rnd-freq=0.02 > ${result}