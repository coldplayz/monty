[
	/* previous code */
	> + # read in n values (in this case 2)
	[<+>-]<. #add the values and print out:
]

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

/* Return to c1 for addition */
<

/* Addition time */
[		Addition loop
	<+	Go to c0 and increment value by one
	>-	Return to c1 and decrement value by one
]		When *c1 reaches 0 loop ends; iteration *c1 times

/* Now convert *c0 to ASCII value by adding 48 */
++++ ++++	Set *c1 to 8
[		Loop to add 6 to *c0 for 8 times
	<++++++	Go to c0 and add 6 to current value
	>-	Return to c1 and decrement value by one
]		On *c1 reaching 0 loop ends; iteration 8 times

/* Go to c0 and print value */
<.	
