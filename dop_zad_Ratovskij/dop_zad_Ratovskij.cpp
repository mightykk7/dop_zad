
#include <iostream>
struct EventSystem {
    void (*handlers[100])();
    int count = 0;
};
void registerHandler(EventSystem& system, void(*handler)()) {
    system.handlers[system.count] = handler;
    system.count++;
}
void triggerEvent(const EventSystem& system) {
    for (int i = 0; i < 4; i++) {
        system.handlers[i]();
    }
}
void handler(const std::string& message) {
    std::cout << message << std::endl;
}
void onUserLogin() {
    std::cout << "Пользователь вошёл в систему" << std::endl;
}
void onUserLogout() {
    std::cout << "Пользователь вышел из системы" << std::endl;
}
void onError() {
    std::cout << "Произошла ошибка!" << std::endl;
}
int main()
{
    setlocale(0, "rus");
    EventSystem system;
    registerHandler(system, &onUserLogin);
    registerHandler(system, &onUserLogout);
    registerHandler(system, &onError);
    triggerEvent(system);
}
