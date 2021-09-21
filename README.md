### eWallet Stack Based Buffer Overflow Practice Application (sbbof)

Multi platform stack based buffer overflow practice application

### Fuzzing Notes:
export AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1
afl-fuzz -i test_cases -o findings /Users/danny/Documents/sbbof/build/ewallet @@
afl-fuzz -i test_cases -o findings /Users/danny/Documents/sbbof/build/ewallet ["test", "3"]


### Win Process Explorer Notes: 
dbghelp.dll path: 
C:\Program Files (x86)\Windows Kits\10\Debuggers\x64\dbghelp.dll

symbols:
srv*c:\symbols*http://msdl.microsoft.com/download/symbols

### Developer Notes:

Kill suspended application:

```bash
jobs 
jobs -l # List
jobs -s # Suspended
jobs -r # Running

kill %1
```