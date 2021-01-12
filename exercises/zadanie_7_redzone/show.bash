#!/bin/bash
echo "main:"
objdump -d ex7 -M intel | sed '/<main>:/,/^$/!d'
echo "fun:"
objdump -d ex7 -M intel | sed '/<.*fun.*>:/,/^$/!d'

