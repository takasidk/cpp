**unique_ptr:
    unique_ptr<T> foo() 
    --> cant be copied
    --> can move ownership by using move()
    unique_ptr<A> p1(new A)
    unique_ptr<A> p2(p1)----wrong error occured
    unique_ptr<A> p2=move(p1)
    then p2=p1 and p1 will be null
shared_ptr:
    shared_ptr<T> foo()
    --> can be copied many number of times 
    --> ownership is shared
    --> keeps a refernce count of shared pointers
    function:use_count()
    shared_ptr<A> p1
    shared_ptr<A> p2(p1)
    shared_ptr<A> p3=p2
    rcount=3
    deleted by p1.reset()
    then,rcount=2,p1=null
weak_ptr:
    weak_ptr<T> foo()
    --> can hold a non-owning resource address that is owned by shared ptr
    -->provides access to object but reference count will not increase
    ways to access the object:
    expired()--->use_count()==0
            or
    lock()--->expired()?share_ptr<T> (): shared_ptr<T>(*this)
custom Deleter
    -->if we need to call some more functions before deleting the 
        pointer
    we need cutom deletion
        For shared_ptr:
            specified in costructor of smart pointer
            shared_ptr<A> sp(new A(),&deleteA);
            delete can be:
                -->function pointer 
                -->lambda function
                -->functor
        For unique_ptr:
            specified in constructor
            deleter type will be part of unique_ptr type
     refer custom_deleter.cpp for more understanding**
