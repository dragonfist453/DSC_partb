all: datastructure-graphical
	
datastructure-graphical: ds_graph.c list.h
	gcc ds_graph.c -lgraph -o dsg
	
debug: ds_graph.c list.h
	gcc ds_graph.c -lgraph -g -o dsg
	gdb dsg

clean: 
	rm dsg
		
