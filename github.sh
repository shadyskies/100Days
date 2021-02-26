#!/bin/bash

while IFS="\n" read a b; do
    git status
    git commit -m "$1" & git push
done < github_cred.txt