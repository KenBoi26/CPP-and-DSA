// Question 1
void swap(int* a, int* b) {
    //Type your code here
    int temp = *a;
    *a = *b;
    *b = temp;
    
}

void minHeapify(int arr[], int size, int i) {
    //Type your code here
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < size && arr[left] < arr[smallest]){
        smallest = left;
    }
    
    if(right < size && arr[right] < arr[smallest]){
        smallest = right;
    }
    
    if(smallest != i){
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, size, smallest);
    }
    
}

void buildMinHeap(int arr[], int size) {
    //Type your code here
    for(int i=(size-1)/2; i>=0; i--){
        minHeapify(arr, size, i);
    }
    
}

void deleteElement(int arr[], int* size, int key) {
    //Type your code here
    int i;
    for(i=0; i<*size; i++){
        if(arr[i] == key){
            break;
        }
    }
    
    if(i == *size){
        return;
    }
    
    arr[i] = arr[*size - 1];
    (*size)--;
    
    minHeapify(arr, *size, i);
    
}



// Question 2
void swap(int arr[], int a, int b) {
    //Type your code here
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    
}

void maxHeapify(int arr[], int n, int i) {
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
        swap(arr, i, largest);
        maxHeapify(arr, n, largest);
    }
    
    
}

void buildMaxHeap(int arr[], int n) {
    //Type your code here
    for(int i=(n-1)/2; i>=0; i--){
        maxHeapify(arr, n, i);
    }
}

void deleteGreaterThanThreshold(int arr[], int &n, int threshold) {
    //Type your code here
    int i=0;
    while(i<n){
        if(arr[i]>threshold){
            arr[i] = arr[n-1];
            n--;
            maxHeapify(arr, n, i);
        }else{
            i++;
        }
    }
    
    
}

void printMaxHeap(int arr[], int n) {
    //Type your code here
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    
    cout << endl;
    
}


// Question 3
void swap(int &x, int &y) {
    //Type your code here
    int temp = x;
    x = y;
    y = temp;
    
}

void maxHeapify(int arr[], int n, int i) {
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
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
    
}

void buildMaxHeap(int arr[], int n) {
    //Type your code here
    for(int i=(n-1)/2; i>=0; i--){
        maxHeapify(arr, n, i);
    }
    
}

void deleteMinFromMaxHeap(int arr[], int &n) {
    //Type your code here
    if(n<=0){
        return;
    }
    
    int minIndex = 0;
    for(int i=1; i<n; i++){
        if(arr[i] < arr[minIndex]){
            minIndex = i;
        }
    }
    
    swap(arr[minIndex], arr[n-1]);
    n--;
    
    maxHeapify(arr, n, minIndex);
    
}

void printHeap(const int arr[], int n) {
    //Type your code here
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    
    cout << endl;
    
}



