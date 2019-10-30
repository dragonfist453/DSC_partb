all: graphical-tree datastructure-graphical

graphical-tree: tree_graphical.c btree.h
	gcc tree_graphical.c -lgraph -o tree_graphical
	
datastructure-graphical: ds_graph.c list.h
	gcc ds_graph.c -lgraph -o dsg
	
debug: ds_graph.c list.h
	gcc ds_graph.c -lgraph -g -o dsg
	gdb dsg

ds-bs: ds.c list.h
	gcc ds.c -o dsbs
	 		 	
clean: 
	rm tree_graphical dsg
		
