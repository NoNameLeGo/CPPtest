#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

struct VRObject {
    int id;
    float x, y, z;
    char name[50];
};

int main()
{
    VRObject objects[3] = {
        {1, 1.0f, 2.5f, 3.0f, "Chair"},
        {2, 4.0f, 0.0f, 1.5f, "Table"},
        {3, -2.0f, 3.0f, 0.5f, "Lamp"}
    };

    ofstream fout("vr_scene.dat", ios::binary);
    fout.write((char*)objects, sizeof(objects));
    fout.close();

    VRObject readObjects[3];
    ifstream fin("vr_scene.dat", ios::binary);
    fin.read((char*)readObjects, sizeof(readObjects));
    fin.close();

    for (int i = 0; i < 3; i++) {
        cout << "ID: " << readObjects[i].id << endl;
        cout << "位置: (" << readObjects[i].x << ", " << readObjects[i].y << ", " << readObjects[i].z << ")" << endl;
        cout << "名称: " << readObjects[i].name << endl;
        cout << "-----------------------------" << endl;
    }

    return 0;
}