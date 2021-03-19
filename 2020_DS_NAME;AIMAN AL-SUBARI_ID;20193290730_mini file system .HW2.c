#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#define ElementType char
using namespace std; 


// the structure for stacks
typedef struct tree_node {
	char name[256]; //
	int type; // 0 for directory, 1 for file;
	struct tree_node* nextsibling;// for brothers
	struct tree_node* firstchild; //for its first child
	struct tree_node* parent;  // ponits to it's parent
}
tnode;

//creat the root directory
tnode* create_root()
{
	tnode* root = (tnode*)malloc(sizeof(tnode));
	strcpy(root->name, "root");
	root->type = 0;
	root->parent = NULL;
	root->nextsibling = NULL;
	root->firstchild = NULL;
	return root;
	//to do
}

//list the files and sub-directories in the current_dir
void list_files(tnode* current_dir)
{
	for (tnode* p = current_dir->firstchild; p != NULL; p = p->nextsibling)
	{
		if (p->type == 0)
		{
			printf(" \033[32m %s \033[0m", p->name);
		}
		else
		{
			printf(" %s ", p->name);
		}
	}
	printf("\n");
	//to do
}

// creat a new file or dir in the current_dir
// type = 0,file; type =1 dir
tnode* make_dir(tnode* current_dir, char* name, int type)
{
	tnode* file = (tnode*)malloc(sizeof(tnode));
	strcpy(file->name, name);
	file->type = type;
	file->nextsibling = current_dir->firstchild;
	current_dir->firstchild = file;
	file->firstchild = NULL;
	file->parent = current_dir;
	return file;

}

void destroy_dir(tnode* node)
{
	if (node->firstchild == NULL)
		free(node);
	else
	{
		tnode* p, * q;
		for (p = node->firstchild, q = p->nextsibling; p != NULL; p = q, q = q->nextsibling)
		{
			destroy_dir(p);
			if (q == NULL)
				break;
		}
		free(node);
	}
}
// delete a file or dir specifid by subdir. command:del
void del_dir(tnode* current_dir, char* subdir)
{

	for (tnode* q = current_dir, *p = current_dir->firstchild;
		p != NULL; q = p, p = p->nextsibling)
	{
		if (strcmp(p->name, subdir) == 0)
		{
			if (q == current_dir)
			{
				q->firstchild = p->nextsibling;
			}
			else
			{
				q->nextsibling = p->nextsibling;
				destroy_dir(p);
			}
			return;
		}
	}
	printf("Directory %s does not exist.\n", subdir);
}
// change the current dir. command:cd
tnode* change_curdir(tnode* current_dir, char* subdir)
{
	tnode* change_curdir(tnode * current_dir, char* subdir);
	{

		if (strcmp(subdir, "..") == 0)
		{
			if (current_dir->parent != NULL)

				return current_dir->parent;
			else
				return current_dir;
		}
		for (tnode* p = current_dir->firstchild; p != NULL; p = p->nextsibling)
		{
			if (strcmp(p->name, subdir) == 0)
			{
				if (p->type)
					break;
				else
					return p;
			}

		}
		printf("Directory %s does not exist.\n", subdir);
		return NULL;
	}

}
int main
(int argc, char* argv[])
 {
 	printf("NAME:AIMAN AL-SUBARI\nID:20193290730\n");
	char cmd[100], para[100];
	tnode* root = create_root();
	tnode* cur_dir = root;
	do {

		printf(" %s >>", cur_dir->name);
		cin >> cmd;
		if (strcmp(cmd, "lct") == 0) /*this is for create lct (list)*/
		{
			list_files(cur_dir);
		}
		else if (strcmp(cmd, "build_drcty") == 0) { /*this is for create  a new directory */
			cin >> para;
			make_dir(cur_dir, para, 0);
		}
		else if (strcmp(cmd, "build file") == 0) { /* this is for create a new file*/
			cin >> para;
			make_dir(cur_dir, para, 1);
		}
		else if (strcmp(cmd, "change_crnt_dir") == 0) { /*this is for change the current directory*/
			cin >> para;
			tnode* tmp = change_curdir(cur_dir, para);
			if (tmp != NULL)
				cur_dir = tmp;
		}
		else if (strcmp(cmd, "omit") == 0) { /* this is for delete a subdirectory*/
			cin >> para;
			del_dir(cur_dir, para);
		}
		else if (strcmp(cmd, "exit") == 0) { /* this is for exit the file system*/
			break;
		}
	} while (1);
	return 1;
}
