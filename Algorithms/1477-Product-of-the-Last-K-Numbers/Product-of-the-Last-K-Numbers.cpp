class ProductOfNumbers {
    vector<int> p{1};

public:
    void add(int num) {
        if (num == 0) p = {1};
        else p.push_back(p.back() * num);
    }

    int getProduct(int k) {
        int n = p.size();
        return k >= n ? 0 : p.back() / p[n - 1 - k];
    }
};


/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */