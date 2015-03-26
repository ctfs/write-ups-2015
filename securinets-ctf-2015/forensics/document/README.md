# Securinets Quals CTF 2015: Document

**Category:** Forensics
**Points:** 150
**Solves:** TODO
**Description:** 

> Hint : no hint (aucun hint)
>
> url : [http://41.231.22.133:8080/1/doc_forensics.docx](doc_forensics.docx)
> 

## Write-up

We are given with file, which we can discover with Unix "file" command, happens to be RAR archive. Firstly we unrar it. We get a folder with 3 folders and 1 file inside. Folders: word, docProps, customXml. File: [Content_Types].xml. Word folder gives us a clue that it might be a word document, which is basically a zipped archive of mentioned folders and that file above. Thus, we zip-archive the folder and give it .docx extension. After that we can open the file, for example, in Google Drive (https://docs.google.com/document/d/1aV4tQvcVd6BULTrHQpE-JiJG57KAFG9NVku7K2oReZI)  and get the flag. 
 Flag= D3_R13N_ChA113Ng3R_

## Other write-ups and resources

* none yet
