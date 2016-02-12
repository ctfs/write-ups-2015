# Hackcon 2015: Watch me surf the internet

**Category:** Binary
**Points:** 75
**Author:** [Aneesh Dogra](https://github.com/lionaneesh)
**Difficulty:** Medium
**Description:** 

> Get the flag from the pcap file in the directory.

## Write-up

by [polym](https://github.com/abpolym)

This writeup is based on a very good writeup by [vimvaders](http://vimvaders.github.io/hackcon2015/2015/08/20/watch-me-surf-the-internet.html).

We are given a gzip compressed pcap that we first uncompress using `gunzip spying.pcapng.gz`.

Looing at the traffic conversation with `wireshark` or `tshark`, we notice nothing that stands out.

However, the author hid the flag in the source port of some TCP requests.

There are several tcp requests that originate from ports such as `10102` or `10114` - all slightly over `10000`.
If one subtracts `10000` from each of these ports, you'll get a decimal ASCII character string: `102` for `f`, `114` for `r`.

As the writeup by vimvader suggests, you can solve this programmatically using a simple combination of `tshark` and `python`:

```bash
$ tshark -r spying.pcapng -Y 'ip.dst == 192.168.64.22' -T fields -e tcp.srcport | python -c 'import sys; print "".join(chr(int(port) - 10000) for port in sys.stdin.readlines())'
fl46: IJustMadeYouWatchMeSurfTheInternet
```

The flag is `IJustMadeYouWatchMeSurfTheInternet`.

## Other write-ups and resources

* <http://vimvaders.github.io/hackcon2015/2015/08/20/watch-me-surf-the-internet.html>
