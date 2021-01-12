#!/bin/bash
echo "main:"
objdump -d ex4 -M intel | sed '/<main>:/,/^$/!d'
echo "fun:"
objdump -d ex4 -M intel | sed '/<.*clobber.*>:/,/^$/!d'

