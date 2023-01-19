# Tabs' Pandoc Setup

* *Makefile.inc*: this includes most of the logic
* *scripts/pandoc_settings.yml*: This sets various bits of pandoc settings.
* *StoryTitle*: Whatever you want to call it. As many as you want.
* *StoryTitle/Makefile*: Includes `Makefile.inc`, and sets the story title.
* *StoryTitle/Chapters*: Each chapter is an individual file here. There is a
  yaml frontmatter which sets additional settings and info for the individual
  story. Frontmatter should only be necessary on the first chapter.

# Makefile

* `make precheck`: Checks if pandoc and pdflatex are installed.
* `make pdf`: Generates a single pdf of the entire story.
* `make html`: Generates a single HTML document of the entire story.
* `make latex`: Generates a single latex document of the entire story.
* `make epub`: Generates a single epub document of the entire story.
* `make ao3`: Generates each chapter as a HTML document for ao3.
* `make clean`: Cleans up anything created into the `out` output folder.
* `make open_pdf`: Opens the PDF in your system PDF viewer.
* `make html`: Opens the HTML in your default browser.
* `make wordcount`: Gives you a wordcount for all chapters individually and
  combined.
* `make todo`: Finds any location of TODO.
