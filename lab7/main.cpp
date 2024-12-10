#include <QVector>
#include <iostream>

int main() {
    QVector<int> numbers = {1, 2, 3, 4};
    for (int n : numbers) {
        std::cout << n << std::endl;
    }
    return 0;
}
