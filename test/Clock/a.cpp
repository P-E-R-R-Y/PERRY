#include <iostream>
#include <cstdio>
#include <chrono>
#include <thread>

class Clock {
    public:
        Clock(int fps) {
            _beg = std::chrono::system_clock::now();
            _end = std::chrono::system_clock::now();
            _target_delta = 1000/fps;
        };

        ~Clock() = default;

        void update() {
            _beg = std::chrono::system_clock::now();
            std::chrono::duration<double, std::milli> work_time = _beg - _end;

            if (work_time.count() < _target_delta) {
                std::chrono::duration<double, std::milli> delta_ms(_target_delta - work_time.count());
                std::__1::chrono::milliseconds delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);

                std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
            }
            _end = std::chrono::system_clock::now();
            std::chrono::duration<double, std::milli> sleep_time = _end - _beg;
        }

        void print() {
            std::chrono::duration<double, std::milli> sleep_time = _end - _beg;
            printf("Time: %.3f ms\n", (sleep_time).count());
        }

    private:
        std::chrono::system_clock::time_point _beg;
        std::chrono::system_clock::time_point _end;
        double _target_delta;
};


int main()
{
    Clock clock(60.0);
    while (true) {
        // Maintain designated frequency of *fps* Hz (200 ms per frame)
        clock.update();
        
        // Your code here

        clock.print();
    }
}