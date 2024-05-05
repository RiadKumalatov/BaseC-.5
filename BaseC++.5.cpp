#include <iostream>
#include <string>

class Counter {
private:
    int value;

public:
    Counter(int initialValue = 1) : value(initialValue) {}

    void increment() {
        ++value;
    }

    void decrement() {
        --value;
    }

    int getCurrentValue() const {
        return value;
    }
};

int main() {
    std::string response;
    std::cout << "Do you want to specify the initial value of the counter? Enter yes or no: ";
    std::getline(std::cin, response);

    int initialValue = 1;
    if (response == "yes") {
        std::cout << "Enter the initial value of the counter: ";
        std::cin >> initialValue;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    Counter counter(initialValue);

    char command;
    while (true) {
        std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
        std::cin >> command;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (command) {
        case '+':
            counter.increment();
            break;
        case '-':
            counter.decrement();
            break;
        case '=':
            std::cout << counter.getCurrentValue() << std::endl;
            break;
        case 'x':
            std::cout << "�� ��������!" << std::endl;
            return 0;
        default:
            std::cout << "�������� �������. ���������� ��� ���." << std::endl;
            continue;
        }
    }
}
