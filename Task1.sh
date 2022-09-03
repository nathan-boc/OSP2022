rm cleanwords.txt

# Concatenate all word files
echo "Concatenating word list files..."
for f in ./wordlists/*.txt
do
	cat $f  >> concat.txt
	echo >> concat.txt
done


# Clean words line by line from the concatenated file

echo "Trimming whitespaces..."
sed 's/^[[:blank:]]*//;s/[[:blank:]]*$//' concat.txt > nowhitespace.txt

echo "Sorting into alphabetical order..."
sort nowhitespace.txt > sorted.txt

echo "Removing duplicates..."
uniq sorted.txt > noduplicates.txt

echo "Removing words containing punctuation..."
sed '/[[:punct:]]/d' noduplicates.txt > nopunct.txt

echo "Removing words with length outside the range 3-15..."
sed -r '/^.{,2}$/d' nopunct.txt > limitstringsmall.txt
sed -r '/^.{15}./d' limitstringsmall.txt > limitstringlarge.txt

echo "Removing strings containing numerals..."
sed '/[0-9]/d' limitstringlarge.txt > nonumerals.txt

echo "Cleaning blank lines..."
grep "\S" nonumerals.txt > noblanks.txt

echo "Shuffling cleaned file..."
shuf noblanks.txt > cleanedwords.txt

echo "Wordlist cleaning complete!"

rm concat.txt
rm sorted.txt
rm noduplicates.txt
rm nopunct.txt
rm limitstringsmall.txt
rm limitstringlarge.txt
rm nonumerals.txt
rm noblanks.txt
rm nowhitespace.txt
