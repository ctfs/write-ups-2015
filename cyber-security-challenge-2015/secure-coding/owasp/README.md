# Cyber Security Challenge 2015: OWASP

**Category:** Secure Coding
**Points:** 20
**Description:**

> To protect against for example XSS, OWASP offers a great library which helps you implement input validation. Find the library and report what default regex is used to validate filenames that are given as input.

## Write-up

The solution lies in the ESAPI (The OWASP Enterprise Security API) Java repository: <https://github.com/ESAPI/esapi-java-legacy/blob/95d85be952ddb64e2a8997f6b862d6208d8ea9f2/configuration/esapi/ESAPI.properties>

```properties
Validator.FileName=^[a-zA-Z0-9!@#$%^&{}\\[\\]()_+\\-=,.~'` ]{1,255}$
```

## Other write-ups and resources

* none
