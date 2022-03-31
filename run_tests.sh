
echo 'Running string test'
g++ test/test_matte_string.cpp src/matte_string.cpp
./a.out
rm ./a.out


echo 'Running hashmap test'
g++ test/test_hashmap.cpp src/hashmap.cpp
./a.out
rm ./a.out