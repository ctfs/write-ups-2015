# Cipherception 

**Category:** Crypto
**Points:** 35
**Author:** 
**Description:**

>OCBnbCB0bCAxMCBmZGFuIHlkIGxkIFlndiBydnogYmQgcG1qcHpkX2Z4Y3liY3R2X2FibGxiY2w=

>5Affine2 > 8Caesar > Atbash > B64

## Writeup

To begin solving the problem one must recognize that all the plain-text words given within the problems are simple encryption methods. With this in mind, and the obvious direction of the arrow, one can backtrack the ciphers to gain the plain-text.

>B64 > Atbash > 8Caesar > 5Affine2


```
Base64: 8 gl tl 10 fdan yd ld Ygv rvz bd pmjpzd_fxcybctv_abllbcl
```

Once the Atbash had been obtain, the chain of decryption is kept going:
```
Atbash: 8 to go 10 uwzm bw ow Bte iea yw knqkaw_ucxbyxge_zyooyxo
```

Atbash to Caesar with shift of 8:
```
8Caesar: 8 lg yg 10 more to go Tlw aws qo cficso_muptqpyw_rqggqpg
```

Affine with A coefficient of 5, B coefficient of 2. User had to remove all unnecessary plaintexts before running throgh Affine.

```
Caesar: Tlw aws qo cficso_muptqpyw_rqggqpg
Affine: The key is always_continue_digging
```

The key has now been successfully extracted.

## Flag
>always_continue_digging

## Other write-ups and resources
