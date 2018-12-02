#include <iostream>
#include <string.h>
#include <math.h>
#include <limits.h>

using namespace std;

struct Node{
  int data;
  Node *next;
};

struct Stack{
  Node *head;
  int size = 0;
  int topstack;
  void create();
  void close();
  void push(int);
  void display();
  int pop();
};
void Stack::display()
  {
    Node *temp=new Node;
    temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<" ";
      temp=temp->next;
    }
  }

void Stack::create(){
  head = NULL;
}
void Stack::close(){
  Node *p;
  while(head){
    p = head;
    head = head->next;
    delete p;
  }
}

void Stack::push(int newdata){
  Node *newnode = new Node;
  newnode->data = newdata;
  newnode->next = head;
  head = newnode;
  topstack = newdata;
  size++;
}

int Stack::pop(){
  Node *topnode;
  int temp;
  topnode = head;
  head = head->next;
  if(head == NULL){
    topstack = 122121;
  }
  else{
      topstack = head->data;
  }

  temp = topnode->data;
  delete topnode;
  size--;
  return temp;

}



void cal(Stack &table,Stack &player1,Stack &player2,Stack &bin);
int main(){
  Stack table;
  Stack player1;
  Stack player2;
  Stack bin;
  int tcount;
  int tvalue;
  int pcount;
  int pvalue;

  cin>>tcount>>pcount;

  table.create();
  for(int i = 0;i<tcount;i++){
    cin>>tvalue;
    table.push(tvalue);
  }
  player1.create();
  for(int i = 0;i<pcount;i++){
    cin>>pvalue;
    player1.push(pvalue);
  }
    player2.create();
  for(int i = 0;i<pcount;i++){
    cin>>pvalue;
    player2.push(pvalue);
  }

  bin.create();
  cout<<"table:";
  table.display();
  cout<<endl;
  cout<<"player1:";
  player1.display();
  cout<<endl;
  cout<<"player2:";
  player2.display();
  cout<<endl;

for(int i = 0;i<tcount;i++){
  if(player1.size != 0 && player2.size != 0){
  if(i%2 == 0){
    cal(table,player1,player2,bin);
    cout<<"table:";
    table.display();

    cout<<endl;
      cout<<"player1:";
      player1.display();

      cout<<endl;
      cout<<"player2:";
      player2.display();
      cout<<endl;
      cout<<"bin:";
      bin.display();
      cout<<endl;
      cout<<bin.size<<endl;
  }
  else if(i%2 ==1){
    cal(table,player2,player1,bin);
    cout<<"table:";
    table.display();

    cout<<endl;
      cout<<"player1:";
      player1.display();

      cout<<endl;
      cout<<"player2:";
      player2.display();
      cout<<endl;
      cout<<"bin:";
      bin.display();
      cout<<endl;
      cout<<bin.size<<endl;
  }
}
}




  table.close();
  player1.close();
  player2.close();
  return EXIT_SUCCESS;
}
void cal(Stack &table,Stack &player1,Stack &player2,Stack &bin){
  int x;
  if(table.topstack < 0){
      x = fabs(table.topstack);
      if(x>player1.size){
        x = player1.size;
      }

        while( x != 0){
        if(player1.topstack > player2.topstack){
          player2.push(player1.pop());
        }
        else if(player1.topstack <= player2.topstack){
          bin.push(player1.pop());
        }
        x--;

    }
      table.pop();

    }
    else if(table.topstack > 0){
        x = table.topstack;
        if(x>player2.size){
          x = player2.size;
        }

          while( x != 0){
          if(player2.topstack > player1.topstack){
            player1.push(player2.pop());
          }
          else if(player2.topstack <= player1.topstack){
            bin.push(player2.pop());
          }
          x--;
        }

        table.pop();

    }
}
