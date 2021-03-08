## type casting:
### 1.implicit conversions:
    -->done by compiler by its own when expressions containing more than 1 data type
    -->hierarchy flow:
        bool-char-short int-int-unsigned int-long-unsigned-long long-float-double-long long
    -->can result in loss of info(sign,overflow)

### 2.Explicit conversions:
    1.c-style type casting 
        -->not safe every time
        --> may be info loss or overflow
        done by (int)a
    2.static_cast
    3.dynamic_cast
    3.const_cast
    4.reinterpret_cast
refer-->[here](https://en.cppreference.com/w/cpp/language/expressions) for these casts for deailed info
