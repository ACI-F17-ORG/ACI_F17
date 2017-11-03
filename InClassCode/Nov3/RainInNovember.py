"""Summer in November to Remember the 5th"""
import random, time
print "it's raining"
	
rain = random.randint(12, 15) 
for n in range(5):
	for waiting in range(rain):
		space = random.randint(1, 3) * " "
		print "|"+space,
	print ""
	time.sleep(1)

print "_______(((        )))              (( ))   (()) _________"