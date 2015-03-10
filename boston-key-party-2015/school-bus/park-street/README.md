# Boston Key Party CTF 2015: Park Street

**Category:** School-Bus
**Points:** 10
**Solves:** 356
**Description:**

> What is the OpenFlow table modification message type to add a new flow? : 10

## Write-up

Reading the [official specification](https://www.opennetworking.org/images/stories/downloads/sdn-resources/onf-specifications/openflow/openflow-spec-v1.0.0.pdf) and searching for `modification`, we see in section `4.6 Flow Table Modification Messages` the `OFPFC_ADD` type for adding a New flow.

## Other write-ups and resources

* <https://github.com/bl4de/ctf/blob/master/BostonKeyPartyCTF_2015/parkstreet.txt>
* [Indonesian](http://blog.rentjong.net/2015/03/boston-key-party-2015-park-street.html)