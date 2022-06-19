#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"
#include <time.h>
#define LEFT 0
#define RIGHT 1
int main()
{
	list numbers;
	init_list ( &numbers ); //init list
	list MS;
	init_list ( &MS );
	list *Q=malloc(sizeof(list)*2);
	init_list ( Q+LEFT );
	init_list ( Q+RIGHT);
	int N;
	scanf("%d",  &N);
	int i;
	int num;
	for ( i = 0 ; i < N ; i ++ ) {
		scanf("%d",&num);
		push ( &numbers , num );
		push ( Q+RIGHT, i+1 );
	}
	i=0;
	while(i<=N) {
		node *nd = index_node(&numbers,i);
		if(front(Q+RIGHT)->key==nd->key) {
			push (Q+LEFT, front(Q+RIGHT)->key);
			remove_item( Q+RIGHT , front(Q+RIGHT));
		} else if ( front(Q+RIGHT)->key> nd->key) {
			if( top  (&MS)->key!=nd->key) {
				puts("IMPOSSIBLE");
				return 0;
			} else {
				
				push(Q+LEFT,tail(&MS)->key);
				if(size(&MS)) {
					pop_item(&MS);
				}
			}
		} else {
			if(size(Q+RIGHT)) {
				push(&MS, front(Q+RIGHT)->key);
				remove_item(Q+RIGHT,front(Q+RIGHT));
				continue;
			}
		}
		i++;
		if(i==N) {
			printf("%s\n" , !size(&MS)?"POSSIBLE":"IMPOSSIBLE");
			return 0;
		} else {
			continue;
		}

	}
		
	puts("IMPOSSIBLE");
	return 0;
}
