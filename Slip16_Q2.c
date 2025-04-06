/*Q 2) Write a program to sort n randomly generated elements using Heapsort method.*/

#include<stdio.h>
#include<stdlib.h>
int a[20],i,n;
void accept()
 {
    printf("Enter the data:");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
}
void display()
{
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);

}
void heapify(int a[],int top,int last)
{
int p=a[top],j,r,temp;
    j=2*top+1;
   
    if(a[j]<a[j+1]&&j<last)
    {
       j=j+1;
    }

    if(p<a[j]&&j<=last)
    { 
        temp=a[top];
        a[top]=a[j];
        a[j]=temp;
        heapify(a,j,last);
    }
}

void buildheap(int a[],int n)
{   
    int i;
    for(i=n/2-1;i>=0;i--)
      heapify(a,i,n-1);
}

void swap(int a[],int n)
{
    int temp,top=0,last;
    buildheap(a,n);
    printf("\nInitial heap::");
    display();

    for(last=n-1;last>=1;last--)
    {
        temp=a[top];
        a[top]=a[last];
        a[last]=temp;
        printf("\nAfter Iteration %d ::",n-last);
        display(a,n);
        heapify(a,top,last-1);
    }
}
void main()
{
    printf("Enter limit:");
    scanf("%d",&n);
    accept();
    swap(a,n);

}