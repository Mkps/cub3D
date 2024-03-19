#!/bin/bash

find src/* -name "*.c" | cut -d'/' -f2- | sed s/$/' \\'/
