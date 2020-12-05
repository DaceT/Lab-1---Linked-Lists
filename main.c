#include <stdio.h>

#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
  
  list_t *list = list_alloc();
  
   
  list_add_to_front(list, 8);
  
  list_add_to_back(list, 7);
  list_add_to_back(list, 1);
  list_add_to_back(list, 2);
  
  list_print(list);
  list_add_at_index(list, 3, 3);
  list_print(list);
  
  /*
  list_print(list);
  list_free(list);
  list_print(list);
  list_add_to_front(list, 8);
  list_add_to_back(list, 9);
  list_add_to_back(list, 1);
  list_add_to_back(list, 2);
  list_print(list);
  //list_print(list);
  int length = list_length(list);
  printf("List length: %d \n", length);
  int num = list_get_index_of(list, 2);
  printf("Index of elem 8: %d \n", num);
  elem elemRF = list_get_elem_at(list, 3);
  printf("elem at index 3: %d \n", elemRF);
  bool res = list_is_in(list, 9);
  printf("Boolean: %d \n", res);
  elem elemRF = list_remove_at_index(list, 3);
  printf("removed elem: %d \n", elemRF);
  list_print(list);
  
  list_add_at_index(list, 3, 3);
  list_print(list);  
  elem elemRB = list_remove_from_back(list);
  printf("removed elem: %d \n", elemRB);
  list_print(list);
  elem elemRF = list_remove_from_front(list);
  printf("removed elem: %d \n", elemRF);
  list_print(list);
  printf("Output: %p \n",list);
  */
  
  return 0;
}