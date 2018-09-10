# cppvar
abomination or not - a `var` type for C++ a la Javascript

<br>

## Usage

This library is used in the Express language runtime to enable the dynamic `var` type.

<br>

## How-To
In practice, for the most part, this library enables the ability to use variables in your C++ code just as you would use a variable in Javascript.

On average, you will experience a performance decrease of a factor of 3x using the dynamically typed int variables vs statically typed int variables in a standard multiply-accumulate scenario over a million operations.
The loss will be greater if more runtime conversions need to be done. <br>
See and run the test example in `test/test.cpp` using `run_test`.

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

1) You currently cannot use a `struct`, any user-defined type, or an `[]` (array) as the value of the dynamic variable.
2) Objects must map a `string` key to a `var` value