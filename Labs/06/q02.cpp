#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class Image {
private:
    int width, height;
    int *data;
public:
    Image(int width, int height, int *data) : width(width), height(height) {
        this->data = new int[width*height];

        for (int i = 0; i < width*height; i++)
            this->data[i] = data[i];
    }

    Image(const Image& obj) : width(obj.width), height(obj.height) {
        this->data = new int[width*height];

        for (int i = 0; i < width*height; i++)
            this->data[i] = obj.data[i];
    }

    ~Image() {
        delete[] data;
    }

    void display() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++)
                cout << *(data + i*width + j) << " ";
            cout << endl;
        }
    }

    void updateData() {
        for (int i = 0; i < width*height; i++) {
            if (data[i] > 0) continue;
            data[i] = rand()%255 + 1;
        }
    }
};

int main() {
    srand(time(0));

    int sample[2*3] = {-1, -2, 0, -3, 4, 128};
    Image image1(2, 3, sample);

    Image copy_image1(image1);

    image1.display();
    cout << "\n";
    copy_image1.display();

    image1.updateData();
    copy_image1.updateData();
    cout << "\n";
    cout << "\n";

    image1.display();
    cout << "\n";
    copy_image1.display();

    return 0;
}