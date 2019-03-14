if [ "$#" -ne 1 ];
then
	echo "Command incomplete"
	echo "Commit message as arg[1]"
	exit -1
else
	#Add the files
	git add .

	#Commit to local repository
	git commit -m "$1"

	#Push to the remote repository
	git push origin master
	
	exit 0
fi
