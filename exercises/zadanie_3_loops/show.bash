#!/bin/bash
echo "main:"
objdump -d ex3 -M intel | sed '/<main>:/,/^$/!d'
echo "fun:"
objdump -d ex3 -M intel | sed '/<.*loop.*>:/,/^$/!d'

