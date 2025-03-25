#include <iostream>
#include <ctime>
using namespace std;
struct Decanat {
    int workersamount;
    int worktime;
    int productivity;
};
struct Node {
    Decanat value;
    Node* nextElement;
};

struct LinkedList {
private:
    Node* head; 
    Node* tail; 
    int size;
public:
    
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

   
    void mypushback(Decanat& FACULTETS) {

        Node* newNode = new Node; 
        newNode->value = FACULTETS;
        newNode->nextElement = nullptr;
        if (head == nullptr) {
            
            head = newNode;
            tail = newNode;
        }

        else {
            tail->nextElement = newNode;
            tail = newNode;
        }
        size++;
    }
    void mypushfront(Decanat& FACULTETS) {
        Node* newNode = new Node; 
        newNode->value = FACULTETS;
        newNode->nextElement = head;
        head = newNode;
        if (tail == nullptr) {
          
            tail = newNode;
        }
       
        size++;
    }

    void display() {
        if (!head) {
            return;

        }
        Node* temp = head;
        int i = 0;
        while (temp != nullptr) {
            cout << "Number :" << i << " Workers amount : " << temp->value.workersamount << ", Work time : " << temp->value.worktime << ", Productivity : " << temp->value.productivity << endl;
            temp = temp->nextElement;
            i++;
        }
        cout << endl;
    }
    void mypopback() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
        }
        else if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            size = 0;
        }
        else {
            Node* temp = head;
            while (temp->nextElement != tail) {
                temp = temp->nextElement;
            }
            delete tail;
            tail = temp;
            tail->nextElement = nullptr;
            size--;
        }
    }
    void mypopfront() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        else {
            Node* temp = head;
            head = head->nextElement;
            delete temp;
        }
        size--;
    }
    int mysize() {
        return size;
    }
    Decanat myget(int index) {
        if (index < 0) {
            cout << "Index out of range." << endl;
            exit(1);
        }
        Node* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->nextElement;
        }
        return temp->value;
    }
    void clear() {
        while (head != nullptr) {
            mypopfront();
        
        }
    }
    

    ~LinkedList() {
        Node* current = head;
        Node* prev = nullptr;
        int i = 0;
        while (current != nullptr) {
            prev->nextElement = current->nextElement;
            delete current;
            prev = current;
            current = current->nextElement;
        }
    }
};
  

int main() {
    srand(time(NULL));
    LinkedList FACULTETS;
    clock_t startTime = clock();
   for (int i = 0; i < 50000; i++)
    {
        Decanat IPSA = { 100,5,90 };
        FACULTETS.mypushback(IPSA);
    }
    for (int i = 0; i < 10000; i++)
    {
        Decanat FIOT = { 50,5,90 };
        FACULTETS.mypushfront(FIOT);
    }
    for (int i = 0; i < 2000; i++)
    {
        int n = rand() % FACULTETS.mysize() + 1;
        FACULTETS.myget(n);
    }
    for (int i = 0; i < 5000; i++)
    {
        FACULTETS.mypopfront();
    }
    for (int i = 0; i < 5000; i++)
    {
        FACULTETS.mypopback();
    }
    clock_t endTime = clock();
    double seconds = (double(endTime - startTime)) / CLOCKS_PER_SEC;
    cout << endl << "Time of this algorithm is: " << seconds;
    
    return 0;
}
