#include<iostream>
#include<ctype.h>
#include<string.h>
using namespace std;
class infixp
{
    char s[10],x,y,infix[20],postfix[20];
    int len,i,j,top;
    public:
            infixp()
            {
                top=-1;
                cout<<"Enter the infix expression";
                cin>>infix;
                len=strlen(infix);
                j=-1;
            }
            void push(char);
            char pop();
            void display();
            bool isempty();
            char stacktop();
            void convert();
            int priority(char);
};
void infixp::push(char c)
{
            top++;
            s[top]=c;
}

char infixp::pop()
{
            if(!isempty())
            {
                y=s[top];
                top--;
                return y;
            }
            else
                return -1;

}
void infixp::display()
{
    cout<<"Postfix Expression: "<<postfix;
}
bool infixp::isempty()
{
    if(top==-1)
        return true;
    else
        return false;
}
char infixp::stacktop()
{
        if(!isempty())
            return s[top];
        else
            return -1;

}
int infixp::priority(char c)
{
    switch(c)
    {
        case '^':return 3;
                break;
        case '*':
        case '/':return 2;
                break;
        case '+':
        case '-':return 1;
                 break;
        case '(':return 0;
                 break;
        default:return -1;
    }
}

void infixp::convert()
{
    char c;
    for(int i=0;i<len;i++)
    {
        c=infix[i];
        if(c=='(')
         {
              push(c);
         }  
        else if(c==')')
        {

            while(c!='(')
            {
                x=pop();
                postfix[++j]=x;
            }
           x= pop();
        }
        else if(isalnum(c))
        { 
            postfix[++j]=c;
        }
        else
            {
                    while(!isempty() && priority(c) <= priority(stacktop()))
                    {
                            x=pop();    
                            postfix[++j]=x;
                    }
                    push(c);
            }    
        }
        while(!isempty())
        {
            x=pop();
            postfix[++j]=x;
        }
        postfix[++j]='\0';
    

}
int main()
{
    infixp i;
    i.convert();
    i.display();
    return 0;
}
