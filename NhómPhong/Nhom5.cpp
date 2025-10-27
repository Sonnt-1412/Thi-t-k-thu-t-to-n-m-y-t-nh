#include<bits/stdc++.h>
using namespace std;

// --- Biến toàn cục ---
vector<double> center36; // sẽ chứa {x, y} boss 36 đầu tiên
int step_count = 0;       // đếm số bước đi từ center36
const int max_steps = 20; // số bước random
double step_size = 50;    // bước cơ bản quanh boss 36

pair<double,double> getNextPoint(double x, double y, int lastBossID){
    // Khởi tạo seed random
    static bool first_call = true;
    if (first_call) {
        srand(time(0));
        first_call = false;
    }

    // Nếu vừa gặp boss ID=36 lần đầu, thiết lập tâm
    if (lastBossID == 36 && center36.empty()) {
        center36.push_back(x);
        center36.push_back(y);
        step_count = 0;
    }

    // Nếu chưa có center36 → khám phá rộng để tìm boss 36
    if (center36.empty()) {
        double dx = (rand() % 3 - 1) * 4 * step_size; // -1,0,1 * 4*step_size
        double dy = (rand() % 3 - 1) * 4 * step_size;
        return {x + dx, y + dy};
    }

    // Nếu đã có center36 → đi random trong 20 bước, sau đó quay về center
    double cx = center36[0];
    double cy = center36[1];

    if (step_count < max_steps) {
        double dx = (rand() % 3 - 1) * step_size;
        double dy = (rand() % 3 - 1) * step_size;
        step_count++;
        return {x + dx, y + dy};
    } else {
        step_count = 0;
        return {cx, cy};
    }
}
int main(){
    return 0;
}

