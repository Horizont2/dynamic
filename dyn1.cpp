#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Passenger {
    int id;
    int arrivalTime;
};

void simulateBusStop(int N, int passengerInterval, int busInterval) {
    queue<Passenger> busStopQueue;
    int currentTime = 0;
    int passengerCount = 1;

    srand(time(0));

    while (currentTime < 1440) {
        if (currentTime % passengerInterval == 0) {
            Passenger p = { passengerCount++, currentTime };
            busStopQueue.push(p);
            cout << "Пасажир " << p.id << " прибув на зупинку о " << p.arrivalTime << " хв.\n";
        }

        if (currentTime % busInterval == 0 && !busStopQueue.empty()) {
            int freeSeats = rand() % N + 1;
            cout << "Маршрутка прибула о " << currentTime << " хв. з " << freeSeats << " вільними місцями.\n";
            while (freeSeats > 0 && !busStopQueue.empty()) {
                Passenger p = busStopQueue.front();
                busStopQueue.pop();
                cout << "Пасажир " << p.id << " сів у маршрутку, чекав " << currentTime - p.arrivalTime << " хв.\n";
                --freeSeats;
            }
        }

        ++currentTime;
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int N = 5;
    int passengerInterval = 5;
    int busInterval = 15;
    simulateBusStop(N, passengerInterval, busInterval);
    return 0;
}
