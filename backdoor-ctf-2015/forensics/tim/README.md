# backdoor CTF 2015: [TIM](https://backdoor.sdslabs.co/challenges/TIM)

**Category:** Forensics
**Points:** 100
**Author:** [Abhay Bir Singh Rana](https://backdoor.sdslabs.co/users/nemo)
**Difficulty:** Easy
**Solves:** 116
**Description:** 

* <https://backdoor.sdslabs.co/challenges/TIM>

> Visit <https://github.com/backdoor-ctf/TIM> to get the flag.

## Write-up

We see in the github repo that there are [several commits](https://github.com/backdoor-ctf/TIM/commits/master), each having an ASCII character commit message of length 2 up until the last commit, which just says `Adds flag`.

After joining the commit messages to one, beginning at the oldest commit, we see a hint:

```bash
echo 4a6f696e2066697273742074776f2063686172616374657273206f66206561636820636f6d6d6974207368613120464c4147 | xxd -r -p
Join first two characters of each commit sha1 FLAG
```

We do exactly what the hint tells us to do and receive the flag:

```bash
$ git rev-list --all | grep -v '^00' | tail -r -n+33 | while read c; do echo -n ${c::2}; done
75[...]
```

Note that there is a padding to confuse people, which is indicated by commits beginning with `00`:

```bash
$ git rev-list --all 
d444f3227636477902c4badc8e35a27cadab456c
009d01e1b04bf2bf2d9bebd666e8d167fae1dc1a
006d89cdd1a4ea3620bc6d4f865a2e341f5ee79a
[...]
00d3be57b5291c68585e8eaadc8c159bbfe7d8e9
05928975ce6acd49c30a5314fa4019d73046ec84
676c0278c6602ca337e0666347eed1c62b1e5e27
[...]
75ae4979ffbb663dbc665495cf892e108114adcd
0068a486c186d9e38e51f87720a0dd65c3e8384d
[...]
0075376f5b95ab02608746da37cd7bfa54ccbc89
```

The flag is not printed here, since this is a long lived CTF.

## Other write-ups and resources

* <https://ctf-team.vulnhub.com/backdoor-ctf-2015-tim/>
* <http://linux.im/2015/04/03/backdoor-ctf-2015-writeup.html#tim--forensics100>
* [Indonesian](https://docs.google.com/document/d/1aAllg6gpMRFi0SMJv18rXbJLSI-yzro3UGABim1eNo4/edit)
