Strongly (but not completely) based on the Google C++ Style Guide.

Everything must be in english.

"using" statements are not allowed on headers, just in cpps.
"using" namespace statements are not allowed at all. Instead of doing this:
```
using namespace std;
```
do this:
```
using std::cout;
using std::cin;
using std::endl;
```
It avoids using all the namespace, which can cause collision of names.

# Define Guards #
All headers MUST have a #define guard with this format:
```
#ifndef ARMAGIC_<FILE>_H_
#define ARMAGIC_<FILE>_H_
...
#endif
```

# Classes #
Should start with a capital letter and have no underscores.
public, protected and private keywords should not be indented and should appear in this order.
Ex:
```
class MyNewClass {
public:
   MyNewClass();  
   int myMethod();
   int getMyInt();

protected:
   int myProtected_;

private:
   int myInt_;
}
```

# Functions/Methods and Common Variables #
Should start with lowercase letter and have no underscores.
Ex:
```
void myNewMethod();
int myIntVariable = 0;
```

# Class Data Members #
Should always have a trailing underscore
Ex:
```
int myDataMember_;
```

# Namespaces #
All lower case, and it's contents are not indented.

# Braces #
Braces should open beside the code and should have a space before.



For instance, that's all folks.