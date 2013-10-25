#include<iostream>
using namespace std;
class Stack{
public:
	void append(int item);
	int pop();
	bool isEmpty();
	bool isFull();
	int head;
private:
	int data[100];
};
void Stack::append(int item){
	data[head]=item;
	head++;
}
int Stack::pop(){
	head--;
	return data[head];
}
bool Stack::isEmpty(){
	return(head==0);
}
bool Stack::isFull(){
	return(head==100);
}
int main(){
	Stack stack;
	Stack *p=&stack;
	p->head=0;
	if(!stack.isFull()){
	p->append(30);
	}
	int n;
	if(!stack.isEmpty()){
		n=stack.pop();
		cout<<"出栈数据为："<<n<<endl;
	}
	return 0;
}


