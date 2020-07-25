#include<iostream>
using namespace std;

//Stack - Vector as object is in stack ,its cs and capacity is in stack
//Heap - Array is stored in Heap

//vptr is in heap but its reference is in stack
//delete vptr removes memory from heap allocated to vptr
//whereas vptr as a variable is removed from stack at end of function call
template<typename T>
class Vector {
    T *arr;    //Pointer to array
    int cs;    //Current Size of vector
    int capacity;    //capacity of vector
public :
    /*

    If we write "const Vector<T> &X" then there is error

    */
    Vector(const Vector<T> &X) {    //When we don't modify parameter
        //When we make parameter const then we have to 
        //every func member of object as returning const value
        
        //cout<<"In copy constructor";
        cs = X.size();
        capacity = X.getCapacity();
        
        //Deep Copy
        arr = new T[capacity];
        
        for(int i = 0;i < cs;i++) {
            arr[i] = X.arr[i];
        }
    }

    Vector(int ds = 1) {    //constructor to initialize vector
        capacity = ds;      //by default capacity 1
        arr= new T[capacity];
        cs = 0;     //current size as 0
    }
    void push_back(T data) {    //inserting single element in vector
        if(cs == capacity) {
            //Expand curr Array
            T *oldArr = arr;
            arr= new T[capacity<<1];
            for(int i = 0;i < capacity;i++) {
                arr[i] = oldArr[i];
            }
            delete [] oldArr;
            capacity = capacity<<1;
        }
        arr[cs++] = data;
    }
    void pop_back() {   //deleting one element of vector
        if(cs == 0) {
            return;
        }
        cs--;   //deleting can be considered as reducing current size 
                //next time when we add a element it gets overwrited
    }
    T at(int i) {   //to get element at ith position
        return arr[i];
    }
    void operator!() {  //overloading NOT operator
        for(int i = 0;i < cs;i++) {
            arr[i] = -arr[i];
        }
    }

    void operator+(T x) {   //overloading + operator
        for(int i = 0;i < cs;i++) {
            arr[i] += x;
        }
    }

    void operator()() {    //overloading () operator
        cout<<"\nLOL\n";
    }

    T& operator[](int i) {    //overloading [] operator
        return arr[i];      // return by reference
    }

    int size() const{       //Const func is func which does not modify data members of class
        return cs;          //returning current size of vector
    }
    int getCapacity() const{
        return capacity;    //returning capacity of vector
    }
    void setCapacity(int c) {   //setting capacity of vector as c
        if(c >  0) {
            capacity = c;
        }
    }
    /*
    void setSize(int n) {       //set size of vector
        if(n > 0 && n <= capacity) {
            cs = n;
        }
    }
    */

   ~Vector() {      //calling destructor
       cout<<"\nDeleting vector!\n";
   }
};

//Class k bahar
ostream& operator<<(ostream &a,Vector<int> &v) {    //overloading << operator for functioning of cout on Vector object
    for(int i = 0;i < v.size();i++) {
        a<<v[i]<<',';
        //cout<<v[i]<<',';
    }
    return a; // Making cascading valid
}

void operator>>(istream &a,Vector<int> &v) {     //overloading >> operator for functioning of cin on Vector object
    int n;
    cin>>n;
    /*
    v.setCapacity(n<<1);
    v.setSize(n);
    for(int i = 0;i < n;i++) {
        a>>v[i];
    }
    */
    for(int i = 0;i < n;i++) {
        int temp;
        a>>temp;
        //cin>>temp;
        v.push_back(temp);
    }
        //return a for making cascading of cin valid
        //for this make return type istream&
}

int main() {
    /*
    Vector<int> v;
    v[0] = 1;
    cout<<v[0];
    */
    
    Vector<int> *vptr = new Vector<int>;
    delete vptr;    //destructor is called
    //constructor, copy constructor, copy assignment operator, destructor
    //These four are by default present in a class

    Vector<int> v,v1;
    cin>>v;
    cin>>v1;
    cout<<v<<endl<<v1;
    Vector<int> v2(v);      //Statement same as Vector<int> v2 = v;
    //Arrays of v and v2 is same
    //Deep Copy - when we copy the vector such that v and v2 don't have same array
    //i.e. copying element by element
    v2[1] = 100;
    cout<<endl<<v<<endl<<v2;

    v2 = v;   //Copy Assignment operator ,Not default copy constructor
    //Makes a shallow copy just like default copy constructor
    
    /*
    for(int i = 0;i <= 5;i++) {
        v.push_back(i * i);
    }
    */
   
    for(int i = 0;i < v.size();i++) {
        cout<<v.at(i)<<"  ";         //Statement same as cout<<v[i]<<"  "; as we have overloaded [] operator
    }
    cout<<"\nCapacity : "<<v.getCapacity();
    !v;
    cout<<endl;
    for(int i = 0;i < v.size();i++) {
        cout<<v.at(i)<<"  ";
    }
    v + 3;
    cout<<endl;
    for(int i = 0;i < v.size();i++) {
        cout<<v.at(i)<<"  ";
    }
    v(); //Functional Object in C++ ,Also known as Functor

    return 0;
}