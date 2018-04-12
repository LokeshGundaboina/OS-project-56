#include<iostream>
#include<conio.h>
using namespace std;
int n;
int arrtime[20], burtime[20], comtime[20]={0};
int qt, rqi[20]={0}, c=0, st, flg=0;
int tm=0, che=0, pnt=0, btm[20]={0}, tt, wt;
float att, awt;
void fun01(int pnt,int tm)
{
    for(int x=pnt+1;x<n;x++)
	{
       if(arrtime[x]<=tm)
	   {
          rqi[che]=x+1;
          che++;
	   }
    }
}
void fun02(int pnt, int tm)
{
    for(int x=pnt+1;x<n;x++)
	{
       int fl=0;
       for(int y=0;y<che;y++)
	   {
          if(rqi[y]==x+1)
		  {
             fl++;
		  }
	   }
       if(arrtime[x]<=tm && fl==0 && btm[x]!=0)
	   {
          rqi[che]=x+1;
          che++;
	   }
    }
}
void AddQue(int pnt)
{
    rqi[che]=pnt+1;
    che++;
}
main()
{
cout<<"Enter the no of processes";
cin>>n;
for(int x=0;x<n;x++)
{
    cout<<"\nEnter Process "<<x+1<<ends<<"Arrival Time=";
    cin>>arrtime[x];
    cout<<"\nEnter Process "<<x+1<<ends<<"Burst Time=";
    cin>>burtime[x];
    btm[x]=burtime[x];
}
cout<<"\nEnter time quantum:";
cin>>qt;
//cout<<endl<<"GANTT CHART"<<endl<<at[0];
do{
    if(flg==0)
	{
       st=arrtime[0];
       if(btm[0]<=qt)
	   {
          tm=st+btm[0];
          btm[0]=0;
          fun01(pnt,tm);
	   }
       else
	   {
          btm[0]=btm[0]-qt;
          tm=st+qt;
          fun01(pnt,tm);
          AddQue(pnt);
		}
    }
    else
	{
       pnt=rqi[0]-1;
       st=tm;
       for(int x=0;x<che && che!=1;x++)
	   {
          rqi[x]=rqi[x+1];
	   }
       che--;
       if(btm[pnt]<=qt)
	   {
          tm=st+btm[pnt];
          btm[pnt]=0;
          fun02(pnt, tm);
	   }
       else
	   {
         btm[pnt]=btm[pnt]-qt;
          tm=st+qt;
          fun02(pnt, tm);
          AddQue(pnt);
	    }
    }
       if(btm[pnt]==0)
	   {
       comtime[pnt]=tm;
       }
   flg++;
//   cout<<"]-P"<<pnt+1<<"-["<<tm;
}while(che!=0);
cout<<"\n\nPROCESS\t Arrival Time\t Burst Time\t Waiting Time\t  Turn Around Time\n";
for(int x=0;x<n;x++)
{
    tt=comtime[x]-arrtime[x];
    wt=tt-burtime[x];
    cout<<"P"<<x+1<<"     \t "<<arrtime[x]<<"          \t "<<burtime[x];
	cout<<"                  "<<wt<<"                   \t "<<tt<<"\n"<<endl;
    awt=awt+wt;
    att=att+tt;
}
for(int x=0;x<n;x++)
{
tt=comtime[x]-arrtime[x];
wt=tt-burtime[x];
cout<<"The total time process  P"<<x+1<<"  waiting in the queue for the processor is "<<wt<<endl;	
}
cout<<"\nAverage Turn Around Time: "<<att/n<<"\nAverage Waiting Time: "<<awt/n;
}
