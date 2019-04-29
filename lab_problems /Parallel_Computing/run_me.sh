---bs---

//Declarations: Each process has a copy
int numPs, totalPs row[4], buf1[2], buf2[2]

Scatter the Matrix to row

if rank % 2 = 0
	buf2[1,2] = row[3,4] 
	Send(buf2 to buf1 of process with a rank of rank +1)
	Receive(buf2 - the first half of next row to buf1)
	row[3,4] = buf[1,2]

else if rank % 2 = 1
	buf2[1,2] = row[1,2]
	Send(buf2 to buf1 of process with a rank of rank +1)
	Receive(buf2 the second half of previous row to buf1)
	row[1,2] = buf[1,2]

//Now each process will have proper set of values
numPs = Number of Ps in that process
Print(numPs)

Gather(All Ps to totalPs variable in root) 



























	Initially I scatter the matrix to 4 process each having one row as an array. 
Then for rank%2 == 0, 
	i store the 2nd and 3rd element of the array in a separate buf
	and send that buffer to rank+1 process. 
Here I receive the buf values from rank+1 process.
In rank%2 == 1, I receive the buf values from rank-1, store the 1st and 2nd array values in a new buf.. store the 1st and 2nd elements of the array as received buf values.. swap new buf and buf.. then send buf to rank-1..
