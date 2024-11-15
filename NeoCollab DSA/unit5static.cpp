// Question 1
#include <iostream>
#include <cmath>

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void maxHeapify(int arr[], int n, int i) 
{
   //Type your code here
   int largest = i;
   int left = 2*i + 1;
   int right = 2*i + 2;
   
   if(left < n && arr[left] > arr[largest]){
       largest = left;
   }
   
   if(right < n && arr[right] > arr[largest]){
       largest = right;
   }
   
   if(largest != i){
       swap(arr, largest, i);
       maxHeapify(arr, n, largest);
   }
}

void buildMaxHeap(int arr[], int n) 
{
   //Type your code here
   for(int i=n/2-1; i>=0; i--){
       maxHeapify(arr, n, i);
   }
}

void insertIntoMaxHeap(int arr[], int *n, int value) 
{
    //Type your code here
    arr[*n] = value;
    (*n)++;
    int i = *n - 1;
    while(i>0 && arr[(i-1)/2] < arr[i]){
        swap(arr, i, (i-1)/2);
        i = (i-1)/2;
    }
}

int isPrime(int num) 
{
    //Type your code here
    if(num <= 1) return 0;
    
    for(int i=2; i<= sqrt(num); i++){
        if(num%i == 0){
            return 0;
        }
    }
    
    return 1;
}

void printMaxHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[100];
    int n = 0; 
    int num_elements;

    scanf("%d", &num_elements);

    for (int i = 0; i < num_elements; i++) {
        int value;
        scanf("%d", &value);

        if (isPrime(value)) {
            insertIntoMaxHeap(arr, &n, value);
        } else {
            printf("%d is not a prime number\n", value);
        }
    }

    buildMaxHeap(arr, n);
    printf("Max Heap: ");
    printMaxHeap(arr, n);

    return 0;
}


// Question 2
#include <iostream>

using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(int heap[], int size, int i)
{
    //Type your code here
    int smallest = i;
   int left = 2*i + 1;
   int right = 2*i + 2;
   
   if(left < size && heap[left] < heap[smallest]){
       smallest = left;
   }
   
   if(right < size && heap[right] < heap[smallest]){
       smallest = right;
   }
   
   if(smallest != i){
       swap(heap[smallest], heap[i]);
       minHeapify(heap, size, smallest);
   }
}

void insertElement(int heap[], int &size, int value, int capacity) 
{
    //Type your code here
    if(size == capacity){
        return;
    }
    
    heap[size] = value;
    size++;
    
    int i = size - 1;
    while(i > 0 && heap[(i-1)/2] > heap[i]){
        swap(heap[i], heap[(i-1)/2]);
        i = (i-1)/2;
    }
    
}

void displayMinHeap(int heap[], int size) {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int findMaxValue(int heap[], int size)
{
    //Type your code here
    int maxVal = heap[0];
    for(int i = 0; i<size; i++){
        if(heap[i] > maxVal){
            maxVal = heap[i];
        }
    }
    
    return maxVal;
}

int main() {
    int n;
    cin >> n;

    int capacity = n; 
    int heap[capacity]; 
    int size = 0;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertElement(heap, size, value, capacity);
    }

    displayMinHeap(heap, size);

    int maxValue = findMaxValue(heap, size);
    cout << "Maximum: " << maxValue;

    return 0;
}



// Question 3
#include <iostream>
#include <iomanip>
using namespace std;


void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(int heap[], int size, int i)
{
   int smallest = i;
   int left = 2*i + 1;
   int right = 2*i + 2;
   
   if(left < size && heap[left] < heap[smallest]){
       smallest = left;
   }
   
   if(right < size && heap[right] < heap[smallest]){
       smallest = right;
   }
   
   if(smallest != i){
       swap(heap[smallest], heap[i]);
       minHeapify(heap, size, smallest);
   }
}

void insertElement(int heap[], int &size, int value, int capacity) 
{
    if(size == capacity){
        return;
    }
    
    heap[size] = value;
    size++;
    
    int i = size - 1;
    while(i > 0 && heap[(i-1)/2] > heap[i]){
        swap(heap[i], heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int removeRootNode(int arr[], int &size){
    if(size == 0) return -1;
    
    int rootVal = arr[0];
    arr[0] = arr[size-1];
    size--;
    
    minHeapify(arr, size, 0);
    return rootVal;
    
}

void displayHeap(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    
    cout << endl;
}

int findMaxValue(int arr[], int size){
    if(size == 0) return -1;
    int maxValue = arr[0];
    for(int i=1; i<size; i++){
        if(arr[i] > maxValue){
            maxValue = arr[i];
        }
    }
    return maxValue;
}

int calculateSum(int arr[], int size){
    int sum = 0;
    for(int i=0; i<size; i++){
        sum += arr[i];
    }
    return sum;
}

double calculateAverage(int arr[], int size){
    if(size == 0) return 0.0;
    double sum = calculateSum(arr, size);
    return sum/size;
}


int main(){
    int n;
    cin >> n;
    int capacity = n;
    int heap[capacity];
    int size = 0;
    
    for(int i=0; i<n; i++){
        int value;
        cin >> value;
        insertElement(heap, size, value, capacity);
    }
    
    cout << "Min Heap: ";
    displayHeap(heap, size);
    
    int rootVal = removeRootNode(heap, size);
    cout << "Root node: " << rootVal << endl;
    
    
    
    int maxVal = findMaxValue(heap, size);
    cout << "Maximum value: " << maxVal << endl;
    
    int sum = calculateSum(heap, size);
    cout << "Sum of nodes: " << sum << endl;
    
    double avg = calculateAverage(heap, size);
    cout << "Average of nodes: " << fixed << setprecision(2) << avg << endl;
    
    return 0;
}



// Question 4
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;  
    int left = 2 * i + 1;  
    int right = 2 * i + 2;  

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Type your code here
    for(int i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }
    
    for(int i = n-1; i>=0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void mergeArrays(int arr1[], int n1, int arr2[], int n2, int result[]) {
    // Type your code here
    int i=0, j=0, k=0;
    while(i<n1 && j<n2){
        if(arr1[i] <= arr2[j]){
            result[k++] = arr1[i++];
        }else{
            result[k++] = arr2[j++];
        }
    }
    
    while(i<n1){
        result[k++] = arr1[i++];
    }
    
    while(j<n2){
        result[k++] = arr2[j++];
    }
}

int main() {
    int n1, n2;

    cin >> n1;
    int arr1[n1];

    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    cin >> n2;
    int arr2[n2];

    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    int result[n1 + n2];
    mergeArrays(arr1, n1, arr2, n2, result);

    heapSort(result, n1 + n2);

    for (int i = 0; i < n1 + n2; i++) {
        cout << result[i] << " ";
    }

    return 0;
}


// Question 5
#include <iostream>
#include <iomanip>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;  
    int left = 2 * i + 1;  
    int right = 2 * i + 2;  

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Type your code here
    for(int i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }
    
    for(int i = n-1; i>=0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

double calculateMedian(int arr[], int n) {
    // Type your code here
    if(n%2 == 1){
        return arr[n/2];
    }else{
        return (arr[(n-1)/2] + arr[n/2])/2.0;
    }
}

int main() {
    int n;

    cin >> n;
    
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heapSort(arr, n);

    double median = calculateMedian(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << fixed << setprecision(2);
    cout << "Median: " << median;

    return 0;
}
