
#include <iostream>
struct EventSystem {
    void (*handlers[100])(const std::string&);
    int count = 0;
};

void registerHandler(EventSystem& system, void(*handler)(const std::string&)) {
    if (system.count < 100) {
        system.handlers[system.count] = handler;
        system.count++;
    }
}

void triggerEvent(const EventSystem& system, const std::string& message) {
    for (int i = 0; i < system.count; ++i) {
        system.handlers[i](message);
    }
}

void onUserLogin(const std::string& message) {
    std::cout << "Пользователь вошёл в систему: " << message << std::endl;
}

void onUserLogout(const std::string& message) {
    std::cout << "Пользователь вышел из системы: " << message << std::endl;
}

void onError(const std::string& message) {
    std::cout << "Произошла ошибка: " << message << std::endl;
}
int main()
{
    setlocale(0, "rus");
    EventSystem system;
    registerHandler(system, onUserLogin);
    registerHandler(system, onUserLogout);
    registerHandler(system, onError);
    triggerEvent(system, "Тестовое сообщение");
}
