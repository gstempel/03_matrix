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

  clear_screen(s);

  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = MAX_COLOR;

  struct matrix *pic;
  pic = new_matrix(4,4);
  pic->lastcol = 0;
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      pic->m[i][j] = 0.0;
    }
  }

  add_edge(pic, 0, 500, 0, 500, 0, 0);
  add_edge(pic, 500, 500, 0, 0, 0, 0);

  for(i = 50; i < 175; i++) {
    for(j = 0; j <25; j++) {
      add_edge(pic, i, j, 0, j, i, 0);
    }
  }

  for(i = 50; i < 175; i++) {
    for(j = 0; j <25; j++) {
      add_edge(pic, 500-i, j, 0, 500-j, i, 0);
    }
  }

  for(i = 50; i < 175; i++) {
    for(j = 0; j <25; j++) {
      add_edge(pic, 500-i, 500-j, 0, 500-j, 500-i, 0);
    }
  }

  for(i = 50; i < 175; i++) {
    for(j = 0; j <25; j++) {
      add_edge(pic, i, 500-j, 0, j, 500-i, 0);
    }
  }


  draw_lines(pic, s, c);

  save_extension(s, "image.png");
  display(s);
  free_matrix(pic);

}  
