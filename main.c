#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *edges;

  edges = new_matrix(4, 4);
  printf("Matrix 'edges' created\n");
  print_matrix(edges);
  printf("Matrix 'edges' printed\n");

  free_matrix( edges );
}  
