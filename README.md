# ft\_printf

This is my 42 ft\_printf, a recode of the libc printf.

**Score 112/100**

## Mandatory Options Handled

 - Format specifiers `%d`, `%i`, `%o`, `%u`, `%x`, `%X`, `%p`, `%s`, `%c`, `%f`, `%%`
 - Format flags `0`, `' '`, `#`, `-`, `+`
 - argument size modifiers `hh`, `h`, `l`, `ll`, `L`
 - field width
 - precision

## Bonuses Implemented

 - Arbitrary argument selector `$`
 - Implemented sprintf, snprintf, asprintf, dprintf, and their variadic (v-) versions.
 - Added ft\_sbprintf, to print to my own stringbuilder class in my libft.
 - Print memory specifier `%m` prints raw memory starting at given address
   - Default output in hexadecimal, alternate form `#` displays ascii, replacing nonprintable with `.`
   - Precision specifies number of bytes; default 4.
   - Can be used with `hh`, `h`, `l`, `ll`, `L`, for 1, 2, 8, 8, 16 byte defaults.
 - Print binary specifier `%b` prints raw memory starting at given address
   - Prints a bitstring, alternate form `#` places `.` between every 4 bits.
   - Precision specifies number of bytes; same options as `%m`
 - `%{underline red green-background}` unix terminal text formatting with keywords.

## Credits

All code is written by me.
