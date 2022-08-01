#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using heap = std::vector<int>;

#define PARENT(i)	((i - 1) / 2)
#define LEFT(i)		(i * 2 + 1)
#define RIGHT(i)	(i * 2 + 2)

void heapify_down(heap &h, int i)
{
	auto left = LEFT(i);
	auto right = RIGHT(i);
	auto largest = i;

	if (left < h.size() && h[left] > h[largest])
		largest = left;

	if (right < h.size() && h[right] > h[largest])
		largest = right;

	if (largest != i) {
		std::swap(h[i], h[largest]);
		heapify_down(h, largest);
	}
}

void heapify_up(heap &h, int i)
{
	auto parent = PARENT(i);

	if (i != 0 && h[parent] < h[i]) {
		std::swap(h[i], h[parent]);
		heapify_up(h, parent);
	}
}

[[maybe_unused]]
heap &insert(heap &h, int item)
{
	h.emplace_back(item);
	heapify_up(h, h.size() - 1);
	return h;
}

int pop(heap &h)
{
	auto ret = h[0];

	h[0] = h.back();
	h.pop_back();
	heapify_down(h, 0);
	return ret;
}

int main(void)
{
	heap h;
	int number;

	insert(h, 3);
	insert(h, 9);
	insert(h, 2);
	insert(h, 1);
	insert(h, 4);
	insert(h, 5);

	number = pop(h);

	for (auto i : h) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	return 0;
}