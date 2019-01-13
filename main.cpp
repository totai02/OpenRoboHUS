#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string name, address;
    int age;

    cout << "Nhập tên của bạn: ";
    getline (cin, name);

    cout << "Nhập tuổi: ";
    cin >> age;

    cout << "Địa chỉ: ";
    cin.ignore();           // câu lệnh dùng để xóa buffer, nếu ko có lệnh này, address sẽ nhận dấu "\n"
                            // của lúc nhập tuổi để lại.
    getline (cin, address);

    cout << "Tên: " << name << ", Tuổi: " << age << ", Địa chỉ: " << address << endl;

    return 0;
}
