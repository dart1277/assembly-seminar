#!/bin/bash
echo "main:"
objdump -d ex1 -M intel | sed '/<main>:/,/^$/!d'
echo "fun:"
objdump -d ex1 -M intel | sed '/<.*insertion_sort3>:/,/^$/!d'
objdump -d ex1 -M intel | sed '/<.*for.*>:/,/^$/!d'
objdump -d ex1 -M intel | sed '/<.*end.*>:/,/^$/!d'

