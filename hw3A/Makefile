all:stack.exe tree.exe

stack.exe:mystack.cpp node.cpp main_stack.cpp
	g++ -o stack.exe main_stack.cpp

tree.exe:Tnode.cpp main_tree.cpp Btree.cpp
	g++ -o tree.exe main_tree.cpp

clean:
	rm -rf stack.exe tree.exe tree_ans.txt stack_ans.txt
	