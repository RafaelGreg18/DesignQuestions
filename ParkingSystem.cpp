//Statement: https://leetcode.com/problems/design-parking-system/

#include <bits/stdc++.h>
using namespace std;

class ParkingSystem {
public:
    vector<int> parking_spots = {0,0,0};

    ParkingSystem(int big, int medium, int small) {
        parking_spots[0] = big;
        parking_spots[1] = medium;
        parking_spots[2] = small;
    }
    
    bool addCar(int carType) {
        if (parking_spots[carType-1] > 0){
            parking_spots[carType-1] -= 1;
            return true;
        }
        return false;
    }
};

/**
 * ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */