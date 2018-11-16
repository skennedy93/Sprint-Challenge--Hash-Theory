#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  Answer *answer = malloc(sizeof(Answer));

  if(length < 2) {
    return NULL;
  }

  for(int i = 0; i < length; i++) {
  hash_table_insert(ht, weights[i], i);
  }
  for(int i = 0; i < length; i++) {
    int ind = hash_table_retrieve(ht, limit - weights[i]);
    if(ind != -1) {
      if(i > ind) {
        answer->index_1 = i;
        answer->index_2 = ind;
      } else {
        answer->index_1 = ind;
        answer->index_2 = i;
      }
      destroy_hash_table(ht);
      return answer;
    }
  }
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}