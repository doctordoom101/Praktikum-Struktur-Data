def display_data(arr):
    print(f"Data[{len(arr)}] :", end=" ")
    for i in arr:
        print(i, end=" ")
    print()

def find_data(arr, target):
    index = -1
    for i in range(len(arr)):
        if arr[i] == target:
            index = i
            break
    return index

def insert_data(arr, data, index):
    arr.insert(index, data)

def delete_data(arr, target):
    arr.remove(target)

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

def exchange_sort(arr):
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            if arr[i] > arr[j]:
                arr[i], arr[j] = arr[j], arr[i]
    return arr

# Main function
def main():
    data = [45, 16, 10, 25, 11, 80, 62, 18, 20, 37]

    # a. Display data
    print("Output Point A.")
    display_data(data)

    # b. Find data 18
    print("\nOutput Point B.")
    target = 18
    index = find_data(data, target)
    if index != -1:
        print(f"Data {target} found at index array ke {index} atau (Data[{index}]={target})")
    else:
        print(f"\nData {target} not found.")

    # c. Insert data 100 at index 5
    print("\nOutput Point C.")
    print("Sebelum di insert adalah ", end="")
    display_data(data)
    insert_data(data, 100, 5)
    print("Setelah di insertkan data 100 adalah ", end="")
    display_data(data)

    # d. Delete data 62
    print("\nOutput Point D.")
    print("Data Sebelum dihapus data 62 adalah ", end="")
    display_data(data)
    delete_data(data, 62)
    print("Data Setelah dihapus data 62 adalah ", end="")
    display_data(data)

    # e. Sort data with Quick-Sort and Exchange-Sort
    print("\nOutput Point E.")
    print("Data Sebelum diurutkan adalah ", end="")
    display_data(data)

    sorted_data_quick = quick_sort(data.copy())
    print("Data Setelah diurutkan dengan metode Quick-Sort adalah ", end="")
    display_data(sorted_data_quick)

    sorted_data_exchange = exchange_sort(data.copy())
    print("Data Setelah diurutkan dengan metode Exchange-Sort adalah ", end="")
    display_data(sorted_data_exchange)

    # f. Compare sorting methods
    print("\nOutput Point F.")
    print("Data Sebelum diurutkan adalah ", end="")
    display_data(data)
    print("Data Setelah diurutkan dengan metode Quick-Sort adalah ", end="")
    display_data(sorted_data_quick)
    print("Data Setelah diurutkan dengan metode Exchange-Sort adalah ", end="")
    display_data(sorted_data_exchange)

    # Measure the execution time of each sorting method to determine which one is faster

if __name__ == "__main__":
    main()