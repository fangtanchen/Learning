echo hello; echo there

filename=t.txt
if [ -x "$filename" ]; then
	
	echo "File $filename exists."; cp $filename $filename.bak
else
	echo "Files $filename not found."; touch $filename
fi; echo "File test complete."
