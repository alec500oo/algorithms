#include <algorithm>
#include <vector>


#define LEFT(i)		(i * 2 + 1)
#define RIGHT(i)	(i * 2 + 2)
#define PARENT(i)	((i - 1) / 2)

using heap = std::vector<int>;

void heapify_down(heap &h, int i, int size)
{
	auto l = LEFT(i);
	auto r = RIGHT(i);
	auto largest = i;

	if (l < size && h[l] > h[largest])
		largest = l;

	if (r < size && h[r] > h[largest])
		largest = r;

	if (largest != i) {
		std::swap(h[i], h[largest]);
		heapify_down(h, largest, size);
	}
}

void heap_sort(heap& h)
{
	for (int i = h.size() / 2 - 1; i >= 0; --i)
		heapify_down(h, i, h.size());

	for (int i = h.size() - 1; i > 0; --i) {
		std::swap(h[0], h[i]);
		heapify_down(h, 0, i);
	}
}

int main(void)
{
	heap h = {14, 27, 3, 2, 6, 18, 45, 1};
	heap_sort(h);
	return 0;
}