#include <iostream>
#include <cstdio>
#include <chrono>
#include <thread>

class Clock {
    public:
        Clock() {
            _beg = std::chrono::system_clock::now();
            _end = std::chrono::system_clock::now();
        };

        ~Clock() = default;

        void start() {
            _beg = std::chrono::system_clock::now();
        }

        void stop() {
            _end = std::chrono::system_clock::now();
        }

        std::chrono::milliseconds getDelta() {
//            std::chrono::duration<double, std::milli> work_time = _end - _beg;
            return std::chrono::duration_cast<std::chrono::milliseconds>(_end - _beg);
        }

        void sleep(std::chrono::milliseconds ms) const {
            std::this_thread::sleep_for(ms);
        }

        static std::chrono::milliseconds FpsToMs(int fps) {
            return std::chrono::milliseconds(1000 / fps);
        }

    private:
        std::chrono::system_clock::time_point _beg;
        std::chrono::system_clock::time_point _end;
};