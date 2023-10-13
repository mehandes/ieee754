#!/bin/bash 

awk -F"\t" -v executable=$2 -v filename=$1 'BEGIN { print "Testing with " filename } {
	if (length($0) > 0) {
		command = ("echo " $2 " | " executable)
  	command | getline r
  
  	if (r == $3)
			print "  " $1 ". OK"
  	else
			print "  " $1 ". FAIL"

  	close(command)
	}
}' $1