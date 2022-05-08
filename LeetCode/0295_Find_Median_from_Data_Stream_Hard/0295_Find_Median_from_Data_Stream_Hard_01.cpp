/*
 *  Results:    AC (359 ms [75.96%];  128.0 MB [8.52%])
 */

class MedianFinder {
public:
    MedianFinder() {

    }

    void addNum(int num) {
        bst.insert(num);
        is_even = !is_even;

        /* special case when add first num */
        if (it == bst.cend())
            it++;

        /* odd */
        if (!is_even && *it > num)
            it--;
        /* even */
        if (is_even && *it <= num)
            it++;
    }

    double findMedian() {
        return (!is_even) ? (double)(*it) : ((*it + *prev(it, 1))/2.0);
    }
private:
    multiset<int> bst;
    multiset<int>::const_iterator it = bst.cbegin();
    bool is_even = true;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

