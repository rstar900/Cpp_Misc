# PImpl
PImpl stands for <b>"Pointer to Implementation"<b>
<br> TODO Explanation <br>

## How to test the example
### Static Linking
```
cd lib
g++ -c special_point.cpp
ar rcs libspecial_point.a special_point.o
cd ..
g++ main.cpp -Llib. -lspecial_point -o main
./main
```

### Dynamic Linking
```
TODO
```
