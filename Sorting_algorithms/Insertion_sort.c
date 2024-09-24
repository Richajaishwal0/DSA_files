#include <stdio.h>

void insertion_sort(int arr[], int size)
{
    int i, current, j;
    for (i = 1; i < size; i++)
    {
        current = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}
void print_array(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int size, i;
    printf("Enter the number of elements :");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    insertion_sort(arr, size);
    print_array(arr, size);
    return 0;
}
