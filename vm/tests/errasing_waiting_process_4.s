.name  "test"
.comment "Testing champ"

ld %16777215, r2
live %-1
fork %8
st r2, 8
aff r2
live %-1

