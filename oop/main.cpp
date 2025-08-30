#include <iostream>

using namespace std;

const int DATA_SIZE = 1024;

class ICoordinate {
    public:
        virtual ~ICoordinate() = default;
        virtual void print() const = 0;
};

class Coordinate : public ICoordinate {
    private:
        int x, y, z;
        int* data;

    public:
        Coordinate() : x(0), y(0), z(0) {
            data = new int[DATA_SIZE];
            cout << "Coordinate() created" << endl;
        }

        Coordinate(int x, int y, int z) : x(x), y(y), z(z) {
            data = new int[DATA_SIZE];
            cout << "Coordinate(x, y, z) created" << endl;
        }

        Coordinate(const Coordinate& other) : x(other.x), y(other.y), z(other.z) {
            data = new int[DATA_SIZE];
            copy(other.data, other.data + DATA_SIZE, data);
            cout << "Coordinate copied created" << endl;
        }

        Coordinate(Coordinate&& other) : x(other.x), y(other.y), z(other.z) {
            data = other.data;
            other.data = nullptr;
            other.x = 0;
            other.y = 0;
            other.z = 0;
            cout << "Coordinate moved" << endl;
        }

        ~Coordinate() {
            delete[] data;
            cout << "Coordinate destroyed" << endl;
        }

        Coordinate& operator=(const Coordinate& other) {
            if (this != &other) {
                x = other.x;
                y = other.y;
                z = other.z;
                copy(other.data, other.data + DATA_SIZE, data);
            }
            return *this;
        }

        bool operator==(const Coordinate& other) const {
            return x == other.x && y == other.y && z == other.z;
        }

        bool operator!=(const Coordinate& other) const {
            return !(*this == other);
        }

        Coordinate& operator=(Coordinate&& other) noexcept {
            if (this != &other) {
                delete[] data;

                x = other.x;
                y = other.y;
                z = other.z;
                data = other.data;

                other.data = nullptr;
                other.x = 0;
                other.y = 0;
                other.z = 0;
            }
            return *this;
        }

        void print() const override {
            cout << "Coordinate(" << x << ", " << y << ", " << z << ")" << endl;
        }
};

int main() {
    return 0;
}
