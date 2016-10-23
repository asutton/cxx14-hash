# cxx14-hash
An object hashing facility.

This facility is based on the C++ standards propoosal "Types don't know #" by Howard Hinnant, which can be found here:

http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3980.html

The default hasher is an implementation of FNV1a for 32 and 64 bit systems. More details on the FNV1 algorithm can be found here:

http://www.isthe.com/chongo/tech/comp/fnv/index.html

