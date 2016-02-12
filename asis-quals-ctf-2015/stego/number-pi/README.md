# ASIS Quals CTF 2015: Number π

**Category:** Stego
**Points:** 200
**Solves:** 2
**Description:**

> Find the flag in this [file](http://tasks.asis-ctf.ir/PI_number_633904b78afdee334b7020dccefbfe39).

## Write-up

by [polym](https://github.com/abpolym)

We extract the file using `unxz` and get a PNG according to `file`.

The PNG shows us a filesystem, the PI symbol and a binary string:

	1101010000000101000101000000010000100100000001010001010000000101001111000000000001110100000000000110010000000000001111000000001111000100000000110001100000000100011101000000000000101100000001101001010000010101000111000000000001110100000001001001000000000010101111000000111010111100000011101011110000001111110001000000000001110100000001101011110000001100011101000000010101011100000001101001010000010101110000000000100101011100000001110110010000000001010111000000011111000100000000101011110000001100001011000000000100011100000000001001000000000010101111000000110001110100000000010101110000000110000000000000110110000100000000

First, we try to decode this string using a binary to ascii converter, but this process is fruitless.

The PNG tells us to search for the keywords `filesystem` and `PI`, which leads us to a filesystem `πfs` that stores data in π, which is [open source](https://github.com/philipl/pifs).

We clone the repository, have to install some libraries with  `sudo apt-get install autogen fuse libfuse2 libfuse-dev` and install the filesystem using `./autogen.sh && ./configure && ./make && sudo ./make install`.

After that, we mount a source directory `/tmp/src` to `/tmp/mnt` using `πfs -o mdd=/tmp/src /tmp/mnt`.

Now, we can copy any file into the src directory and we will receive an ''unπ-ed'' file.

We have to prepend the binary string with two zeroes and save it as a binary file. We can do that using

```bash
echo "00$(echo '<string>' | perl -lpe '$_=pack\"B*\",$_')" > /tmp/src/flagbin
```

Now we just have to look at the content of `/tmp/mnt/flagbin`:

	$ cat /tmp/mnt/flagbin
	ASIS{4716b435ce8ddd6ede25a2926d0c8d42}

## Other write-ups and resources

* <http://khack40.info/asis-quals-ctf-2015-number-pistega-write-up/>
