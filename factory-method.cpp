#include <iostream>
using namespace std;

//клас продукту//
class IMessage {
public:
    virtual void show() const = 0;
    virtual ~IMessage() = default;
};
// конкретні продукти//
class HelloMessage : public IMessage {
public:
    void show() const override {
        cout << "Hello" << endl;
    }
};
class GoodbyeMessage : public IMessage {
public:
    void show() const override {
        cout << "Goodbye" << endl;
    }
};
// Фабричний метод //
IMessage* createMessage(const string& type) {
    if (type == "hello") {
        return new HelloMessage();
    }
    else if (type == "goodbye") {
        return new GoodbyeMessage();
    }
    else {
        return nullptr;
    }
}
int main() {
    IMessage* msg1 = createMessage("hello");
    IMessage* msg2 = createMessage("goodbye");

    if (msg1) msg1->show();
    if (msg2) msg2->show();
    return 0;
}