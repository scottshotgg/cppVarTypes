# varcpp
abomination or not - a `var` type for C++ a la js

<br>

## Usage

This library is used in the Express language runtime to enable the dynamic `var` type.

<br>

## How-To

See and run the test example in `test/test.cpp` using `run_test`.
In practice, for the most part, this library enables the ability to use variables in your C++ code just as you would use a variable in Javascript.

```cpp
  // Initialize a new dynamically typed variable and cycle through the primitive types
  var test = 6.66;
  test = '6';
  test = "6";
  test = 6;
  test = true;

  // It can also be an object
  test = {};
  test["6"] = 6.66;
  test["6"] = 6;
  test["6"] = "6";
  test["6"] = true;
  test["6"] = {};

  // ...
```

<br>

## Undefined Behavior _(for now)_

1) You currently cannot use a `struct` or an array as the value of the dynamic variable.
2) Keys for objects must be a `string` for now