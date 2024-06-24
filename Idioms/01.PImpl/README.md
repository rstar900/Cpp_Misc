# PImpl
PImpl stands for <b>"Pointer to Implementation"<b>
<br> TODO Explanation <br>

## How to test the example
### Static Linking
```
g++ -c special_point.cpp
ar rcs libspecial_point.a special_point.o
g++ main.cpp -L. -lspecial_point -o main
./main
```

### Dynamic Linking
```
TODO
```
