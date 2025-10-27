#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <chrono>
using namespace std;

struct Info {
    int VietNam, ThaiLand, Campuchia;
    bool operator==(const Info &o) const {
        return VietNam == o.VietNam && ThaiLand == o.ThaiLand && Campuchia == o.Campuchia;
    }
};

// -------- solve chỉ nhận được thông tin của chính nó + neighbor --------
Info solve(int id, const vector<Info> &self_message_history, const vector<vector<Info>> &neighbors_message_history, const int Round){
    Info temp = {0, 0, 0};
    for(long neigh = 0; neigh < neighbors_message_history.size(); neigh++){
        temp.VietNam += neighbors_message_history[neigh][Round - 1].VietNam;
        temp.ThaiLand += neighbors_message_history[neigh][Round - 1].ThaiLand;
        temp.Campuchia += neighbors_message_history[neigh][Round - 1].Campuchia;
    }
    if(Round == 1){
        temp.VietNam = temp.VietNam + self_message_history[0].VietNam;
        temp.ThaiLand = temp.ThaiLand + self_message_history[0].ThaiLand;
        temp.Campuchia = temp.Campuchia + self_message_history[0].Campuchia;
    }

    else{
        temp.VietNam = temp.VietNam - (neighbors_message_history.size() - 1) * self_message_history[Round - 2].VietNam;
        temp.ThaiLand = temp.ThaiLand - (neighbors_message_history.size() - 1) * self_message_history[Round - 2].ThaiLand;
        temp.Campuchia = temp.Campuchia - (neighbors_message_history.size() - 1) * self_message_history[Round - 2].Campuchia;
    }
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int maxn = 1000;
    int n, Round = 0;
    Info Day[maxn + 5];
    vector<int> neighbors[maxn + 5];
    vector<vector<Info>> message_history(maxn + 5); // Lưu lịch sử thông điệp cho từng node

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> Day[i].VietNam >> Day[i].ThaiLand >> Day[i].Campuchia;
        message_history[i].push_back(Day[i]);
    }

    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        neighbors[x].push_back(y);
        neighbors[y].push_back(x);
    }

    while (++Round) {
        vector<future<Info>> fut;
        fut.reserve(n);

        for (int i = 1; i <= n; i++) {
            // Chuẩn bị lịch sử riêng và lịch sử hàng xóm
            vector<vector<Info>> neighbors_message_history;
            for (int nb : neighbors[i]) neighbors_message_history.push_back(message_history[nb]);
            fut.push_back(async(launch::async, solve, i, message_history[i], neighbors_message_history,Round));
        }
        // Cập nhật kết quả mới
        for (int i = 1; i <= n; i++) {
            Day[i] = fut[i - 1].get();
            message_history[i].push_back(Day[i]);
        }

        cout << "Round " << Round << " completed.\n";
        if (Round == 10) break;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    for(long i = 1; i <= n; i++){
        cout << message_history[i][Round].VietNam <<" ";
        cout << message_history[i][Round].ThaiLand <<" ";
        cout << message_history[i][Round].Campuchia <<" ";
        cout << endl;
    }
}
