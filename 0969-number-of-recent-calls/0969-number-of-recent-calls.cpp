class RecentCounter {
public:
    queue<int> dev;

    RecentCounter() {}

    int ping(int t) {
        dev.push(t);
        while(dev.front() < t - 3000) dev.pop();
        return dev.size();
    }
};