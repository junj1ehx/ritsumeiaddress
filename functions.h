#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define SIZE 128
#include<string.h>
#include<stdlib.h>
#include<stdio.h>


struct task{
    int id;
    char name[SIZE];
    char mail[SIZE];
    char group[SIZE];
	int sex;//male = 1,female = 2,undefined = 3
	struct task *next;
  };
int get_input();
void return_menu();
//main.c
void add(struct task **top,struct task **end);
//add.c
void print_list(struct task *head,struct task *end);
void delete_list(struct task **top,struct task **end,int num);
void clear_list(struct task **head, struct task **end);
//delete.c
void shift(char c[SIZE]);
void unshift(char c[SIZE]);
void code(struct task **top);
void decode(struct task **top);
void raw_import(struct task **top, struct task **end);
void raw_export(struct task *top,struct task *end);
//sort.c
void az_sort(struct task **head,struct task **end);
void group_sort(struct task **top, struct task **end);
void update(struct task **head,struct task **end);
void group_sort(struct task **head, struct task **end);
void group_find();
void name_find(struct task **top, struct task **end);
void sex_find(struct task **top, struct task **end);
//cipher.c
void csv_import(struct task **top,struct task **end);
void csv_export(struct task *top,struct task *end);
void txt_import(struct task **top, struct task **end);
void txt_export(struct task *top,struct task *end);
//csv.c
void fdelete();
fdelete.c
#endif
