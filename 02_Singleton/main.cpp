#include <iostream>
#include <thread>

using namespace std;

static std::mutex mt;
class Rocket {
private:
    static Rocket *ms_rocket;
    Rocket() {}
    Rocket(const Rocket &rocket) {}
    ~Rocket() {}
    void operator=(const Rocket &rocket) {}
public:
    static Rocket *sharedRocket() {
        mt.lock();
        if (ms_rocket == NULL) {
            ms_rocket = new Rocket ();
        }
        mt.unlock();
        return ms_rocket;
    }
    static void deleteRocket() {
        mt.lock();
        if (ms_rocket != NULL) {
            delete  ms_rocket;
            ms_rocket = NULL;
        }
        mt.unlock();
    }
};

Rocket *Rocket::ms_rocket = NULL;

int main()
{
    Rocket *p1 = Rocket::sharedRocket();
    Rocket *p2 = Rocket::sharedRocket();

    cout << p1 << endl;
    cout << p2 << endl;

    return 0;
}
