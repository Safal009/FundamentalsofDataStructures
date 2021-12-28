#include<iostream>
#include<stdlib.h>
#include<conio.h>
#define SIZE 5
using namespace std;
class deque
{
int queue[SIZE];
int L,R;
public:
deque()//constructor for initializing values
{
L = -1;
R = -1;
}
void insert_r(int x)// inserting in the right side
{
if(L == (R+1)%SIZE)// checking for the overflow condition
{
printf("\nQueue Overflow");
}
else if(R == -1)// if right is pointing to the
{ // null value make left and right
L = 0; // to point to starting point
R = 0; // means Q is free
queue[R] = x;
}
else // if R is pointing to any
{ // position move to next
R = (R+1) %SIZE; // position by using this formula
queue[R] = x;
}
}
void insert_L(int x)// inserting in the left side
{
if(L == (R+1)%SIZE)// checking for the overflow condition
{
printf("\nQueue Overflow");
}
else if(L == -1)// if left is pointing to the
{ // null value make left and right
L = 0; // to point to starting point
R = 0; // means Q is free
queue[R] = x;
}
else // if L is pointing to any
{ // position move to next
L = (L+SIZE-1) %SIZE; // position by using this formula
queue[L] = x;
}
}
int delete_r()
{
int x;
if(L == -1)//checking for underflow condition
{
printf("\nQueue Underflow");
}
else if(L == R)// if both the pointers are pointing to
{ //same position , means only one element is
x = queue[L]; //available in the Q
L = -1; //delete the element and make the L&R to
R = -1; //point to -1
}
else //normal deletion
{
x = queue[R];
R = (R+SIZE-1)%SIZE;
}
return x;
}
int delete_L()
{
int x;
if(L == -1) //checking for underflow condition
{
printf("\nQueue Underflow");
}
else if(L == R)// if both the pointers are pointing to
{
x = queue[L]; //same position , means only one element is
L = -1; //available in the Q
R = -1; //delete the element and make the L&R to point to -1
}
else //normal deletion
{
x = queue[L];
L = (L+1)%SIZE;
}
return x;
}
void display()
{ int i;
if(L<=R)
{
for(i=L;i<=R;i++)
cout<<queue[i]<<"-->\t";
}
else
{
for(i=0;i<=R;i++)
cout<<queue[i]<<"-->\t";
for(i=L;i<SIZE;i++)
cout<<queue[i]<<"-->\t";
}
}
};
int main()
{
deque d;
char choice;
int x;
while(1)
{
printf("\n1: Insert From Left \n");
printf("2: Insert From Right\n");
printf("3: Delete From left\n");
printf("4: Delete From Right\n");
printf("5: Display\n");
printf("6: Exit Program\n");
printf("Enter Your Choice:");
cin>>choice;
switch(choice)
{
case '1':
printf("Enter Integer Data :");
cin>>x;
d.insert_L(x);
break;
case '2':
printf("Enter Integer Data :");
cin>>x;
d.insert_r(x);
break;
case '3':
printf("Deleted Data From Front End:---- %d\n",d.delete_L());
break;
case '4':
printf("Deleted Data From Back End:---- %d\n",d.delete_r());
break;
case '6':
exit(0);
break;
case '5':d.display();
break;
}
}
return 0;
}
