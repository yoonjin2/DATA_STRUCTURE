#include <stdio.h>
#include "list.h"
//show list
void show( list *lst ) {
    node * t;
    for ( t = lst -> front -> next ; t != lst -> rear ; t = t -> next ) {
        printf ( "%d\n" , t -> key ) ;
    }
}
node* first( list *lst) {
	return lst -> front -> next;
}
node *front( list *lst) {
	return first(lst);
}
node* head ( list *lst) {
	return first(lst);
}


node* last ( list *lst) {
	return lst -> rear -> prev;
}
node *rear( list *lst) {
	return last(lst);
}

node *tail( list *lst) {
	return last(lst);
}

node*  top ( list *lst) {
	return last(lst);
}
