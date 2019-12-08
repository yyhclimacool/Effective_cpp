#include <iostream>
#include <string>

using namespace std;

void logCall(const std::string &name) {
  cout << "name:" << name << endl;
}

class Customer {
public:
  Customer() = default;
  Customer(const string &name) : name(name) {}
  Customer(const Customer &rhs) : name(rhs.name) {
    logCall("Calling Copy Constructor"); 
  }
  Customer &operator=(const Customer &rhs) {
    name = rhs.name;
    logCall("Calling Copy Assignment");
    return *this;
  }
  virtual ~Customer() = default;
  string name;
};

class PriorityCustomer : public Customer {
public:
  PriorityCustomer() = default;
  PriorityCustomer(const string &name, int prio)
    : Customer(name), priority(prio) {}

  PriorityCustomer(const PriorityCustomer &rhs) 
    : Customer(rhs), priority(rhs.priority) {}

  PriorityCustomer &operator=(const PriorityCustomer &rhs) {
    Customer::operator=(rhs);
    priority = rhs.priority;
    return *this;
  }
  
  ~PriorityCustomer() = default;

  int priority;
};

int main() {
  PriorityCustomer pc {"kevin", 16};
  PriorityCustomer default_pc;
  default_pc = pc;
  PriorityCustomer copy_pc(pc);
}
