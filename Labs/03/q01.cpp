#include <iostream>

class BoardMarker {
private:
    std::string brand;
    std::string shade;
    bool refillable, ink_status;
public:
    void setBrand(std::string new_brand) {
        brand = new_brand;
    }
    void setShade(std::string new_shade) {
        shade = new_shade;
    }
    void setRefillable(bool flag) {
        refillable = flag;
    }
    void setInkStatus(bool flag) {
        ink_status = flag;
    }

    std::string getBrand() {
        return brand;
    }
    std::string getShade() {
        return shade;
    }
    bool getRefillable() {
        return refillable;
    }
    bool getInkStatus() {
        return ink_status;
    }
    
};

void write(BoardMarker marker) {
    if (marker.getInkStatus()) {
        std::cout << marker.getBrand() << " pen wiritng with a shade of " << marker.getShade() << std::endl;
        marker.setInkStatus(false);
        marker.setRefillable(true);
        return;
    }
    std::cout << "depleted ink" << std::endl;
}

void refill(BoardMarker marker) {
    if (marker.getRefillable()) {
        std::cout << "refilling ink" << std::endl;
        marker.setRefillable(false);
        marker.setInkStatus(true);
        return;
    }
    std::cout << "ink not depleted. can't refill yet" << std::endl;
}

int main()
{
    BoardMarker marker;
    marker.setBrand("dollar");
    marker.setShade("black");

    write(marker);
    write(marker);
    refill(marker);
    write(marker);

    return 0;
}
