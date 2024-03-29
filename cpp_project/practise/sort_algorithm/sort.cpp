#include "sort.h"

sort_compare::sort_compare() {}
sort_compare::sort_compare(const int &n)
{
    for (int i = 0; i < n; i++)
    {
        nums.push_back((-i) ^ 3);
    }
}
sort_compare::~sort_compare() {}

vector<int> sort_compare::GetNums()
{
    return nums;
}

// 快排序
int sort_compare::partition(vector<int> &nums, int low, int high)
{
    int base = nums[low];
    while (low < high)
    {
        while (low < high && nums[high] >= base)
        {
            --high;
        }
        nums[low] = nums[high];

        while (low < high && nums[low] <= base)
        {
            ++low;
        }
        nums[high] = nums[low];

        return low;
    }
}
vector<int> sort_compare::quick_sort(vector<int> &nums, int low, int high)
{
    if (low < high)
    {
        int pivotpos = partition(nums, low, high);
        quick_sort(nums, low, pivotpos);
        quick_sort(nums, pivotpos + 1, high);
    }
    return nums;
}

// 交换函数
void sort_compare::swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// 冒泡排序
vector<int> sort_compare::bubble_sort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) // 共进行n-1趟
    {
        for (int j = n - 1; j > i; j--)
        {
            if (nums[j] < nums[j - 1])
            { // 选出较小者
                swap(nums[j], nums[j - 1]);
            }
        }
    }
    return nums;
}

// 选择法排序
vector<int> sort_compare::select_sort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] > nums[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(nums[min], nums[i]);
        }
    }
    return nums;
}

// 直接插入排序   细读
vector<int> sort_compare::insert_sort(vector<int> &nums)
{
    int n = nums.size();
    int i, j;
    int temp;
    for (i = 1; i < n; i++)
    {
        if (nums[i] < nums[i - 1])
        {
            temp = nums[i];
            for (j = i - 1; (temp < nums[j]) && (j >= 0); j--)
            {
                nums[j + 1] = nums[j];
            }
            nums[j + 1] = temp;
        }
    }
    return nums;
}

// 归并排序
vector<int> sort_compare::merge_sort(vector<int> &nums, int low, int high)
{
    if (low < high)
    {
        int mid = (high + low) / 2;
        merge_sort(nums, low, mid);
        merge_sort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
    return nums;
}

void sort_compare::merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> copy_cache;
    int i, j, k;
    for (int i = 0; i < nums.size(); i++)
    {
        copy_cache[i] = nums[i];
    }
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (copy_cache[i] <= copy_cache[j])
        {
            nums[k] = copy_cache[i++];
        }
        else
        {
            nums[k] = copy_cache[j++];
        }
    }
    while (i <= mid)
    {
        nums[k++] = copy_cache[i++];
    }
    while (j <= high)
    {
        nums[k++] = copy_cache[j++];
    }
}

// 计数排序
vector<int> sort_compare::count_sort(vector<int> &nums)
{

    int min = 65536;
    int max = -65536;
    int j = 0; // j用于记录最终排序后nums的下标
    // 找出最大最小值
    for (int i = 0; i < nums.size(); i++)
    {
        if (min > nums[i])
        {
            swap(min, nums[i]);
        }
        if (max < nums[i])
        {
            swap(max, nums[i]);
        }
    }

    vector<int> count(max - min + 1, 0);

    for (int i = 0; i < nums.size(); i++)
    {
        count[nums[i] - min]++;
    }

    for (int i = 0; i < count.size(); i++)
    {

        while (count[i] > 0)
        {
            nums[j++] = min + i;
            count[i]--;
        }
    }

    return nums;
}

// 堆排序
void sort_compare::heap_adjustment(vector<int> &nums, int i, int n)
{
    // paramaters checkout

    if (nums.size() <= 0)
    {
        cout << "the sort array's is null";
        return;
    }

    if (i < 0 || n <= 0)
    {
        cout << "the parameter i or n is wrong,please input again";
        return;
    }

    // running the code formaly
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && nums[largest] < nums[left])
    {
        largest = left;
    }

    if (right < n && nums[largest] < nums[right])
    {
        largest = right;
    }

    if (i != largest)
    {
        swap(nums[i], nums[largest]);
        heap_adjustment(nums, largest, n);
    }
}

vector<int> sort_compare::heap_sort(vector<int> &nums)
{
    int n = nums.size();
    // constructing the big root heap originally
    for (int i = n / 2; i > 0; i--)
    {
        heap_adjustment(nums, i, n);
    }
    // 依次将堆顶元素与“堆底元素”交换
    for (int i = n - 1; i > 0; i--)
    {
        swap(nums[0], nums[i]);
        heap_adjustment(nums, 0, i); // i表示待排序的元素共余n个
    }
}

// 折半查找算法
int sort_compare::middle_search(vector<int> &nums, int key)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (nums[middle] == key)
        {
            return middle;
        }
        else if (nums[middle] > key)
        {
            high = middle - 1;
        }

        else
        {
            low = middle + 1;
        }
    }
    cout << "not exits";
    return -1;
}

void sort_compare::menu()
{
    cout << "欢迎进入排序算法菜单界面！请选择你的排序算法" << endl;
    cout << "*************1.冒泡排序*************" << endl;
    cout << "*************2.直接插入排序*************" << endl;
    cout << "*************3.选择法排序*************" << endl;
    cout << "*************4.快速排序*************" << endl;
    cout << "*************5.归并排序*************" << endl;
    cout << "*************6.计数排序*************" << endl;
    cout << "*************7.堆排序*************" << endl;
    cout << "*************8.计数排序.*************" << endl;
    cout << "*************9.查    找.*************" << endl;
    cout << "*************0.退出系统.*************" << endl;
}
void sort_compare::Display()
{
    cout << "排序后的数组元素为" << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums.size() << "   ";
    }
}

void sort_compare::run(vector<int> &nums)
{
    int choose;
    menu();
    cout << "please choose your sort algorithms";
    cin >> choose;
    if (choose > 9 || choose < 0)
    {
        cout << "error parameter,please input the correct parameter" << endl;
        return;
    }
    switch (choose)
    {
    case 1:

        bubble_sort(nums);
        Display();
        break;
    case 2:
        insert_sort(nums);
        Display();
        break;

    case 3:
        select_sort(nums);
        Display();
        break;

    case 4:
        quick_sort(nums, 0, nums.size() - 1);
        Display();
        break;

    case 5:
        merge_sort(nums, 0, nums.size() - 1);
        Display();
        break;

    case 6:
        count_sort(nums);
        Display();
        break;

    case 7:
        heap_sort(nums);
        Display();
        break;

    case 8:
        cout << "please input the key";
        int key;
        cin >> key;
        middle_search(nums, key);
        break;

    default:
        // break;

        cout << "carry on?(y or n)";
        char instruciton;
        cin >> instruciton;
        while (instruciton == 'y' || instruciton == 'Y')
        {
            run(nums);
        }
        break;
    }
}