#!/bin/bash
echo "main:"
objdump -d ex1 -M intel | sed '/<main>:/,/^$/!d'
echo "fun:"
objdump -d ex1 -M intel | sed '/<.*insertion.*>:/,/^$/!d'

