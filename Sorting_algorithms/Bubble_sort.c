#include <stdio.h>

void bubble_sort(int arr[], int size)
{
    int i, j, temp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
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
    bubble_sort(arr, size);
    print_array(arr, size);
    return 0;
}