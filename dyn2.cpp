#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct PrintJob {
    int priority;
    string clientName;
    int pages;
    int submissionTime;

    bool operator<(const PrintJob& other) const {
        return priority < other.priority;
    }
};

void simulatePrinterQueue() {
    priority_queue<PrintJob> printQueue;

    printQueue.push({3, "Клієнт A", 10, 1});
    printQueue.push({1, "Клієнт B", 5, 2});
    printQueue.push({4, "Клієнт C", 15, 3});
    printQueue.push({2, "Клієнт D", 7, 4});

    cout << "Черга друку:\n";
    while (!printQueue.empty()) {
        PrintJob job = printQueue.top();
        printQueue.pop();
        cout << "Друк для " << job.clientName << " з пріоритетом " << job.priority
             << " та кількістю сторінок " << job.pages << endl;
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    simulatePrinterQueue();
    return 0;
}
