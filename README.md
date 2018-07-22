c-pbe-with-md5-and-des
========

Password Based Encryption with MD5 and DES algorithm written in C

What you need
-------------

Install the next software.

`sudo apt-get install git gcc gdb make libssl-dev`

Build
-----

Clone this repository.

`git clone https://github.com/gustavorv86/c-pbe-with-md5-and-des`

Go to repository folder and run make command.

```
cd c-pbe-with-md5-and-des
make
```

Run examples
------------

Run the **load_environment** script to load the **LD_LIBRARY_PATH**.

`. load_environment`

Go to **dist** directory and run the examples.

```
cd dist
./pbe_md5_des_test_main
```
