rm shell-cleanedwords.txt

# Reading word file
echo "\nReading word list file..."
cat $1 >> dirtyfile.txt


# Clean words line by line from the input file

echo "Trimming whitespaces..."
sed 's/^[[:blank:]]*//;s/[[:blank:]]*$//' dirtyfile.txt > nowhitespace.txt

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

echo "Finalising cleaned file..."
cat noblanks.txt > shell-cleanedwords.txt

echo "Wordlist cleaning complete!\n"

rm dirtyfile.txt
rm sorted.txt
rm noduplicates.txt
rm nopunct.txt
rm limitstringsmall.txt
rm limitstringlarge.txt
rm nonumerals.txt
rm noblanks.txt
rm nowhitespace.txt
