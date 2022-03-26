# Base32 Converter | <a href="https://www.codacy.com/gh/SynAcktraa/base32-Converter/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=SynAcktraa/base32-Converter&amp;utm_campaign=Badge_Grade"><img src="https://app.codacy.com/project/badge/Grade/49a87a43344d4fbdbd4d99c42b8457d9"/></a> |

>A cli tool based on Base32 algorithm to encode and decode data.

## Help

>`base_32 -h`

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
./base_32 -d KN2GC4RAMFXGIICGN5ZGWIDUNBUXGICQOJXWUZLDOQQDUKI=

```

Output:
```bash
Star and Fork this Project :)
```
---
<p align=center>&copy; This tool is based on ASCII charset.</p>
