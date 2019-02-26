# WASP Software Engineering and Cloud Computing

The purpose of this repository is to show that I'm able to master Versioning, Refactoring and Testing in Software Engineering.

## The Assignment & Software Engineering Tasks

### Choice of task

The DECIDE system is implemented according to this specification: http://www.monperrus.net/martin/decide.pdf since there is no own PhD project code available to demonstrate the Software Engineering skills.

### Assigned TA's GitHub

- Versioning & Testing:
@gluckyhang
- Refactoring:
@llbit

* [ ] Give the TAs access to the repository

### Versioning

Pass:
* [x] Setup own repository
* [ ] Maintain a streak of 10+ high-quality commits
* [x] Write a high quality README
* [ ] Perform a release
* [ ] Upload a link to the code repository to Canvas

Checks:
* [ ] Structured repository, appropriate folders
* [ ] Every commit is atomic bug fix, or feature with clear commit message (reflecting commit contents)
* [ ] Insturctions on compiling and executing the code with simple example

Pass with distinction:
* [ ] Commits clearly identified as feature, fix, documentantion, etc.
* [x] Documentation specifying: commit conventions and branch conventions

### Refactoring

Pass:
* [ ] Each refactoring as a single commit
* [ ] Reach at least 16 points
(rename method/variable/field, encapsule field, move method/field, extract magic constant, inline method)
* [ ] At least 2 complex refactorings
(replace conditional with polymorphism, replace inheritance with delegation, extract class/method, extract interface, pull up method)
* [ ] Use name scheme of the refactoring cataloques
* [ ] Submit list of commit identifiers for the refactoring commits

### Testing

Pass:
* [ ] One test case for each function of the code (intention, test inputs and oracle for function)
* [ ] Document intention of each use
* [ ] Document rational of test oracles
* [ ] Automate test execution (setup existing framework or custom scripts)

Checks:
* [ ] At least one corresponding test case per function
* [ ] Test inputs and oracles correspond to intention
* [ ] Test automation scripts or framework

Pass with distinction:
* [ ] Multiple test cases for each function for various usage cenarios (nominal/exceptional cases)
* [ ] Report of relevance of test cases (appropriate for basic requriements or different execution scenario)

## Used Commit & Branch Conventions

Commit conventions are based on [the Angular conventions](https://github.com/angular/angular/blob/22b96b9/CONTRIBUTING.md#-commit-message-guidelines).
Each commit message consists of a header, a body and a footer. The header has a special format that includes a type, a scope and a subject:

```
<type>(<scope>): <subject>
<BLANK LINE>
<body>
<BLANK LINE>
<footer>
```

- Type: "feat:", "fix:", "doc:", "refactor:", "test:", ...
- Scope: Optional
- Subject: Short description
- Body: Motivation for change and contrast to previous code
- Footer: Reference issues that this closes, ...

Branch conventions are based on a Discussion on [Stackoverflow](https://stackoverflow.com/questions/273695/what-are-some-examples-of-commonly-used-practices-for-naming-git-branches) and Vincent Driessens Git branching model illustrated in [this picture](https://i.stack.imgur.com/tjJCt.png).
The naming of a branch follows

```
<grouping token>/<lead token>
```

- Grouping tokens: develop, feature, release branch, hotfixes, master
- Lead token: < feature name >, < bug name >, issue < name > < number > , ...

## Code Description and Execution

### DECIDE()

- How the Decide system works
- How to compile the code
- How to execute the code (on simple example)

