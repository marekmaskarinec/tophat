cd umka

IMPORTS=`ls **.um | awk '{split($0,a," "); for (x in a) {print "\t\""a[x]"\""}}'`
echo -e "// Test for import warnings and errors.\n// Autogenerated by \`cmd/buildallt.sh\` \nimport (\n$IMPORTS\n)" > ../tests/allt.um
