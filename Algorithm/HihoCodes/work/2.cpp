#include<stdio.h>
#include<math.h>
int main(){
        int a,b,i,n=0,x[7],y[7];
            scanf("%d",&a);
            for(i=1;i<=7;i++){
                    x[i-1]=a/(pow(10,7-i));
                        b=(int)pow(10,7-i);
                            a=a-x[i-1]*((int)pow(10,7-i));
            }
                for(i=0;i<=8;i++)printf("%d ",x[i]);
                /*i=8;
                 *  while(!x[i]){
                 *      n++;i--;}
                 *          n=9-n;
                 *              for(i=9;i>=1;i--)y[9-i]=x[i-1];
                 *                  while(!y[1])
                 *                      for(i=1;i<=9;i++)y[i-1]=y[i];
                 *                          for(i=1;i<=9;i++)b=y[i-1]*pow(10,9-i);
                 *                              printf("%d",b);
                 *                                  */return 0;
}



                 *  }
}
