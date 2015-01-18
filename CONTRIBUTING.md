# Contribution guide

Please take a moment to review this document in order to make the contribution process easy and effective for everyone involved.

## Adding a new write-up entry

1. Each CTF gets its own folder in the root of this repository. For example, ‘Foo Bar CTF 2015’ would get a folder named `foo-bar-ctf-2015`.
2. Every CTF challenge gets its own subfolder within that folder. For example, all files related to the ‘Foo Bar CTF 2015’ challenge named ‘Sucky sandbox’ would be located in `foo-bar-ctf-2015/sucky-sandbox`.
3. Every CTF challenge folder needs a Markdown-formatted `README.md` file, e.g. `foo-bar-ctf-2015/sucky-sandbox/README.md`. This file contains any details about the challenge, the main write-up itself, and links to other write-ups and resources. The folder should also contain the source files needed to reproduce the challenge.
4. Once you’re done adding the entry or making your changes, whilst following  submit a pull request using the GitHub web interface.
5. Finally, make sure you follow our committing rules

## Changing an existing entry

1. Feel free to make any changes you see fit. Add a link to a write-up on your blog, add missing source files, clarify explanations in the write-up, or — if you’ve found a better way to solve a challenge — simplify the existing solution.
2. Once you’re done, submit a pull request using the GitHub web interface.

## Committing rules
These rules exist to keep the repo maintainable and complete. Please consider following them.

1. Update the root `big-ctf/README.md` file, when adding a writeup to `big-ctf/task/`:
	* If you add a writeup in the `Write-up` section of the `big-ctf/task/README.md` file, then move the task link from `Repo: Incomplete` to `Repo: Completed`
	* If there already exists a writeup in the `Write-up` section, add another `Alternative write-up` section above the `Other write-ups and resources` section
	* If you add a writeup *link* in the `Other write-ups and resources` section, please remove the task link in the `Links: Missing` section
2. Do not add files that have a filesize bigger than 15MB to keep the repo relatively small. Upload the file instead to a service or reference it from somewhere else.
3. Consider following these [committing rules](https://atom.io/docs/latest/contributing#git-commit-messages). For this repo, we like to use these [emojis](http://www.emoji-cheat-sheet.com/):
	* :memo: when adding a writeup to the `Write-up` section of a task
	* :floppy_disk: when adding resources for a task, e.g. files or scripts
	* :link: when adding a writeup link to the `Other write-ups and resources` section of a task
	* :pill: when fixing broken links or corrupt Markup stuff
	* :books: when updating the structure of this repo or adding a ctf skeleton structure
