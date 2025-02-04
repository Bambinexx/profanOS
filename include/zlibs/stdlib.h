#ifndef STDLIB_ID
#define STDLIB_ID 1007

#include <type.h>

#define get_func_addr ((int (*)(int, int)) *(int *) 0x1ffffb)

/*
int main();
void *calloc(uint32_t nmemb, uint32_t lsize);
void free(void *mem);
void *malloc(uint32_t size);
void *realloc(void *ptr, uint32_t size);
long int a64l(const char *str);
void abort(void);
int abs(int j);
int atexit(void (*func)(void));
double atof(const char *s);
*/

#define calloc(nmemb, lsize) ((void *(*)(uint32_t, uint32_t)) get_func_addr(STDLIB_ID, 3))(nmemb, lsize)
#define free(mem) ((void (*)(void *)) get_func_addr(STDLIB_ID, 4))(mem)
#define malloc(size) ((void *(*)(uint32_t)) get_func_addr(STDLIB_ID, 5))(size)
#define realloc(ptr, size) ((void *(*)(void *, uint32_t)) get_func_addr(STDLIB_ID, 6))(ptr, size)
#define a64l(str) ((long int (*)(const char *)) get_func_addr(STDLIB_ID, 7))(str)
#define abort() ((void (*)(void)) get_func_addr(STDLIB_ID, 8))()
#define abs(j) ((int (*)(int)) get_func_addr(STDLIB_ID, 9))(j)
#define atexit(func) ((int (*)(void (*)(void))) get_func_addr(STDLIB_ID, 10))(func)
#define atof(s) ((double (*)(const char *)) get_func_addr(STDLIB_ID, 11))(s)
#define atoi(s) ((int (*)(const char *)) get_func_addr(STDLIB_ID, 12))(s)
#define atol(s) ((long int (*)(const char *)) get_func_addr(STDLIB_ID, 13))(s)
#define atoll(s) ((long long int (*)(const char *)) get_func_addr(STDLIB_ID, 14))(s)
#define bsearch(key, base, nmemb, size, compar) ((void *(*)(const void *, const void *, uint32_t, uint32_t, int (*)(const void *, const void *))) get_func_addr(STDLIB_ID, 15))(key, base, nmemb, size, compar)
#define canonicalize_file_name(name) ((char *(*)(const char *)) get_func_addr(STDLIB_ID, 16))(name)
#define div(numer, denom) ((div_t (*)(int, int)) get_func_addr(STDLIB_ID, 17))(numer, denom)
#define drand48() ((double (*)(void)) get_func_addr(STDLIB_ID, 18))()
#define drand48_r(buffer, result) ((int (*)(struct drand48_data *, double *)) get_func_addr(STDLIB_ID, 19))(buffer, result)
#define __drand48_iterate(xsubi, buffer) ((void (*)(unsigned short int [3], struct drand48_data *)) get_func_addr(STDLIB_ID, 20))(xsubi, buffer)
#define erand48(xsubi) ((double (*)(unsigned short int [3])) get_func_addr(STDLIB_ID, 21))(xsubi)
#define erand48_r(xsubi, buffer, result) ((int (*)(unsigned short int [3], struct drand48_data *, double *)) get_func_addr(STDLIB_ID, 22))(xsubi, buffer, result)
#define exit(status) ((void (*)(int)) get_func_addr(STDLIB_ID, 23))(status)
#define gcvt(number, ndigit, buf) ((char *(*)(double, int, char *)) get_func_addr(STDLIB_ID, 24))(number, ndigit, buf)
#define getenv(var) ((char *(*)(const char *)) get_func_addr(STDLIB_ID, 25))(var)
#define getpt() ((int (*)(void)) get_func_addr(STDLIB_ID, 26))()
#define jrand48(xsubi) ((long int (*)(unsigned short int [3])) get_func_addr(STDLIB_ID, 27))(xsubi)
#define jrand48_r(xsubi, buffer, result) ((int (*)(unsigned short int [3], struct drand48_data *, long int *)) get_func_addr(STDLIB_ID, 28))(xsubi, buffer, result)
#define l64a(value) ((char *(*)(long int)) get_func_addr(STDLIB_ID, 29))(value)
#define labs(j) ((long int (*)(long int)) get_func_addr(STDLIB_ID, 30))(j)
#define lcong48(param) ((void (*)(unsigned short int [7])) get_func_addr(STDLIB_ID, 31))(param)
#define ldiv(numer, denom) ((ldiv_t (*)(long int, long int)) get_func_addr(STDLIB_ID, 32))(numer, denom)
#define llabs(j) ((long long int (*)(long long int)) get_func_addr(STDLIB_ID, 33))(j)
#define lldiv(numer, denom) ((lldiv_t (*)(long long int, long long int)) get_func_addr(STDLIB_ID, 34))(numer, denom)
#define lrand48() ((long int (*)(void)) get_func_addr(STDLIB_ID, 35))()
#define lrand48_r(buffer, result) ((int (*)(struct drand48_data *, long int *)) get_func_addr(STDLIB_ID, 36))(buffer, result)
#define mblen(s, n) ((int (*)(const char *, uint32_t)) get_func_addr(STDLIB_ID, 37))(s, n)
#define mbstowcs(pwcs, s, n) ((uint32_t (*)(wchar_t *, const char *, uint32_t)) get_func_addr(STDLIB_ID, 38))(pwcs, s, n)
#define mbtowc(pwc, s, n) ((int (*)(wchar_t *, const char *, uint32_t)) get_func_addr(STDLIB_ID, 39))(pwc, s, n)
#define mkdtemp(template) ((char *(*)(char *)) get_func_addr(STDLIB_ID, 40))(template)
#define mkostemp(template, flags) ((int (*)(char *, int)) get_func_addr(STDLIB_ID, 41))(template, flags)
#define mkostemp64(template, flags) ((int (*)(char *, int)) get_func_addr(STDLIB_ID, 42))(template, flags)
#define mkostemps(template, suffixlen, flags) ((int (*)(char *, int, int)) get_func_addr(STDLIB_ID, 43))(template, suffixlen, flags)
#define mkostemps64(template, suffixlen, flags) ((int (*)(char *, int, int)) get_func_addr(STDLIB_ID, 44))(template, suffixlen, flags)
#define mkstemp(template) ((int (*)(char *)) get_func_addr(STDLIB_ID, 45))(template)
#define mkstemp64(template) ((int (*)(char *)) get_func_addr(STDLIB_ID, 46))(template)
#define mkstemps(template, suffixlen) ((int (*)(char *, int)) get_func_addr(STDLIB_ID, 47))(template, suffixlen)
#define mkstemps64(template, suffixlen) ((int (*)(char *, int)) get_func_addr(STDLIB_ID, 48))(template, suffixlen)
#define mktemp(template) ((char *(*)(char *)) get_func_addr(STDLIB_ID, 49))(template)
#define mrand48() ((long int (*)(void)) get_func_addr(STDLIB_ID, 50))()
#define mrand48_r(buffer, result) ((int (*)(struct drand48_data *, long int *)) get_func_addr(STDLIB_ID, 51))(buffer, result)
#define nrand48(xsubi) ((long int (*)(unsigned short int [3])) get_func_addr(STDLIB_ID, 52))(xsubi)
#define nrand48_r(xsubi, buffer, result) ((int (*)(unsigned short int [3], struct drand48_data *, long int *)) get_func_addr(STDLIB_ID, 53))(xsubi, buffer, result)
#define on_exit(func, arg) ((int (*)(void (*)(int, void *), void *)) get_func_addr(STDLIB_ID, 54))(func, arg)
#define posix_memalign(memptr, alignment, size) ((int (*)(void **, size_t, size_t)) get_func_addr(STDLIB_ID, 55))(memptr, alignment, size)
#define ptsname(fd) ((char *(*)(int)) get_func_addr(STDLIB_ID, 56))(fd)
#define qsort(base, nmemb, size, compar) ((void (*)(void *, uint32_t, uint32_t, int (*)(const void *, const void *))) get_func_addr(STDLIB_ID, 57))(base, nmemb, size, compar)
#define qsort_r(base, nmemb, size, compar, arg) ((void (*)(void *, uint32_t, uint32_t, int (*)(void *, const void *, const void *), void *)) get_func_addr(STDLIB_ID, 58))(base, nmemb, size, compar, arg)
#define rand() ((int (*)(void)) get_func_addr(STDLIB_ID, 59))()
#define rand_r(seed) ((int (*)(unsigned int *)) get_func_addr(STDLIB_ID, 60))(seed)
#define random() ((long int (*)(void)) get_func_addr(STDLIB_ID, 61))()
#define random_r(buffer, result) ((int (*)(struct random_data *, int32_t *)) get_func_addr(STDLIB_ID, 62))(buffer, result)
#define realpath(path, resolved_path) ((char *(*)(const char *, char *)) get_func_addr(STDLIB_ID, 63))(path, resolved_path)
#define rpmatch(response) ((int (*)(const char *)) get_func_addr(STDLIB_ID, 64))(response)
#define secure_getenv(name) ((char *(*)(const char *)) get_func_addr(STDLIB_ID, 65))(name)
#define seed48(seed16v) ((unsigned short int *(*)(unsigned short int [3])) get_func_addr(STDLIB_ID, 66))(seed16v)
#define seed48_r(seed16v, buffer) ((int (*)(unsigned short int [3], struct drand48_data *)) get_func_addr(STDLIB_ID, 67))(seed16v, buffer)
#define setenv(name, value, overwrite) ((int (*)(const char *, const char *, int)) get_func_addr(STDLIB_ID, 68))(name, value, overwrite)
#define unsetenv(name) ((int (*)(const char *)) get_func_addr(STDLIB_ID, 69))(name)
#define clearend() ((void (*)(void)) get_func_addr(STDLIB_ID, 70))()
#define putenv(string) ((int (*)(char *)) get_func_addr(STDLIB_ID, 71))(string)
#define srand48(seedval) ((void (*)(long)) get_func_addr(STDLIB_ID, 72))(seedval)
#define srand48_r(seedval, buffer) ((int (*)(long, struct drand48_data *)) get_func_addr(STDLIB_ID, 73))(seedval, buffer)
#define strtod(nptr, endptr) ((double (*)(const char *, char **)) get_func_addr(STDLIB_ID, 74))(nptr, endptr)
#define strtod_l(nptr, endptr, loc) ((double (*)(const char *, char **, locale_t)) get_func_addr(STDLIB_ID, 75))(nptr, endptr, loc)
#define strtof(nptr, endptr) ((float (*)(const char *, char **)) get_func_addr(STDLIB_ID, 76))(nptr, endptr)
#define strtof_l(nptr, endptr, loc) ((float (*)(const char *, char **, locale_t)) get_func_addr(STDLIB_ID, 77))(nptr, endptr, loc)
#define strtol(nptr, endptr, base) ((long int (*)(const char *, char **, int)) get_func_addr(STDLIB_ID, 78))(nptr, endptr, base)
#define strtol_l(nptr, endptr, base, loc) ((long int (*)(const char *, char **, int, locale_t)) get_func_addr(STDLIB_ID, 79))(nptr, endptr, base, loc)
#define strtoll(nptr, endptr, base) ((long long int (*)(const char *, char **, int)) get_func_addr(STDLIB_ID, 80))(nptr, endptr, base)
#define strtoll_l(nptr, endptr, base, loc) ((long long int (*)(const char *, char **, int, locale_t)) get_func_addr(STDLIB_ID, 81))(nptr, endptr, base, loc)
#define strtoul(nptr, endptr, base) ((unsigned long int (*)(const char *, char **, int)) get_func_addr(STDLIB_ID, 82))(nptr, endptr, base)
#define strtoul_l(nptr, endptr, base, loc) ((unsigned long int (*)(const char *, char **, int, locale_t)) get_func_addr(STDLIB_ID, 83))(nptr, endptr, base, loc)
#define strtoull(nptr, endptr, base) ((unsigned long long int (*)(const char *, char **, int)) get_func_addr(STDLIB_ID, 84))(nptr, endptr, base)
#define strtoull_l(nptr, endptr, base, loc) ((unsigned long long int (*)(const char *, char **, int, locale_t)) get_func_addr(STDLIB_ID, 85))(nptr, endptr, base, loc)
#define system(command) ((int (*)(const char *)) get_func_addr(STDLIB_ID, 86))(command)
#define grantpt(fd) ((int (*)(int)) get_func_addr(STDLIB_ID, 87))(fd)
#define unlockpt(fd) ((int (*)(int)) get_func_addr(STDLIB_ID, 88))(fd)
#define valloc(size) ((void *(*)(size_t)) get_func_addr(STDLIB_ID, 89))(size)
#define wcstod(nptr, endptr) ((double (*)(const wchar_t *, wchar_t **)) get_func_addr(STDLIB_ID, 90))(nptr, endptr)
#define wcstod_l(nptr, endptr, loc) ((double (*)(const wchar_t *, wchar_t **, locale_t)) get_func_addr(STDLIB_ID, 91))(nptr, endptr, loc)
#define wcstof(nptr, endptr) ((float (*)(const wchar_t *, wchar_t **)) get_func_addr(STDLIB_ID, 92))(nptr, endptr)
#define wcstof_l(nptr, endptr, loc) ((float (*)(const wchar_t *, wchar_t **, locale_t)) get_func_addr(STDLIB_ID, 93))(nptr, endptr, loc)
#define wcstol(nptr, endptr, base) ((long int (*)(const wchar_t *, wchar_t **, int)) get_func_addr(STDLIB_ID, 94))(nptr, endptr, base)
#define wcstol_l(nptr, endptr, base, loc) ((long int (*)(const wchar_t *, wchar_t **, int, locale_t)) get_func_addr(STDLIB_ID, 95))(nptr, endptr, base, loc)
#define wcstoll(nptr, endptr, base) ((long long int (*)(const wchar_t *, wchar_t **, int)) get_func_addr(STDLIB_ID, 96))(nptr, endptr, base)
#define wcstoll_l(nptr, endptr, base, loc) ((long long int (*)(const wchar_t *, wchar_t **, int, locale_t)) get_func_addr(STDLIB_ID, 97))(nptr, endptr, base, loc)
#define wcstombs(s, pwcs, n) ((size_t (*)(char *, const wchar_t *, size_t)) get_func_addr(STDLIB_ID, 98))(s, pwcs, n)
#define wcstoul(nptr, endptr, base) ((unsigned long int (*)(const wchar_t *, wchar_t **, int)) get_func_addr(STDLIB_ID, 99))(nptr, endptr, base)
#define wcstoul_l(nptr, endptr, base, loc) ((unsigned long int (*)(const wchar_t *, wchar_t **, int, locale_t)) get_func_addr(STDLIB_ID, 100))(nptr, endptr, base, loc)
#define wcstoull(nptr, endptr, base) ((unsigned long long int (*)(const wchar_t *, wchar_t **, int)) get_func_addr(STDLIB_ID, 101))(nptr, endptr, base)
#define wcstoull_l(nptr, endptr, base, loc) ((unsigned long long int (*)(const wchar_t *, wchar_t **, int, locale_t)) get_func_addr(STDLIB_ID, 102))(nptr, endptr, base, loc)
#define wctomb(s, wchar) ((int (*)(char *, wchar_t)) get_func_addr(STDLIB_ID, 103))(s, wchar)
#define itoa(value, str, base) ((char *(*)(int, char *, int)) get_func_addr(STDLIB_ID, 106))(value, str, base)

#endif
