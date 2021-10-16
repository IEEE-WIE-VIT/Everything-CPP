#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void heapify(vector<int> &height, int i)
{
  int size = height.size();
  int biggest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < size && height[l] > height[biggest])
    biggest = l;
  if (r < size && height[r] > height[biggest])
    biggest = r;

  if (biggest != i)
  {
    swap(&height[i], &height[biggest]);
    heapify(height, biggest);
  }
}
void insert(vector<int> &height, int newNum)
{
  int size = height.size();
  if (size == 0)
  {
    height.push_back(newNum);
  }
  else
  {
    height.push_back(newNum);
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(height, i);
    }
  }
}
void del_node(vector<int> &height, int num)
{
  int size = height.size();
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == height[i])
      break;
  }
  swap(&height[i], &height[size - 1]);

  height.pop_back();
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(height, i);
  }
}
void arr(vector<int> &height)
{
  for (int i = 0; i < height.size(); ++i)
    cout << height[i] << " ";
  cout << "\n";
}

int main()
{
  vector<int> tree;

  insert(tree, 37);
  insert(tree, 4);
  insert(tree, 24);
  insert(tree, 50);
  insert(tree, 92);

  cout << "The Max Heap array is: ";
  arr(tree);

  del_node(tree, 4);

  cout << "After deleting an element the array is: ";

  arr(tree);
}
