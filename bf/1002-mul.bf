/* Get input and set bytes */
,		Get input and set it's ASCII value to current byte at cell 0 (c0)
>,		Move to next cell (c1) and do same

/* Convert ASCII values in each cell to their intended value */
>++++++++	Move to c2 and set value to 8 as next loop counter
[		Loop to subtract 48 from values at c0 and c1
	<<------Subtract 6 from *c0
	>------	Subtract 6 from *c1
	>-	Decrement loop counter at c2
]		On *c2==0 loop ends; iteration 8 times

/* Go to outer loop counter c0 */
<<

/* Multiplication time */
[			Multiplication loop; iteration *c0 times
	/* Go to c1 */
	>
	[		Inner loop iteration *c1 times
		>+	Go to c2 and incremeent value by one; c2 will store multiplication result
		>+	Go to c3 and increment value by one; Stores copy of c1 by loop end
		<<-	Return to inner loop counter c1 and decrement value by one
	]		*c1==0? then exit loop
	/* Copy *c3 into *c1 */
	>>		Move to c3
	[
		<<+	Refilling c1
		>>-	by consuming c3
	]
	<<<-		Decrement outer loop counter c0
]			When *c0 reaches 0 loop ends; iteration *c0 times

/* Now convert *c2 to ASCII value by adding 48 */
++++ ++++	Set loop counter at c0 to 8
[		Loop to add 6 to *c2 for 8 times
	>>++++++Go to c2 and add 6 to current value
	<<-	Return to c0 and decrement value by one
]		On *c0 reaching 0 loop ends; iteration 8 times

/* Go to c2 and print value */
>>.	
