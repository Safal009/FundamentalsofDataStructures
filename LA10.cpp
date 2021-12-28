#include<iostream>
#include<string.h>
using namespace std;
class parentheses
{    
    char st[20];
    int top;
    public:
     void push(char a);
     void pop();
     void check();
   
};
void parentheses::push(char a)
{      top++;  
      st[top]=a;                 
 }
void parentheses::pop()
{        
    top--;                        
    
}
void parentheses::check()
{   
    char ch[20];  
    int x=1,i=0;
     top=-1;
    cout<<"\nenter the expression: ";
     cin>>ch;
      while(i<strlen(ch))
      {   
     
   if((ch[i]=='{')||(ch[i]=='[')||(ch[i]=='('))
     {   
         push(ch[i]);                          
     }
      
         if(ch[i]=='}')
     {    
         if(st[top]=='{')
            pop();
         else
         {   
                 cout<<"\nopening brace '{' is not found";   
              }
          
     }
     if(ch[i]==']')
     {    if(st[top]=='[')
            pop();
       else
       {    
          cout<<"\nopening bracket '[' is not found";
          
           }
     }
      if(ch[i]==')')
     {    if(st[top]=='(')
            pop();
       else
       { 
          cout<<"\nopening parentheses '(' is not found";
        
         } 
     }
    i++;
      }
        if(top==-1)
        {   
            x=5; 
           cout<<"\n EXPRESSION IS WELL PARENTHESESED";
         
       }
        else
        {   while(top!=-1)
            {
            if(st[top]=='[')
            { 
                pop();  
                cout<<"\nclosing bracket ']' is not found";   
                
            }
            if(st[top]=='{')
            { 
                pop();  
                cout<<"\nclosing brace '}' is not found";  
            }
            if(st[top]=='(')
            { 
                pop();  
                cout<<"\nclosing parentheses ')' is not found";   
                
            }
            }
           
             cout<<"\n EXPRESSION IS NOT WELL PARENTHESESED";
       }
  
           
     
}

     int main()
     {    parentheses p;
          p.check();
        
        return 0;
       } 
