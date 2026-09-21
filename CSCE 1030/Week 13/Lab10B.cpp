#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Point {
    int x;
    int y;
    int z;
    double distance;
};

void readData(ifstream& inFile, Point points[], int& size) {
    size = 0;
    while (inFile >> points[size].x >> points[size].y >> points[size].z) {
        size++;
        if (size >= 20) break;
    }
    inFile.close();
}

Point findMin(Point points[], Point user, int size) {
    user.distance = 0;
    Point minPoint = points[0];
    double minDistance = sqrt(pow(points[0].x - user.x, 2) + pow(points[0].y - user.y, 2) + pow(points[0].z - user.z, 2));
    for (int i = 0; i < size; i++) {
        double distance = sqrt(pow(points[i].x - user.x, 2) + pow(points[i].y - user.y, 2) + pow(points[i].z - user.z, 2));
        points[i].distance = distance;
        if (distance < minDistance) {
            minDistance = distance;
            minPoint = points[i];
        }
    }
    return minPoint;
}

int main() {
    ifstream inFile("data.dat");
    if (!inFile.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }
    Point user;
    int count = 20;
    Point arr[count];
    readData(inFile, arr, count);
    cout << "Enter point: ";
    cin >> user.x >> user.y >> user.z;
    Point minPoint = findMin(arr, user, count);
    cout << "The closest point is " << minPoint.x << " " << minPoint.y << " " << minPoint.z << endl;
    cout << "Minimum distance = " << minPoint.distance << endl;
    return 0;
}