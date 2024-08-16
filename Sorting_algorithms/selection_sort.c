#include <stdio.h>

void selection_sort(int arr[], int size)
{
    int i, j, min, temp;
    for (i = 0; i < size; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
                temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            }
        }
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
    selection_sort(arr, size);
    print_array(arr, size);
    return 0;
}