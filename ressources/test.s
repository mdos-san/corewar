.name "test"
.comment "test champ"

and r2, r2, r2
sti r1, %:yolo, %1
sti r1, %:toto, %1
toto:
	live %1
	fork %:yolo
	zjmp %:toto

yolo:
	live %1
	zjmp %:yolo
