# Base32 Converter | <img src="https://app.codacy.com/project/badge/Grade/939d7a865e4743b4acd7c06faef5f12e"/> |

>A cli tool based on Base32 algorithm to encode and decode data.

## Help

>```base_32 -h```

Output:

```bash
Note: Put space separated data in quotes.
Usage: ./base_32 -e/-d <data>
|CLI options|:-
        -e - encodes the data string
        -d - decodes the encoded data
```
---
## Encoding

```bash
./base_32 -e "Portable cli tool o_O"
```
Output:

```bash
KBXXE5DBMJWGKIDDNRUSA5DPN5WCA327J4==
```
---
## Decoding

```bash
./base_32 -d `KN2GC4RAMFXGIICGN5ZGWIDUNBUXGICQOJXWUZLDOQQDUKI=`

```

Output:
```bash
Star and Fork this Project :)
```
---
<p align=center>&copy; This tool is based on ASCII charset.</p>
