#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  //Testing Matrix fxns
  struct matrix *edges;
  struct matrix *tester;

  edges = new_matrix(4, 4);
  printf("Matrix 'edges' created\n");
  print_matrix(edges);
  printf("Turning 'edges' into identity matrix...\n");
  ident(edges);
  print_matrix(edges);

  tester = new_matrix(4, 4);
  printf("Matrix 'tester' created\n");
  int i, j;
  for(i = 0; i < tester->rows; i++) { 
    for(j = 0; j < tester->cols; j++)
      tester->m[i][j] = i;
  }
  print_matrix(tester);

  printf("Multiplying 'edges' by 'tester'...\n");
  matrix_mult(edges, tester);
  print_matrix(tester);
  printf("Multiplying 'tester' by 5...\n");
  scalar_mult(5, tester);
  print_matrix(tester);

  free_matrix( edges );
  free_matrix( tester );

  //Drawing Pic
  screen s;
  color c;

  c.red = MAX_COLOR;
  c.green = MAX_COLOR;
  c.blue = MAX_COLOR;

  struct matrix *pic;
  pic = new_matrix(4,4);
}  
