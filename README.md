# Base32 Conversion

>Base32 encoding and decoding algorithm implemented in C.

## Help:

>```base_32 -h```

Output:

```
Note: Put space separated data in quotes.
Usage: base_32 <opt> "data"
|CLI options|:-
        -e - Encodes the data string
        -d - Decodes the data string
```
---
## Encoding:
```powershell
base_32 -e "Hack Teh World"
```
Output:
```
JBQWG2ZAKRSWQICXN5ZGYZA=
```
---
## Decoding:
```powershell
base_32 -d "JBQWG2ZAKRSWQICXN5ZGYZA="
```
Output:
```
Hack Teh World
```
___
<p align=center>&copy; This tool is based on UTF-8 charset.</p>