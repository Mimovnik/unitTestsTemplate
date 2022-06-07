# unitTestsTemplate
A template for C++ unit testing using google tests.
Testing works by taking input from *.in file in /tests/input/ folder
then saving output to actual-*.txt file in /tests/actual/
and comparing it with your expected output file *.out in /tests/expected/ folder.
## Installing
To install simply clone the repository and run install.sh to clone googletest
then rename unitTestsTemplate/ folder to your projects name
```
git clone https://github.com/Mimovnik/unitTestsTemplate
./install.sh
mv unitTestsTemplate yourProjectsName
```
## Support
For now only Linux is supported
