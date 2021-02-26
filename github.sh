#!/bin/bash

while IFS="\n" read a b; do
    git status
    git commit -m "$1" 
    git push "https://$a:$b@100Days.biz/file.git" --all
done < github_cred.txt