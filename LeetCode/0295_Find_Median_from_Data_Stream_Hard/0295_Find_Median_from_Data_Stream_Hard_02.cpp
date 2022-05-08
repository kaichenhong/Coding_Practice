/*
 *  Results:    AC (310 ms [92.22%];  117.1 MB [23.13%])
 */


class MedianFinder {
public:
    MedianFinder() {

    }

    void addNum(int num) {
        if (min_q.empty() || num <= min_q.top())
            min_q.push(num);
        else
            max_q.push(num);

        if (min_q.size() < max_q.size()) {
            min_q.push(max_q.top());
            max_q.pop();
        } else if (min_q.size() >= max_q.size()+2) {
            max_q.push(min_q.top());
            min_q.pop();
        }
    }

    double findMedian() {
        if (min_q.size() == max_q.size()+1)
            return (double)(min_q.top());
        else
            return (double)((min_q.top() + max_q.top()) / 2.0);
    }
private:
    priority_queue<int, vector<int>, less<int>> min_q;
    priority_queue<int, vector<int>, greater<int>> max_q;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

