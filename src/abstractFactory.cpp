#include <iostream>
#include <string>
using namespace std;

// 抽象产品类 Button
class Button {
public:
    virtual void paint() = 0; // 纯虚函数，用于子类覆盖
    virtual ~Button() {}
};

// 具体产品类 WinButton
class WinButton : public Button {
public:
    void paint() override {
        cout << "Windows Button\n";
    }
};

// 具体产品类 MacButton
class MacButton : public Button {
public:
    void paint() override {
        cout << "Mac Button\n";
    }
};

// 抽象产品类 Checkbox
class Checkbox {
public:
    virtual void paint() = 0; // 纯虚函数，用于子类覆盖
    virtual ~Checkbox() {}
};

// 具体产品类 WinCheckbox
class WinCheckbox : public Checkbox {
public:
    void paint() override {
        cout << "Windows Checkbox\n";
    }
};

// 具体产品类 MacCheckbox
class MacCheckbox : public Checkbox {
public:
    void paint() override {
        cout << "Mac Checkbox\n";
    }
};


// 抽象工厂类 GUIFactory
class GUIFactory {
public:
    virtual Button* createButton() = 0;
    virtual Checkbox* createCheckbox() = 0;
    virtual ~GUIFactory() {}
};

// 具体工厂类 WinFactory
class WinFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new WinButton();
    }
    Checkbox* createCheckbox() override {
        return new WinCheckbox();
    }
};

// 具体工厂类 MacFactory
class MacFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new MacButton();
    }
    Checkbox* createCheckbox() override {
        return new MacCheckbox();
    }
};
int main() {
    GUIFactory* factory;
    Button* button;
    Checkbox* checkbox;

    // 假设根据不同的环境设置，可以在这里选择不同的工厂
    factory = new WinFactory();

    // 通过工厂创建按钮
    button = factory->createButton();
    button->paint(); // 输出：Windows Button

    // 通过工厂创建复选框
    checkbox = factory->createCheckbox();
    checkbox->paint(); // 输出: Windows Checkbox

    // 清理资源
    delete button;
    delete checkbox;
    delete factory;

    // 这里为了示例简洁，没有使用智能指针; 在实际应用中应当考虑使用智能指针管理动态分配的资源
    return 0;
}
