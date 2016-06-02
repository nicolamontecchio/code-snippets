#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

/*
  read matrix from tsv file;
  matrix is allocated, will need to be freed
  return 0 if succesfull, 1 otherwise
  output is written in N (n rows), M (n cols) and X (data)
*/
int read_txt_float_matrix(char *fpath, uint32_t *N, uint32_t *M, float **X)
{
  uint32_t C = 0;

  FILE *fp = fopen(fpath, "r");
  if(!fp)
  {
    fprintf(stderr, "cannot open %s for reading\n", fpath);
    return 1;
  }

  // number of columns
  rewind(fp);
  uint32_t first_line_len = 0;
  while(1)
  {
    char c = fgetc(fp);
    if(c == '\n')
    {
      C++;
      break;
    }
    else if(c == '\t')
      C++;
    first_line_len++;
  }
  rewind(fp);

  uint32_t n_max_rows = 4096;
  *X = (float *) malloc(sizeof(float) * n_max_rows * C);

  uint32_t i = 0;
  while(!feof(fp))
  {
    for(uint32_t j = 0; j < C; j++)
      fscanf(fp, "%f ", (*X) + i*C + j);
    i++;
    if(i == n_max_rows)
    {
      n_max_rows *= 2;
      *X = realloc(*X, sizeof(float) * n_max_rows * C);
    }
  }

  *N = i;
  *M = C;
  *X = realloc(*X, sizeof(float) * (*N) * C);

  fclose(fp);
  return 0;
}
