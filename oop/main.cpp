#include <algorithm>
#include <cstdio>
#include <unistd.h>

using namespace std;

struct Coordinate {
    int x, y, z;
    int* data;

    Coordinate() {
        x = y = z = 0;
        data = new int[1024];
        printf("Coordinate() created, resource allocated at %p\n", static_cast<void*>(data));
    }

    Coordinate(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
        data = new int[10];
        printf("Coordinate(x,y,z) created, resource allocated at %p\n", static_cast<void*>(data));
    }

    Coordinate(const Coordinate& other) {
        x = other.x;
        y = other.y;
        z = other.z;
        data = new int[1024];
        copy(other.data, other.data + 1024, data);
        printf("Coordinate copied, resource allocated at %p\n", static_cast<void*>(data)); 
    }

    ~Coordinate() {
        delete[] data;
        printf("Coordinate destroyed, resource deallocated at %p\n", static_cast<void*>(data));
    }

    Coordinate& operator=(const Coordinate& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;
            copy(other.data, other.data + 1024, data);
        }
        return *this;
    }

    bool operator==(const Coordinate& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator!=(const Coordinate& other) const {
        return !(*this == other);
    }
};

int main() {
    for (int i =0; i < 10; i++) {
        Coordinate c1;
        sleep(1);
    }
    return 0;
}
