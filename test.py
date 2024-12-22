import os
import shutil
path = "C:/Users/nguye/Desktop/CHUYENTIN/GIT"

for nxt in os.listdir():
	for (root, dirs, file) in os.walk(path + "/" + nxt):
	    for f in file:
	        if '.cpp' in f:
	        	shutil.copy(path + "/" + nxt + "/" + f, path)