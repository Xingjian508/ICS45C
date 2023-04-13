constexpr int STK_MAX = 1000;


class Stack
{

    int _lastIndex;
    char storage[STK_MAX];

    public:
    Stack() {
        _lastIndex = -1;
    }

    void push(char c) {
        if (_lastIndex != STK_MAX-1) {
            _lastIndex++;
            storage[_lastIndex] = c;
        }
    }

    char pop() {
        if (_lastIndex == -1) {
            return '@';
        }
        else {
            char value = storage[_lastIndex];
            _lastIndex--;
            return value;
        }
    }

    char top() {
        if (_lastIndex == -1) {
            return '@';
        }
        return storage[_lastIndex];
    }

    bool isEmpty() {
        if (_lastIndex == -1)
            return true;
        return false;
    }

    bool isFull() {
        return (_lastIndex == STK_MAX-1);
    }

};


void push_all(Stack & stk, string line) {
    for (auto character : line) {
        stk.push(character);
    }
}

void pop_all(Stack & stk) {
    while (!stk.isEmpty()) {
        cout << stk.pop() << endl;
    }
}
