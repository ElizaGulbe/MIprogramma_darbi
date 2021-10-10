#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class Deque
{
    int  arr[1000];
    int  front;
    int  rear;
    int  size;
public :
    Deque(int size)
    {
        front = -1;
        rear = 0;
        this->size = size;
    }
 
    // Operations on Deque:
    void  insertfront(int key);
    void  insertrear(int key);
    void  deletefront();
    void  deleterear();
    bool  isFull();
    bool  isEmpty();
    int  getFront();
    int  getRear();
};
// Checks whether Deque is full or not.
bool Deque::isFull()
{
    return ((front == 0 && rear == size-1)||
            front == rear+1);
}
 
// Checks whether Deque is empty or not.
bool Deque::isEmpty ()
{
    return (front == -1);
}
 
// Inserts an element at front
void Deque::insertfront(int key) {
    // check whether Deque if  full or not
    if (isFull())
    {
        cout << "Overflow\n" << endl;
        return;
    }
 
    // If queue is initially empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
 
    // front is at first position of queue
    else if (front == 0)
        front = size - 1 ;
 
    else // decrement front end by '1'
        front = front-1;
 
    // insert current element into Deque
    arr[front] = key ;
}
 
// function to inset element at rear end
// of Deque.
void Deque ::insertrear(int key)
{
    if (isFull())
    {
        cout << " Overflow\n " << endl;
        return;
    }
 
    // If queue is initially empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
 
    // rear is at last position of queue
    else if (rear == size-1)
        rear = 0;
 
    // increment rear end by '1'
    else
        rear = rear+1;
 
    // insert current element into Deque
    arr[rear] = key ;
}
 
// Deletes element at front end of Deque
void Deque ::deletefront()
{
    // check whether Deque is empty or not
    if (isEmpty()) {
        cout << "Queue Underflow\n" << endl;
        return ;
    }
 
    // Deque has only one element
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else
        // back to initial position
        if (front == size -1)
            front = 0;
 
        else // increment front by '1' to remove current
            // front value from Deque
            front = front+1;
}
 
// Delete element at rear end of Deque
void Deque::deleterear()
{
    if (isEmpty())
    {
        cout << " Underflow\n" << endl ;
        return ;
    }
 
    // Deque has only one element
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = size-1;
    else
        rear = rear-1;
}
 
// Returns front element of Deque
int Deque::getFront()
{
    // check whether Deque is empty or not
    if (isEmpty())
    {
        cout << " Underflow\n" << endl;
        return -1 ;
    }
    return arr[front];
}
 
// function return rear element of Deque
int Deque::getRear()
{
    // check whether Deque is empty or not
    if(isEmpty() || rear < 0)
    {
        cout << " Underflow\n" << endl;
        return -1 ;
    }
    return arr[rear];
}


class Stack {
    int top;
public:
    int a[1000]; // Maximum size of Stack
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    bool isEmpty();
};
 
bool Stack::push(int x)
{
    if (top >= (1000 - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}
 
int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}
bool Stack::isEmpty()
{
    return (top < 0);
}

class Queue
{
    int a[1000];
    int rear;   //same as tail
    int front;  //same as head
  
    public:
    Queue()
    {
        rear = front = -1;
    }
    
    //declaring enqueue, dequeue and display functions
    void enqueue(int x);     
    int dequeue();
};

// function enqueue - to add data to queue
void Queue :: enqueue(int x)
{
    if(front == -1) {
        front++;
    }
    if( rear == 1000-1)
    {
        cout << "Queue is full";
    }
    else
    {
        a[++rear] = x;
    }
}
// function dequeue - to remove data from queue
int Queue :: dequeue()
{
    return a[++front];  // following approach [B], explained above
}
void createAndDisplayQueue(const vector<int> &initialValue){
    class Queue data;
    for(int i = 0 ; i < initialValue.size() ; i++) {
        data.enqueue(initialValue[i]); // pievieno vectoru stack
    }
    cout << "queue dequeue seciba" << endl; 
    for (int i = 0 ; i < initialValue.size() - 1 ; i++) {
        cout << data.dequeue() << " " << endl;
    }
}
void displayOpportunities(){
    cout << "Iespejamas darbibas ir: " << endl;
    cout << "1: Ievadit skaitlus" << endl;
    cout << "2: Rinda" << endl;
    cout << "3. Steks" << endl;
    cout << "4. Divi steki (Rinda)" << endl;
    cout << "5. Izvada skaitlu virkni" << endl;
    cout << "6. Beigt darbibu" << endl;
    cout << "ludzu ievadiet skaitli" << endl;
}
void displayList(vector<int> &initialValue) {
    string retVal = "[";
    for(int i = 0 ; i < initialValue.size(); i++) {
        if (i == initialValue.size() - 1) {
            retVal = retVal + to_string(initialValue[i]) + "]";
        } else {
            retVal = retVal + to_string(initialValue[i]) + ",";  
        }
        
    }
    
    cout << retVal << endl;  
}

void createAndDisplayStack(const vector<int> &initialValue){
    class Stack data;
    for(int i = 0 ; i < initialValue.size() ; i++) {
        data.push(initialValue[i]); // pievieno vectoru stack
    }
    cout << "Stack pop seciba" << endl; 
    for (int i = 0 ; i < initialValue.size() ; i++) {
        cout << data.pop() << " " << endl;
    }

}

void createAndDisplayDeque(const vector<int> &initialValue){
    class Deque data(initialValue.size());
    for(int i = 0 ; i < initialValue.size() ; i++) {
        data.insertfront(initialValue[i]); // pievieno vectoru Deque
    }
    cout << "Deque pop seciba" << endl; 
    for (int i = 0 ; i < initialValue.size() ; i++) {
        cout << data.getFront() << " " << endl; // izprinte front
        data.deletefront(); // izdzes front
    }
}

int switchcase(const int &inputData, vector<int> &initialValue) {
    switch (inputData) {
        case 1:
            cout << "ievadiet 1 skaitli" << endl; 
            int number;     // ievada pa vienam skaitlim lidz lietotajs vairs nevelas ievietot skaitli 
            cin >> number; 
            initialValue.push_back(number); 
            char response; 
            cout << "vai velaties ievadit vel vienu skaitli? y - Ja , n - ne" << endl;
            cin >> response;
            while(response == 'y') {
                cout << "ievadiet 1 skaitli" << endl; 
                cin >> number; 
                initialValue.push_back(number); 
                cout << "vai velaties ievadit vel vienu skaitli? y - Ja , n - ne" << endl;
                cin >> response;
            }
            return 1;
            break;
        case 2:
            createAndDisplayQueue(initialValue);
            return 1;
            break;
        case 3:
            createAndDisplayStack(initialValue);
            return 1;
            break;
        case 4:
            createAndDisplayDeque(initialValue);  
            return 1;
            break;
        case 5:
            displayList(initialValue);
            return 1;
            break;
        case 6:
            cout << "Programmas darbiba izbeigta" << endl; 
            return 0; 
        default:
            cout << "Nepareiza vertiba.Ludzu ievadiet vertibu no 1(ieskaitot) lidz 6(ieskaitot)" << endl;
            return 0;  
            break;
        }

}
int main(){
    vector<int> initialValue;
    for (int i = 4 ; i < 9 ; i++ ) {
        initialValue.push_back(i);
    } 
     while (1) {
        displayOpportunities();
        int inputData;
        cin >> inputData;
         if(switchcase(inputData,initialValue) == 0) break; 
    }
    return 0;
}