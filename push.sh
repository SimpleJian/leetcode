# !/bin/bash

if [ $# = 0 ];
then
	cmd="Just another push"
else
	cmd=$*
fi

git add -A
git commit -m "$cmd"
git pull origin master
git push origin master
