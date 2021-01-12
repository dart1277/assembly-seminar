#!/bin/bash
echo "main:"
objdump -d ex6 -M intel | sed '/<main>:/,/^$/!d'



