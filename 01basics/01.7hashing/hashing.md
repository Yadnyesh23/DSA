# Hashing


Given array = {1, 2, 3 , 2, 1, 2}
find the frequency of 1, 2, 3 in array

```cpp
int freq(int num, int arr[]){
    int count;
    for(int i = 0 ; i < arr.size(); i++){
        if(num == arr[i]){
            count++;
        }
    }
    return count;
}
```

In this, to find frequency of each num we loop through complete array. So for each num time complexity is O(n) suppose there are 3 numbers so it becomes 3 x O(n)

What is hashing?

suppose the array is {1,2,3,2,4,1,5,4} -> This array has numbers from 0 to 5

in hashinh we will store the new array called hash array
initially all will be 0
hash_array = { 0,  0,  0,  0,  0,  0} -> In this array count of each number si stored
             | 0 | 1 | 2 | 3 | 4 | 5 |

hash_array  after counting= { 0,  2,  2,  1,  2,  1} 
                            | 0 | 1 | 2 | 3 | 4 | 5 |