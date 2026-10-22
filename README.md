*This project has been created as part of the 42's curriculum by fhidalgo*

# Libft Library

## Table of contents

- [Libft Library](#libft-library)
  - [Description](#description)
  - [Instructions](#instructions)
    - [Compiling](#compiling)
  - [Recursos](#recursos)
    - [References](#references)
    - [Use of AI](#use-of-ai)
- [Explaining  functions](#explaining-functions)
  - [LIBC - Functions that capitalices letters or viceversa](#libc---functions-that-capitalices-letters-or-viceversa)
  - [LIBC - Functions that does stuff with strings](#libc---functions-that-does-stuff-with-strings)
    - [ft_strlen](#ft_strlen)
    - [ft_strncmp](#ft_strncmp)
    - [ft_strlcpy](#ft_strlcpy)
    - [ft_strlcat](#ft_strlcat)
    - [ft_strchr](#ft_strchr)
    - [ft_strrchr](#ft_strrchr)
    - [ft_strnstr](#ft_strnstr)
  - [LIBC - Functions that does stuff with memory without allocating it](#libc---functions-that-does-stuff-with-memory-without-allocating-it)
    - [ft_memset](#ft_memset)
    - [ft_bzero](#ft_bzero)
    - [ft_memcpy and ft_memmove](#ft_memcpy-and-ft_memmove)
    - [ft_memchr](#ft_memchr)
    - [ft_memcmp](#ft_memcmp)
  - [LIBC - Functions that does stuff with memory allocating it](#libc---functions-that-does-stuff-with-memory-allocating-it)
    - [ft_calloc](#ft_calloc)
    - [ft_strdup](#ft_strdup)
  - [ft_atoi](#ft_atoi)
  - [ADITIONAL FUNCTIONS - Strings](#aditional-functions---strings)
    - [ft_split](#ft_split)
    - [ft_substr](#ft_substr)
    - [ft_strjoin](#ft_strjoin)
    - [ft_strtrim](#ft_strtrim)
    - [ft_striteri](#ft_striteri)
    - [ft_strmapi](#ft_strmapi)
  - [ADITIONAL FUNCTIONS - File descriptor functions](#aditional-functions---file-descriptor-functions)
    - [ft_putchar_fd](#ft_putchar_fd)
    - [ft_putstr_fd](#ft_putstr_fd)
    - [ft_putendl_fd](#ft_putendl_fd)
    - [ft_putnbr_fd](#ft_putnbr_fd)
  - [ft_itoa](#ft_itoa)
  - [List functions](#list-functions)
    - [ft_lstnew](#ft_lstnew)
    - [ft_lstsize](#ft_lstsize)
    - [ft_lstlast](#ft_lstlast)
    - [ft_lstadd_front](#ft_lstadd_front)
    - [ft_lstadd_back](#ft_lstadd_back)
    - [ft_lstiter](#ft_lstiter)
    - [ft_lstdelone](#ft_lstdelone)
    - [ft_lstclear](#ft_lstclear)
    - [ft_lstmap](#ft_lstmap)

## Description

Welcome to my libft project. It contains all of the functions in the 42's libft's assignment that you can divide into 3:

1. **Libc functions** (`ft_` prefix, same behavior as the originals):
   - Character checks and conversion: `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`, `toupper`, `tolower`, `atoi`
   - Memory: `memset`, `bzero`, `memcpy`, `memmove`, `memchr`, `memcmp`, `calloc`
   - Strings: `strlen`, `strlcpy`, `strlcat`, `strchr`, `strrchr`, `strncmp`, `strnstr`, `strdup`
2. **Additional functions**: `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
3. **Linked lists** (`t_list`): `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Instructions

### Compiling

The project includes a Makefile to compile everything. Just run:

```bash
make all
```

To test a specific function that depends on other functions I have a `re_s` rule in the Makefile:

```makefile
re_s: $(TEST)
	@ar rcs libft.a $(TEST)
	@cc THE_FUNCTION.c libft.a
	@echo ""
	./a.out
	@echo ""
	@echo ""
	@make fclean
```

For using it just run:

```bash
make re_s
```

It builds the library from `$(TEST)`, compiles `THE_FUNCTION.c` against it, runs it, and cleans up.


## Recursos

### References
- [Linux man pages](https://man7.org/linux/man-pages/) – `string(3)`, `ctype(3)`, `malloc(3)`, `write(2)`
- [Hermandis - Cómo hacer un Makefile](https://hernandis.me/blog/como-hacer-un-makefile/)

### Use of AI
AI was used for:
- **Debugging**: finding specific errors in some programs, mainly memory allocation issues (`malloc`/`free`, leaks).
- **Theory**: explaining specific details about pointers and linked lists, as a more precise alternative to searching online.
- **README.md**: formatting and structuring the sections.

No AI-generated code was submitted without being understood and reviewed.

# Explaining  functions

I'm meaning this functions
```
ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint
```

All these check what the name sujests. The receive a characer (via int) and returns `0` or `1` if the question is false or true.

What is "the question"? For example "ft_isdigit": Is this char a digit? And so forth.

## LIBC - Functions that capitalices letters or viceversa

I'm meaning

```
ft_tolower, ft_toupper
```

The first one receives a character (via `int`) and turns it into lowercase and the second one, the contrary.

## LIBC - Functions that does stuff with strings

### ft_strlen

You know, a function that receives a string and meassures the lenght of it. Useful as hell.

### ft_strncmp

It compares two strings, at most `n` characters, and returns the difference between the first pair of characters that are different.

So, the code explained:

- We first check if `n` is 0. If so, there is nothing to compare, so we return `0`.

- Then we loop while `i < n`. Inside, we stop when one of three things happens: the characters are different, `s1` ended or `s2` ended. Checking for the `'\0'` is important, because we must not keep reading past the end of a string.

- When that happens, we return the subtraction of both characters, cast to `unsigned char` as the manual says the comparison is done that way. The result is negative if `s1` is smaller, positive if it is bigger.

- If the loop ends without finding any difference in the first `n` characters, the strings are equal for our purposes, so we return `0`.

```
s1 = "hello"   s2 = "help"   n = 4

index:  0 1 2 3
s1:     h e l l
s2:     h e l p
                ^
                'l' - 'p' = negative
```

### ft_strlcpy

It copies a string from a source to a destination. But not all of it, just the size given by `size`. Though, it returns the size of the source everytime, not the copied string.
```
RETURN VALUES
     The strlcpy() and strlcat() functions return the total length of the
     string they tried to create.  For strlcpy() that means the length of src. [...]
```

For doing this we define 
- an index variable 
- the variable that will store the lenght of the source (`s_src`).

We first check if we have size to cpy. If not, we return the size of the original source, as man sais.

If yes, we enter a loop for copying `src`in `dest` till we don't have more source and we are in the `size - 1` index of the array. That `-1` is for booking a bed for the following `\0` that we will add after the loop :).


### ft_strlcat

It basically appends `src` to the end of `dst`, never writing more than `size` bytes in total (the final `'\0'` included).

So, the code explained:

- First I measure `src` with `ft_strlen` (`s_src`).

- Then I track the destination string for knowing where I have to start concatenating from. If `s_dst == size`, `dst` it means it has no `'\0'` inside the buffer, so there is no valid string to append to. I copy nothing and return `s_src + size`.

```
RETURN VALUES
[...]

     Note, however, that if strlcat() traverses size characters without find‐
     ing a NUL, the length of the string is considered to be size and the des‐
     tination string will not be NUL-terminated (since there was no space for
     the NUL).
```

- Otherwise I copy `src` after the end of `dst`, character by character. The loop is
```
index of src + lenght of dest < size - 1
```

Note that we need the `-1` for the ending nul, as always. So it would be `i + s_dst < size - 1`, but, for preventing underflow (as it is a `size_t`) we move the -1 to the other side of the inequation so the final condition is `i + s_dst + 1 < size`.

As always, we add the `'\0'`at the end, and we return what the function expects.

### ft_strchr

It looks for the first appearance of the character `c` in the string `s` and returns a pointer to it.

- I loop while the current character (`*s`) is different from `(char)c`. I cast `c` to `char` because it comes as an `int` and I'm comparing it with a `char`.

- If we don't find the character and we reach the end of the string, it returns `NULL` as in the manual.

Finally we return **the very same string**, that is now moved, but we cast it to char as we received a const char and the outcome has to be a char.

In this case, as the man sais, the nul terminator is part of the string so we don't have to do anything but tracking the string forward.

```
RETURN VALUE
       The strchr() and strrchr() functions return a pointer  to  the  matched
       character  or NULL if the character is not found.  The terminating null
       byte is considered part of the string, so that if  c  is  specified  as
       '\0', these functions return a pointer to the terminator.
```

### ft_strrchr

The same idea as `ft_strchr` but looking for the **last** appearance of `c`.

So, the code explained:

- First we run a loop to the end of the string. When it finishes, `i` is the index of the `'\0'`.

- Then we go backwards from `i` to `0`. The first match I find is the last one in the string, so I return its address right there (`&s[i]`), casting it to `char *` because `s` is `const`.

- Both sides of the comparison are cast to `unsigned char`, so negative `char` values are compared properly.

- If we didn't find it, it exist the loop and returns a `NULL`

Same as before: if `c` is `'\0'`, the first iteration already matches and returns a pointer to the terminator.

```
s = "hello"   c = 'l'

index:  0 1 2 3 4 5
        h e l l o \0
                ^
                returned (index 3, the last 'l')
```

### ft_strnstr

It basically looks for the first appearance of the string `little` inside `big`, searching at most `len` characters, and returns a pointer to where it starts.

- We first check if `little` is empty. If so, the manual says to return `big`, so we do it right away. We cast it to char because big is const char.

- Then we loop through `big` with `i`, as long as we haven't reached its end or the limit `len`. Each `i` is a possible starting point in `big`. It goes to the next position in the string in each iteration.

- At each starting point we reset `j`, (that it the `little`'s starting point) to 0 and run an inner loop that compares `little[j]` with `big[i + j]`. It keeps going while the characters match, `big` hasn't ended and `i + j < len`. That last condition makes sure we never look further than `len` in `big`.

- When the inner loop ends, if we didn't find a match in `little]` so we return the address of `&big[i]` (casting it of course).

- If we run out of `big` or `len` without a full match, we return `NULL`.

```
big = "hello world"   little = "wor"   len = 11

index:  0 1 2 3 4 5 6 7 8 9 10
        h e l l o _ w o r l d
                    ^
                    returned (index 6)
```

## LIBC - Functions that does stuff with memory without allocating it

### ft_memset

It basically fills the first `n` bytes of the memory area pointed to by `s` with the byte `c`.

So, the code explained:

- I declare an **unsigned char** so that C doesn't get crazy trying to guess how much memory it is trying to use. 

- Then I introduce `s`'s information in it (`void_friend`).

- Once done that I overwrite `s`'s information with the given-in-parameter data `c` inside a loop.

The loop will stop when it reaches the quantity of information given in `n`.

Finally the function returns the `s` memory area as said in man:
```
"RETURN VALUE
       The memset() function returns a pointer to the memory area s."
```

### ft_bzero

The same as memset but the previous `c` is  just 0s. And it does not return anything this time according to man.

```
RETURN VALUE
       None.
```

### ft_memcpy and ft_memmove

Again we have to cast so that C doesn't freak out.

We first check that the arrays exist.

The `if` protects the function if you receive two NULLs as arrays. Without that, the loop would try to start in memory that doesn't exist so...  #SegmentationFault xD.

As in the "man" sais that we don't check overlappings, we just loop the string copying one string to the other and return the destination array.

`ft_memmove` does the same, but it handles overlapping memory areas. If `dest` is at a higher address than `src`, it copies from the last byte to the first.

Why? When `dest > src` and the areas overlap, the start of `dest` lies on top of the end of `src`. Copying forward would overwrite source bytes before reading them. Copying backward writes each byte into a place that has already been read (or isn't part of `src`).

```
index:  0 1 2 3 4 5 6 7 8 9
src:    S S S S S S S
dest:         D D D D D D D
                <--- copy direction
```

If `dest < src`, copying forward is safe, so it just calls `ft_memcpy`.


```
DESCRIPTION
       The  memcpy()  function  copies  n bytes from memory area src to memory
       area dest.  The memory areas must not overlap.  Use memmove(3)  if  the
       memory areas do overlap.

RETURN VALUE
       The memcpy() function returns a pointer to dest.
```

```
RETURN VALUE
       The memmove() function returns a pointer to dest.
```

### ft_memchr

The steps:
- I define a const unsigned char because the "man" specifies that ir works internally with unsigned chars.
```
DESCRIPTION
       The  memchr()  function  scans  the  initial n bytes of the memory area
       pointed to by s for the first instance of c.  Both c and the  bytes  of
       the memory area pointed to by s are interpreted as unsigned char.
```
- The pointer goes on while we don't run out of the size given in parameter `n`. Each cicle, n lowers 1, and we push the pointer forward.

It it doesn't find the char, it will return `NULL`. Otherwise it will return our pointer. But, as it returns void, we have to ccast it to void inside.

### ft_memcmp

It compares the first `n` bytes of two memory areas and returns the difference between the first pair of bytes that are different.

So, the code explained:

- We cast both pointers to `const unsigned char *` (`s_a` and `s_b`), because `void *` can't be dereferenced or moved byte by byte, and the manual says the bytes are compared as `unsigned char`.

```
DESCRIPTION
       The  memcmp()  function compares the first n bytes (each interpreted as
       unsigned char) of the memory areas s1 and s2.
```

- We check if `n` is 0. If so, there is nothing to compare, so we return `0`.

- Then we loop while our index `i` is less than the mx size to check (`n`), comparing `s_a[i]` with `s_b[i]`. If they are different, we return their subtraction. The result is negative if the first area is smaller, positive if it is bigger.

- If the loop ends without finding any difference, the areas are equal, so we return `0`.

The difference with `ft_strncmp`: here we don't stop at `'\0'`, because we are comparing raw memory, not strings. A `'\0'` is just another byte.

```
s1 = "ab\0cd"   s2 = "ab\0ce"   n = 5

index:  0 1 2  3 4
s1:     a b \0 c d
s2:     a b \0 c e
                  ^
                  'd' - 'e' = negative
```

## LIBC - Functions that does stuff with memory allocating it

### ft_calloc

It reserves memory for `nmemb` elements of `size` bytes each, and fills all of it with zeros.

- We define `arr`, an `unsigned char` pointer so we can walk the memory byte by byte, and an index `i`.

- If `nmemb` or `size` is 0, we return `malloc(0)`. As the "man"says, `ft_calloc` must return a unique pointer that can be passed to `free()`.

```
RETURN VALUE
[...]
       If nmemb or size is 0,  then  calloc()  returns either  NULL,  or a unique pointer value that can later be successfully
       passed to free().
```

- Then we check for overflow. If `nmemb * size` doesn't fit in a `size_t`, the multiplication would wrap around and we would reserve less memory than requested. To avoid it, we check if `nmemb` is bigger than the max `size_t`value that is `(size_t)(-1)`. If so, we return `NULL`, as the manual says.

- If everything is ok we reserve `nmemb * size` bytes with `malloc`. If it fails, we return `NULL`.

- Finally we loop through every byte and set it to `'\0'`, and we return the pointer.

```
ft_calloc(4, 2)  ->  8 bytes

before (malloc): ? ? ? ? ? ? ? ?   (garbage)
after:           0 0 0 0 0 0 0 0
```

### ft_strdup

It returns a pointer to a new string that is a copy of `src`.

- We reserve memory with `malloc` for the length of `src` **plus 1**. That extra byte is for the `'\0'`, as `ft_strlen` doesn't count it.

- If `malloc` fails, we return `NULL`.

- Then we loop through `src` copying each character into `copy` till we reach the end of `src`.

- After the loop we add the `'\0'` ourselves, because the loop stops before copying it.

We return `copy`. It's a new memory area, so whoever calls `ft_strdup` is responsible for freeing it.


## ft_atoi

It converts the beginning of a string into an `int`.

- We define three variables: `i` for walking the string, `sign` (starts as `1`) and `res`, where we build the number.

- First we skip the whitespace. Those are the characters from `9` to `13` in ASCII. That is following characters found in isspace.

- Then we check for a sign. If there is a `'-'`, we flip `sign` to `-1`. If it is a `'+'`, we do nothing. In both cases we move `i` forward so the sign isn't read as part of the number.

- Then we loop while the current character is a digit (using our `ft_isdigit`). Each iteration we shift what we already have one position to the left (`res * 10`) and add the new digit. `nptr[i] - '0'` turns the character into its numeric value (`'7' - '0' = 7`).

- When we find something that is not a digit (or the `'\0'`), the loop ends and we return `sign * res`. Mutipliying aplies the correct sign to the number.

```
nptr = "  -123abc"

res:  0 -> 1 -> 12 -> 123
              (1*10+2)  (12*10+3)

stops at 'a' -> returns -123
```

## ADITIONAL FUNCTIONS - Strings

### ft_split

Oh my fellow, this function which also splits the hearts to dare to code it.

Well, I have five functions: 
- a word counter
- a letter counter
- the split function itself
- a function that frees things in a certain case
- a line-saver function that Norminette likes xD.

The `count_words` function recieves the string and the separator given to ft_split and counts the words. How? I define an index and a counter, and I trigger a loop. While the string exists two things happen:

- If it finds the separator, simply goes on. 
- When exiting this loop you'll find a non-separator. So an if triggers. This one counts a word, and after that, keeps going till it finds a separator.

This way we count the words of the given string.

The `count_letter` function does similarly but just with the chars. It counts till fiinding a separator.

There we go to the interesting part.

First of all we define two indexes and a double pointer (`grid`). The double pointer will store the splitted string. The `i` index is for tracking the given string. The `j` index is for tracking each string of our new grid double pointer.

- First of all: makes no sense to do anything o this if we have no string xD.

- Once we checked that we malloc the grid with the size of the words, plus 1. So we are just allocating the "first column" of the grid.

- As usual, if malloc failed randomly, the runaway.

One we've done all this, the magic starts.

- As the string exists, we check the separator, as we did defore.
- If it doesn't, an "if" triggers again. But this time what we do is to store the the word in the first position. For that we use a function in our library: `ft_substr`. It uses the `i` index for knowing where to start, and from there it stores the letters of the function. How many? `count_letters`. That many.

`ft_substr` already handles memory of its substring so we are basically using grid as it were a single pointer, not a double (way easier).

But, what if ft_substr fails? What happens with that memory. We don't want leaks. There's where `free_all` functions comes. It basicly tracks the grid pointer reversely freeing each string and, in the end, freeing the whole double pointer.

But if it worked, we define the index as the `i` we had plus the word we checked, and then we go to the next position (`word`) of the grid pointer.

We do this till the string ends.

And at the end we add a `NULL` (we need a string here).

We could have returned the grid pointer, but it had so many lines, so, we created a function that adds the ending null (`str_null_complete`), and the ft_split's functions returns that function.


### ft_substr

It reserves memory and returns a substring of `s`, starting at index `start` and with a maximum length of `len`.

- We first check that `s` exists. If not, we return `NULL`.

- We measure `s` with `ft_strlen` (`s_len`).

- If `start` is beyond the end of `s` (`start >= s_len`), there is nothing to copy, so we return an empty string with `ft_strdup("")`. Returning `NULL` here would be wrong, because it is not an error.

- If `len` is bigger than what is left of `s` from `start` (`s_len - start`), we shorten it to that. This way we never reserve more than needed.

- We reserve `len + 1` bytes with `malloc` (the `+1` is for the `'\0'`). If it fails, we return `NULL`.

- Then we copy from `s[start + i]` into `sub[i]` while `i < len` and `s` hasn't ended.

- Finally we add the `'\0'` and return `sub`.

```
s = "hello world"   start = 6   len = 3

index:  0 1 2 3 4 5 6 7 8 9 10
        h e l l o _ w o r l d
                    ^ ^ ^
sub = "wor"
```

### ft_strjoin

It reserves memory and returns a new string made of `s1` followed by `s2`.

- We check that both strings exist. If not, we return `NULL`.

- We reserve `ft_strlen(s1) + ft_strlen(s2) + 1` bytes (again, the `+1` is for the `'\0'`). If `malloc` fails, we return `NULL`.

- We use three indexes: `i` walks `s1`, `j` walks `s2` and `k` walks the new string `s3`.

- First loop: we copy all of `s1` into `s3`. Second loop: we keep writing in `s3` (`k` doesn't reset) copying all of `s2`.

- We add the `'\0'` at the end and return `s3`.

```
s1 = "foo"   s2 = "bar"

s3 = f o o b a r \0
     ^----^ ^----^
       s1     s2
```

### ft_strtrim

It reserves memory and returns a copy of `s1` without the characters of `set` at the beginning and at the end.

- We define `start` (0) and `end` (the length of `s1`).

- First loop: we move `start` forward while `s1[start]` exists and is a character of `set`. We use `ft_strchr(set, s1[start])` to know if it belongs to `set`.

- Second loop: we move `end` backwards while it is bigger than `start` and the character before it (`s1[end - 1]`) is in `set`. The `end > start` condition makes sure they never cross, for example when the whole string is made of characters of `set`.

- Now the part we want to keep is between `start` and `end`. We reserve `end - start + 1` bytes, and if `malloc` fails we return `NULL`.

- We copy it with `ft_strlcpy` from `&s1[start]`. The size is `end - start + 1` so it also adds the `'\0'`.

```
s1 = "xxhixx"   set = "x"

index:  0 1 2 3 4 5
        x x h i x x
            ^   ^
          start end

trim = "hi"
```

### ft_striteri

It applies the function `f` to every character of the string `s`, giving it the index and the address of the character, so `f` can modify it in place.

- We first check that `s` and `f` exist. If not, we return and do nothing.

- Then we loop while `s[i]` exists. In each iteration, we call f(i, &s[i]): 

  - The first argument is the index
  - The second is the memory address of the character `s[i]`, so `f` can modify `s` in place.


### ft_strmapi

It applies the function `f` to each character of the string `s` to create a new string, passing its index and character as parameters.

- First, we check if `s` or `f` exist. If not, we return `NULL`.

- We reserve memory for the new string (`change`) with malloc for the length of s plus 1 (for the `'\0'`). If malloc fails, we return NULL.

- We loop through `s` using the index `i`. In each iteration, we apply `f(i, s[i])` and store the result in `change[i]`.

When the loop finishes, we add the `'\0'` at the end of `change` and return it.

## ADITIONAL FUNCTIONS - File descriptor functions

### ft_putchar_fd

It writes the character `c` into the file descriptor `fd`.

- We check that `fd` is valid (`fd >= 0`). If not, we do nothing, because `write` would fail anyway.

- We call `write(fd, &c, 1)`. `write` needs an **address**, so we pass `&c`, and `1` is the number of bytes to write.

### ft_putstr_fd

It writes the string `s` into the file descriptor `fd`.

- We check that the string exists. If not, we return and write nothing.

- Then we loop through the string while `s[i]` is not `'\0'`, and we send each character to `ft_putchar_fd`.

### ft_putendl_fd

It writes the string `s` followed by a line break.

It is just `ft_putstr_fd` and then we use `ft_putchar_fd('\n', fd)` for adding the line break.

### ft_putnbr_fd

It writes the integer `n` into the file descriptor `fd`.

- We copy `n` into a `long` (`nb`). The reason is `INT_MIN` (`-2147483648`): if we did `-n` with an `int`, the result (`2147483648`) wouldn't fit and it would overflow. With a `long` it does.

- If `nb` is negative, we write a `'-'` and turn `nb` positive.

- If `nb` has more than one digit (`nb >= 10`), we call the function again with `nb / 10`. That writes all the digits **except the last one**, and in the right order.

- Then we write the last digit: `(nb % 10) + '0'` turns the number into its character (`7 + '0' = '7'`).

```
ft_putnbr_fd(123, 1)

putnbr(123) -> putnbr(12) -> putnbr(1) -> writes '1'
                          -> writes '2'
            -> writes '3'

output: 123
```

## ft_itoa

It receives an int, as requested. I create four variables
- the string that will contain the final number
- a long for casting the given `n` (for avoiding `INT_MAX` and `INT_MIN`)
- an index
- a variable that will store the length of the number.

So we have two cases: negative and positive.

- If it's negative, we need an extra position for the string, so our malloc needs an extra position in the array. 
- If not we reserve only the needed space.

Finally we add the numbers into the array.

For all this we use two auxiliar funtions.

The first one is `num_len`, which measures the lenght of the number and returns its size.

- For that we create a while loop, that sums 1 to a variable (res) and divides the number by 10. 
- At the end, for ensuring we include the final number, we sum 1 again.

The other one is `num_adder`. It receives the destination string, the starting point of it, the number to add and the lenght of the given number. First we store the 10 * length in a variable for using it later this way.

The while loop is true if the lenght is not 0. It shrinks one after each iteration. 

First we add the first number in the start position that. If the number is 12345: 12345 / 10000 = 1. De remainder is the rest of the number 2345 so we store it. The next operation will be 2345 / 1000 = 2... and so on.

## List functions

### ft_lstnew

It creates a node, the basic piece of a linked list. Every list starts with one of these.

- We reserve memory for a `t_list` with `malloc`. If it fails, we return `NULL`.

- We store `content` in the node (`node->content`).

- We set `node->next` to `NULL`, because for now the node is alone and points to nothing.

We return the node.

```
node:  [ content | next ]
          ^         ^
        data      NULL
```

### ft_lstsize

It counts the number of nodes in a linked list.

- We initialize an unsigned int counter i to 0.
- We loop while lst exists. In each iteration, we increment i and move lst forward to the next node (lst = lst->next).

When lst reaches NULL, the loop ends and we return i, that is the times we passed through a node, that is, the number of nodes.

### ft_lstlast

The main logic is "if the next node is NOT null" (which implied it is the last one) keep going in the list. 

If it is, it exits the while and returns the very node.

Obviously we check if the very node exists or not before doing anything else.

```
before:  lst -> [A] -> [B] -> [C] -> NULL
                                  ^
                                  |
returned:                          [C]
```

### ft_lstadd_front

It inserts a node at the **beginning** of the list. 

- We check that `lst` (the address of the pointer to the first node) and `new` exist. If not, we return.

- We make `new->next` point to what was the first node (`*lst`).

- We make `*lst` point to `new`, so the list now starts there.

We need `t_list **` because we are changing **which node is the first one**, and that pointer belongs to the caller.

```
before:  lst -> [A] -> [B] -> NULL
after:   lst -> [new] -> [A] -> [B] -> NULL
```

### ft_lstadd_back

It inserts a node at the **end** of the list, keeping the order in which we add elements.

- We check that `lst` and `new` exist. If not, we return.

- If the list is empty (`*lst == NULL`), `new` becomes the first node and we return.

- Otherwise, we get the last node with `ft_lstlast` and make its `next` point to `new`.

```
before:  lst -> [A] -> [B] -> NULL
after:   lst -> [A] -> [B] -> [new] -> NULL
```

### ft_lstiter

It is for applying a functions to the content of **every** node in a list.

- We check that the list and `f` exist. If not, we return.

- We loop throught `lst` aplyting the fucntion. In each iteration we call `f(lst->content)` and move to the next node.

### ft_lstdelone

It delets **one** node safely, freeing both its content and the node itself.

- We check that the node and the deleting function `del` exist. If not, we return.

- We call the deleting functions `del(lst->content)`. Then we free the node with `free(lst)`.

It doesn't touch the next node. If we want to keep the rest of the list, we must save `lst->next` **before** calling it.

### ft_lstclear

We first define a t_list pointer the we will use as a temporary variable or not losing the reference of what i after the node we want to delete.

We check that the params given are ok.

Then we store the list's next's information in ref.

Now, with the information saved, we delete the content of the node, and free the whole of it.

Now we add the next's information to the list.

### ft_lstmap

It creates create a **new list** by applying a function to the content of each node of another one, leaving the original intact. For example, a list of numbers and another one with each number doubled.

- We check that the list, `f` and `del` exist. If not, we return `NULL`.

- We start with an empty new list (`n_list = NULL`).

- For each node of the original list:
  - We apply `f` to its content (`content`). That gives us the new content.
  - We create a node with `ft_lstnew(content)`.
  - If creating the node fails, we have to clean up everything: we free the content we just created with `del`, we free the whole new list with `ft_lstclear`, and we return `NULL`. This avoids leaks.
  - If it works, we add the node at the end with `ft_lstadd_back`, so the new list keeps the same order.

- When we finish, we return the new list.

```
lst:     [1] -> [2] -> [3]
f: x * 2
n_list:  [2] -> [4] -> [6] 
```






