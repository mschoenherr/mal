all: step2_repl

step0_repl: step0_repl.c
	gcc -ledit -o step0_repl step0_repl.c

step1_read_print: step1_read_print.c
	gcc -ggdb -o step1_read_print step1_read_print.c reader.c printer.c types.c ll.c/ll.c linenoise/linenoise.c

step2_eval: step2_eval.c
	gcc `pkg-config --cflags --libs gmodule-2.0` -ggdb -o step2_eval step2_eval.c eval.c reader.c printer.c types.c ll.c/ll.c linenoise/linenoise.c
