#include<stdio.h>
#include<stdlib.h>

int main()
{
  int num, *m, *supera;
  double *xa, *da, *ra, *saldoa;
  double *xb, *rb, *saldob;

  scanf("%d", &num);

  m=malloc(num *sizeof(int));
  supera=malloc(num *sizeof(int));
  xa=malloc(num *sizeof(double));
  xb=malloc(num *sizeof(double));
  da=malloc(num *sizeof(double));
  ra=malloc(num *sizeof(double));
  rb=malloc(num *sizeof(double));
  saldoa=malloc(num *sizeof(double));
  saldob=malloc(num *sizeof(double));

  for(int i=0; i<num; i++){
    scanf("%lf %lf %lf %lf %lf %d", &xa[i], &da[i], &ra[i], &xb[i], &rb[i], &m[i]);
  }

  for(int i=0; i<num; i++){
    supera[i]=0;
    saldoa[i]=xa[i];
    saldob[i]=xb[i];
    for(int j=0; j<m[i]; j++){
      saldoa[i]*=1+(ra[i]/100);
      saldoa[i]+=da[i];
      saldob[i]*=1+(rb[i]/100);
      if(saldob[i]>saldoa[i]){
        supera[i]++;
      }
    }
  }

  for(int i=0; i<num; i++){
    if(ra[i]>rb[i]){
      printf("\nRendimento de B invalido");
    }
    else if(m[i]-supera[i]>=supera[i]){
      printf("\n%.2lf %.2lf B nao supera A", saldoa[i], saldob[i]);
    }
    else
      printf("\n%.2lf %.2lf %d", saldoa[i], saldob[i], supera[i]);

}

  free(m);
  free(supera);
  free(xa);
  free(xb);
  free(da);
  free(ra);
  free(rb);
  free(saldoa);
  free(saldob);

    return 0;
}
