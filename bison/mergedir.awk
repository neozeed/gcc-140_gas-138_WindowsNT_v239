# This is an awk program to insert the value of the variable `dir'
# into the file names in the #line commands in bison.simple.
# Out of laziness, we assume the file name in the text is bison.simple.
$1 == "#line" { print $1, $2, "\"" dir "/bison.simple\"" }
$1 != "#line"
