#include<stdio.h>
#include<stdbool.h>
#define size 5

void push();
const char* pop();
void display();
bool isfull();
bool isempty();
char item[8];
int top=-1;

int stk[size];
int choice;
void main(){
while(1){
   printf("\n 1. Push 2. Pop 3.Display 4. isFull 5. isEmpty");
   scanf("%d",&choice);
   switch(choice){
   case 1: push();break;
   case 2: printf("%s",pop());break;
   case 4: if(isfull()){printf("\n Overflow");}break;
   case 3: display();break;
   case 5: if(isempty()){printf("\n Underflow");} break;
   default: printf("Try Again");
   
}
}
}
bool isfull(){
  if(top+1>size-1){return true;}
  return false; 
}
bool isempty(){
  if(top==-1){return true;}
  return false;
}
void display(){
   if(isempty()){printf("Empty");return;}
else{
   for(int i=0;i<=top;i++){ printf("%d ",stk[i]);}}
   return;}
const char* pop(){
if(isempty()){return "Empty";}
else{
sprintf(item,"%d",stk[top]);
top--;
return item;} 
}

void push(){
   if(isfull()){printf("Stk overflow");return;}
   else{
   printf("Item????");
   top++;
   scanf("%d",&stk[top]);
   printf("Item added");
   }
   return;
}