// Question 4
void swap(int *x, int *y) {
    //Type your code here
    int temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(int arr[], int n, int i) {
    //Type your code here
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < n && arr[left] < arr[smallest]){
        smallest = left;
    }
    
    if(right < n && arr[right] < arr[smallest]){
        smallest = right;
    }
    
    if(smallest != i){
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
    
    
}

void buildMinHeap(int arr[], int n) {
    //Type your code here
    
    for(int i=(n-1)/2 ; i>=0; i--){
        minHeapify(arr, n, i);
    }
    
    
}

int filterElements(int arr[], int *n, double avg) {
    //Type your code here
    
    int newSize = 0;
    for(int i=0; i<*n; i++){
        if(arr[i] >= avg){
            arr[newSize] = arr[i];
            newSize++;
        }
    }
    *n = newSize;
    buildMinHeap(arr, *n);
    return newSize;
    
    
}

double calculateAverage(int arr[], int n) {
    //Type your code here
    if(n==0) return 0.0;
    double sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    
    double avg = sum/n;
    
    return avg;
    
}


// Question 5
#include<cmath>
void swap(int *x, int *y) {
    //Type your code here
    int temp = *x;
    *x = *y;
    *y = temp;
    
}

void minHeapify(int heap[], int size, int i) {
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
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
    
}

void buildMinHeap(int heap[], int size) {
    //Type your code here
    for(int i=(size-1)/2; i>=0; i--){
        minHeapify(heap, size, i);
    }
    
}

void insertElement(int heap[], int *size, int value) {
    //Type your code here
    heap[*size] = value;
    int index = *size;
    (*size)++;
    
    while(index > 0){
        int parent = (index-1)/2;
        if(heap[parent] > heap[index]){
            swap(&heap[parent], &heap[index]);
            index = parent;
        }else{
            break;
        }
    }
}

void displayMinHeap(int heap[], int size) {
    //Type your code here
    for(int i=0; i<size; i++){
        cout << heap[i] << " ";
    }
    
    cout << endl;
    
}

bool isPrime(int num) {
    //Type your code here
    if(num <= 1){
        return false;
    }
    
    for(int i=2; i<= sqrt(num); i++){
        if(num%i == 0){
            return false;
        }
    }
    
    return true;
    
}

void deleteSmallestPrime(int heap[], int *size) {
    //Type your code here
    int smallestPrimeIndex = -1;
    int smallestPrimeValue = -1;
    
    for(int i=0; i<*size; i++){
        if(isPrime(heap[i])){
            if(smallestPrimeIndex == -1 || heap[i] < smallestPrimeValue){
                smallestPrimeIndex = i;
                smallestPrimeValue = heap[i];
            }
        }
    }
    
    if(smallestPrimeValue != -1){
        heap[smallestPrimeIndex] = heap[*size - 1];
        (*size)--;
        
        minHeapify(heap, *size, smallestPrimeIndex);
    }
    
}



// Question 6
void swap(int* a, int* b) {
    //Type your code here  
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int size, int root) {
    //Type your code here  
    int largest = root;
    int left = 2*root + 1;
    int right = 2*root + 2;
    
    if(left < size && arr[left] > arr[largest]){
        largest = left;
    }
    
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }
    
    if(largest != root){
        swap(&arr[largest], &arr[root]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    //Type your code here
    for(int i=size/2 - 1; i>=0; i--){
        heapify(arr, size, i);
    }
    
    for(int i=size-1; i>=0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}




// Question 7
void swap(int* a, int* b) {
    //Type your code here  
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int size, int root) {
    //Type your code here  
    int largest = root;
    int left = 2*root + 1;
    int right = 2*root + 2;
    
    if(left < size && arr[left] > arr[largest]){
        largest = left;
    }
    
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }
    
    if(largest != root){
        swap(&arr[largest], &arr[root]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    //Type your code here
    for(int i=size/2 - 1; i>=0; i--){
        heapify(arr, size, i);
    }
    
    for(int i=size-1; i>=0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}




// Question 8
void swap(int* a, int* b) {
    //Type your code here  
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int size, int root) {
    //Type your code here  
    int largest = root;
    int left = 2*root + 1;
    int right = 2*root + 2;
    
    if(left < size && arr[left] > arr[largest]){
        largest = left;
    }
    
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }
    
    if(largest != root){
        swap(&arr[largest], &arr[root]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    //Type your code here
    for(int i=size/2 - 1; i>=0; i--){
        heapify(arr, size, i);
    }
    
    for(int i=size-1; i>=0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int* filterBelow30(int arr[], int size, int* count) {
    //Type your code here
    int *result = new int[size];
    *count = 0;
    
    for(int i=0; i<size; i++){
        if(arr[i] < 30){
            result[*count] = arr[i];
            (*count)++;
        }
    }
    
    return result;
}




// Question 9
void swap(int* a, int* b) {
    //Type your code here  
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int size, int root) {
    //Type your code here  
    int largest = root;
    int left = 2*root + 1;
    int right = 2*root + 2;
    
    if(left < size && arr[left] > arr[largest]){
        largest = left;
    }
    
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }
    
    if(largest != root){
        swap(&arr[largest], &arr[root]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    //Type your code here
    for(int i=size/2 - 1; i>=0; i--){
        heapify(arr, size, i);
    }
    
    for(int i=size-1; i>=0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}




// Question 10
void MaxHeapify(int arr[], int N, int i)
{
    //Type your code here
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < N && arr[left] > arr[largest]){
        largest = left;
    }
    
    if(right < N && arr[right] > arr[largest]){
        largest = right;
    }
    
    if(largest != i){
        swap(arr[largest], arr[i]);
        MaxHeapify(arr, N, largest);
    }
}
void MaxHeapSort(int arr[], int N)
{
    //Type your code here
    for(int i=N/2-1; i>=0; i--){
        MaxHeapify(arr, N, i);
    }
    
    for(int i=N-1; i>0; i--){
        swap(arr[0], arr[i]);
        MaxHeapify(arr, i, 0);
    }
}
void MinHeapify(int arr[], int n, int i)
{
    //Type your code here
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < n && arr[left] < arr[smallest]){
        smallest = left;
    }
    
    if(right < n && arr[right] < arr[smallest]){
        smallest = right;
    }
    
    if(smallest != i){
        swap(arr[smallest], arr[i]);
        MinHeapify(arr, n, smallest);
    }
}
void MinHeapSort(int arr[], int n)
{
    //Type your code here
    for(int i=n/2-1; i>=0; i--){
        MinHeapify(arr, n, i);
    }
    
    for(int i=n-1; i>0; i--){
        swap(arr[0], arr[i]);
        MinHeapify(arr, i, 0);
    }
}
void printHeapArray(int arr[], int n)
{
    //Type your code here
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}




