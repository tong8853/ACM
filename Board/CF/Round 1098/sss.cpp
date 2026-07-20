#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
const int m = 5;

int empty = m;
int full = 0;
std::mutex mtx;

void Ai() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        while (empty <= 0) {
            // 等待空位
        }
        empty--;
        std::cout << "A: 生产了一个产品, empty=" << empty << std::endl;
        full++;
        lock.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void B() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        while (full <= 0) {
            // 等待产品
        }
        full--;
        std::cout << "B: 消费了一个产品, full=" << full << std::endl;
        empty++;
        lock.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    std::thread t1(Ai);
    std::thread t2(B);

    std::this_thread::sleep_for(std::chrono::seconds(2));

    t1.detach();
    t2.detach();

    return 0;
}