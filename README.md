# Base32 Conversion

>Base32 encoding and decoding algorithm implemented in C.

Compile:

```powershell
gcc base32.c utils.c -o base32
```
---
Ask For Help:

>```base32 -h 'or' base32 --help```

Output:

```

Usage: base32  --<mode> <data>
|CLI options|:-
        <data> = A data string which will be manipulated.
        <mode>:
                -e, --encode = Encodes the data string
                -d, --decode = Decodes the data string
```
---
## Encoding:
```powershell
base32 --encode "Hack Teh World"
```
Output:
```
SGFjayBUZWggV29ybGQ=
```
---
## Decoding:
```powershell
base32 --encode "SGFjayBUZWggV29ybGQ="
```
Output:
```
Hack Teh World
```
___
<p align=center>&copy; This tool is based on UTF-8 charset.</p>