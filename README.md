# Base32 Converter | <a href="https://www.codacy.com/gh/SynAcktraa/base32-Converter/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=SynAcktraa/base32-Converter&amp;utm_campaign=Badge_Grade"><img src="https://app.codacy.com/project/badge/Grade/49a87a43344d4fbdbd4d99c42b8457d9"/></a> |

>A cli tool based on Base32 algorithm to encode and decode data.

## Help

>`./base_32 -h`

Output:

```terminal
*IMP*: Put space separated data in quotes.
|CLI options|:-
        -e - Encodes the data string
        -d - Decodes the data string
        -i - takes next argument as data string
        -f - takes next argument as filename
        -o - takes next argument as filename and saves the output in file
             (if filename is not given, it defaults to base64Out)
```
---
## Encoding

```bash
./base_32 -e -i "Portable cli tool o_O"
```
Output:

```bash
KBXXE5DBMJWGKIDDNRUSA5DPN5WCA327J4==
```
---

```bash
./base_32 -e -f infile
```
Output:

```bash
KN4W4QLDNN2HEYLB
```
---
## Decoding
```bash
./base_32 -d -f encoded
```
Output:

```terminal
small portable base64-converter in C.
```
---
```bash
./base_32 -d -i KN2GC4RAMFXGIICGN5ZGWIDUNBUXGICQOJXWUZLDOQQDUKI=

```
Output:

```bash
Star this project :), it boosts my ego.
```
---

<p align=center>&copy; This tool is based on ASCII charset.</p>
