#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pipe1[2],pipe2[2],pipe3[2],pipe4[2],pipe5[2],pipe6[2],pipe7[2],pipe8[2],pipe9[2],pipe10[2];
    pipe(pipe1);pipe(pipe2);pipe(pipe3);pipe(pipe4);pipe(pipe5);pipe(pipe6);pipe(pipe7);pipe(pipe8);pipe(pipe9);pipe(pipe10);
    int child1=fork();
    if(child1==0)
    {
        int i=0;
        int j=100;
        int sum1=0;
        for(i;i<=j;i++)
        {
            sum1=sum1+i;
        }
        write(pipe1[1],&sum1,sizeof(sum1));
    }
    else
    {
        int child2=fork();
        if(child2==0)
        {
            int i=101;
            int j=200;
            int sum2=0;
            for(i;i<=j;i++)
            {
                sum2=sum2+i;
            }
            write(pipe2[1],&sum2,sizeof(sum2));
          }
          else
          {
              int child3=fork();
              if(child3==0)
              {
                int i=201;
                int j=300;
                int sum3=0;
                for(i;i<=j;i++)
                {
                    sum3=sum3+i;
                }
                write(pipe3[1],&sum3,sizeof(sum3));
              }
              else
              {
                  int child4=fork();
                  if(child4==0)
                  {
                    int i=301;
                    int j=400;
                    int sum4=0;
                    for(i;i<=j;i++)
                    {
                        sum4=sum4+i;
                    }
                    write(pipe4[1],&sum4,sizeof(sum4));
                  }
                  else
                  {
                      int child5=fork();
                      if(child5==0)
                      {
                        int i=401;
                        int j=500;
                        int sum5=0;
                        for(i;i<=j;i++)
                        {
                            sum5=sum5+i;
                        }
                        write(pipe5[1],&sum5,sizeof(sum5));
                      }
                      else
                      {
                          int child6=fork();
                          if(child6==0)
                          {
                            int i=501;
                            int j=600;
                            int sum6=0;
                            for(i;i<=j;i++)
                            {
                                sum6=sum6+i;
                            }
                            write(pipe6[1],&sum6,sizeof(sum6));
                          }
                          else
                          {
                              int child7=fork();
                              if(child7==0)
                              {
                                int i=601;
                                int j=700;
                                int sum7=0;
                                for(i;i<=j;i++)
                                {
                                    sum7=sum7+i;
                                }
                                write(pipe7[1],&sum7,sizeof(sum7));
                              }
                              else
                              {
                                  int child8=fork();
                                  if(child8==0)
                                  {
                                    int i=701;
                                    int j=800;
                                    int sum8=0;
                                    for(i;i<=j;i++)
                                    {
                                        sum8=sum8+i;
                                    }
                                    write(pipe8[1],&sum8,sizeof(sum8));
                                  }
                                  else
                                  {
                                      int child9=fork();
                                      if(child9==0)
                                      {
                                        int i=801;
                                        int j=900;
                                        int sum9=0;
                                        for(i;i<=j;i++)
                                        {
                                            sum9=sum9+i;
                                        }
                                        write(pipe9[1],&sum9,sizeof(sum9));
                                      }
                                      else
                                      {
                                          int child10=fork();
                                          if(child10==0)
                                          {
                                            int i=901;
                                            int j=1000;
                                            int sum10=0;
                                            for(i;i<=j;i++)
                                            {
                                                sum10=sum10+i;
                                            }
                                            write(pipe10[1],&sum10,sizeof(sum10));
                                          }
                                          else
                                          {
                                              wait(NULL);wait(NULL);wait(NULL);
                                              wait(NULL);wait(NULL);wait(NULL);
                                              wait(NULL);wait(NULL);wait(NULL);
                                              wait(NULL);

                                              int sum1;int sum2;int sum3;int sum4;int sum5;int sum6;int sum7;int sum8;int sum9;int sum10;
											  int total_sum=0;
                                              read(pipe1[0],&sum1,sizeof(sum1));
                                              read(pipe2[0],&sum2,sizeof(sum2));
                                              read(pipe3[0],&sum3,sizeof(sum3));
                                              read(pipe4[0],&sum4,sizeof(sum4));
                                              read(pipe5[0],&sum5,sizeof(sum5));
                                              read(pipe6[0],&sum6,sizeof(sum6));
                                              read(pipe7[0],&sum7,sizeof(sum7));
                                              read(pipe8[0],&sum8,sizeof(sum8));
                                              read(pipe9[0],&sum9,sizeof(sum9));
                                              read(pipe10[0],&sum10,sizeof(sum10));
                                              total_sum=sum1+sum2+sum3+sum4+sum5+sum6+sum7+sum8+sum9+sum10;
                                              printf("%d",total_sum);
											  printf("\n");
                                          }
                                      }
                                  }
                              }
                          }
                      }
                  }
              }
          }
      }
}
