#!/bin/bash
echo "main:"
objdump -d ex5 -M intel | sed '/<main>:/,/^$/!d'
echo "fun:"
objdump -d ex5 -M intel | sed '/<.*fun.*>:/,/^$/!d'

