/*
 *  Results:    AC (325 ms [76.72%];  93.2 MB [94.48%])
 */


class DetectSquares {
public:
    DetectSquares() {

    }

    void add(vector<int> point) {
        table[{point.at(0), point.at(1)}]++;
    }

    int count(vector<int> point) {
        int ret = 0;

        for (const auto &iter : table) {
            const auto pt = iter.first;

            if ((point.at(0) != pt.first && point.at(1) != pt.second)
                    && (abs(point.at(0) - pt.first) == abs(point.at(1) - pt.second))) {
                int p1_cnt = table[{pt.first, pt.second}];
                int p2_cnt = table[{pt.first, point.at(1)}];
                int p3_cnt = table[{point.at(0), pt.second}];

                ret += p1_cnt * p2_cnt * p3_cnt;
            }
        }

        return ret;
    }
private:
    map<pair<int, int>, int> table;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */

