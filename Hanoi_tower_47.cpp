#include <iostream>
#include <stack>

using namespace std;

void displayStack(const stack<int>& _stack) {
	stack<int> stack = _stack;
	while (!stack.empty()) {
		cout << stack.top() << " ";
		stack.pop();
	}
}

void displayStacks(const stack<int>& stack1, const stack<int>& stack2, const stack<int>& stack3) {
	stack<int> first = stack1, second = stack2, third = stack3;
	cout << "first ";
	displayStack(first);
	cout << "\n" << "second ";
	displayStack(second);
	cout << "\n" << "third ";
	displayStack(third);
}

int main() {
	int n;
	cin >> n;
	stack <int> first, second, third;

	for (int i = 0; i < n; i++)
		first.push(i+1);

	displayStacks(first, second, third);

	for (int i = 0; i < pow(2, n) - 1; i++) {
		if ((n % 2 == 0 && i % 3 == 0) || (n % 2 == 1 && i % 3 == 1)) {
			if (second.empty()) {
				second.push(first.top()); first.pop();
			}
			else if (first.empty()) {
				first.push(second.top()); second.pop();
			}
			else if (first.top() > second.top()) {
				second.push(first.top()); first.pop();
			}
			else {
				first.push(second.top()); second.pop();
			}
		}
		else if ((n % 2 == 0 && i % 3 == 1) || (n % 2 == 1 && i % 3 == 0)) {
			if (first.empty()) {
				first.push(third.top()); third.pop();
			}
			else if (third.empty()) {
				third.push(first.top()); first.pop();
			}
			else if (first.top() > third.top()) {
				third.push(first.top()); first.pop();
			}
			else {
				first.push(third.top()); third.pop();
			}
		}
		else {
			if (second.empty()) {
				second.push(third.top()); third.pop();
			}
			else if (third.empty()) {
				third.push(second.top()); second.pop();
			}
			else if (second.top() > third.top()) {
				third.push(second.top()); second.pop();
			}
			else {
				second.push(third.top()); third.pop();
			}
		}
	}
	cout << "\n\n" << pow(2, n) - 1 << " operations\n\n";
	displayStacks(first, second, third);
}

