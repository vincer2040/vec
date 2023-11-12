# vec
a vector implementation in pure C

## Getting started 

the easiest way to get started is to copy the two files src/vec.c and src/vec.h into your project and compile them 
along with your binary. You can also install the library (see [installing](#installing))

## Usage 

#### basic usage

note that `vec_free` takes in a function to free the individual elements. It is ignored if NULL is passed

```c
#include "vec.h"
#include <stdio.h>

int main() {
  vec* vec = vec_new(sizeof(int));
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  int out;
  vec_push(&vec, &a1);
  vec_push(&vec, &a2);
  vec_push(&vec, &a3);
  vec_push(&vec, &a4);
  vec_pop(vec, &out);
  printf("%d\n", out); // 4
  printf("%lu\n", vec->len); // 3
  vec_free(vec, NULL);
  return 0;
}
```

#### other functions 

```c
#include "vec.h"
#include <stdio.h>

int main() {
  vec* vec = vec_new(sizeof(int));
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  int* out1;
  int out2;
  vec_push(&vec, &a1);
  vec_push(&vec, &a2);
  vec_push(&vec, &a3);
  vec_push(&vec, &a4);
  out1 = vec_get_at(vec, 1);
  printf("%d\n", *out1); // 2
  vec_remove_at(vec, 1, &uot2);
  printf("%d\n", out2); // 2
  printf("%lu\n", vec->len); // 3
  vec_free(vec, NULL);
  return 0;
}
```

## Installing  

1. Clone this repo

```
git clone https://github.com/vincer2040/vec
```

2. build and install

```
cd vec
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
make install
```

the default install path is /usr/local/lib

