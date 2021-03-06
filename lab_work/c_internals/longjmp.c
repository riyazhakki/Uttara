/* longjmp.c: Implement the simple program to demonstrate jumps in c */

# include <stdio.h>
# include <setjmp.h>

jmp_buf main_proc;

main (int argc, char * argv[] ){
	int val;
	if (argc > 1) sscanf (argv [1], "%d", &val);
	else val = 1;
	switch (setjmp (main_proc)){
		case 0: printf ("did setjmp\n"); break;
		case 1: val = 0; printf ("came from 1\n"); break;
		case 2: val = 0; printf ("came from 2\n"); break;
	}
	if (val) {
		printf ("invoking sub1\n");
		sub1 (val);
		printf ("returned from sub1\n");
	}
}

sub1 (int val) {
	if (val == 1)
		longjmp (main_proc, 1);
	printf ("invoking sub2 \n");
	sub2 (val);
	printf ("returned from sub2 \n");
}

sub2 ( int val ) {
	if (val == 2) 
		longjmp (main_proc, 2);
	printf ("did not take longjmp \n");
}
