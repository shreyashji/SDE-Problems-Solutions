//should alwasy map a large key to same small key
//should genrate  values from 0 to m-1
//should be fast ,O(1) for integers ,O(len) for strings of length len
//should uniformly distribute large keys into hash table slots
/*
chaining
M=no. of slots in hash table
n= no. of keys to be inserted
load factor alpha =n/m (we want load factor to be small as possible)
if no. of slots will be high then there is more chances of collison

expected chain length = we dont know (worst case every key inserted in same chain)
expected chain length = alpha
we can implement chaining with linked list & vector

*/