#!/bin/bash
echo "main:"
objdump -d ex2 -M intel | sed '/<main>:/,/^$/!d'
echo "fun:"
objdump -d ex2 -M intel | sed '/<.*branch.*>:/,/^$/!d'

