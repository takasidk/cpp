## Queue ADT:(FIFO)
    First In First Out
    deletion at front end 
    insertion at rear end
A list or collection with restriction that insertion can be performed at
one end (rear end) and deletion can be performed at one end (front)
- Operations:\
enqueue(x)\
dequeue()\
front()/peek()\
isEmpty()\
*These will be having constant time complexity O(1).*
- Example:
let say we have a printer shared in a network and printer can print only one
at a point of time So, it can take only one request at a time So, queue ADT
is something like that so we can use here queue structure process requestions
the requests made by computers will be queued 
- Implementation:
#### 1.with array:
So,here the idea is to take an array of some max size and keep tracking of front and rear
element by declaring a front,rear variables to -1 
* enqueue(data)-

      check if its full:
        throw an error then
      if this is first insertion:
        then intialise rear and front to zero
      else:
        increase the rear by one 
       write the array element at rear to the given data
     
* dequeue()-
 
      check if its empty:
        throw an error if it is
      if there is only element(i.e rear==front):
        then intialise back front and rear to -1
      else:
        increase the front by one
        
- For an linear array when we enqueue and dequeue some data we will be left with more 
unused memory at the start of the array So,to overcome this we can use **circular array**
where when ever we increase front or rear increase using modulo method(i.e rear=(rear+1)%n,n is ur array max size)
[Code](https://github.com/takasidk/cpp/blob/master/data_structures/queue/queue_array.cpp)
#### 2.with linked list:
In queue implementation using array we used circular array so that we will 
be able to using the whole array size But, if we have more data to insert but your array is full
then we can create an array double the size of prev array and copy all the elements of prev array
to the new array and delete the prev array But, this is a costly process and 
one more limitation is that we will be having more unused memory to the right of rear end when we have a big array and less data
So, we can use linked list implementation to get out of this limitation/
drawback
- Coming to implementation using linkedlist :
in linkedlist insertion /deltion at front will O(1) But, insertion/deletion
at end will O(n) because we need traverse to end to insert/delete 
So, what we can do is we can declare a pointer rear which we store address
of the end element (will point to the rear Node) so that we no need to 
traverse the whole list
[Code](https://github.com/takasidk/cpp/blob/master/data_structures/queue/queue_linkedlist.cpp)
