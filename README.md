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

* [x] Give the TAs access to the  repository
-> public repo

### Versioning

Pass:
* [x] Setup own repository
* [x] Maintain a streak of 10+ high-quality commits
* [x] Write a high quality README
* [ ] Perform a release
* [ ] Upload a link to the code repository to Canvas

Checks:
* [x] Structured repository, appropriate folders
* [x] Every commit is atomic bug fix, or feature with clear commit message (reflecting commit contents)
* [x] Insturctions on compiling and executing the code with simple example

Pass with distinction:
* [x] Commits clearly identified as feature, fix, documentantion, etc.
* [x] Documentation specifying: commit conventions and branch conventions

### Refactoring

Pass:
* [x] Each refactoring as a single commit
* [x] Reach at least 16 points
(rename method/variable/field, encapsule field, move method/field, extract magic constant, inline method)
* [ ] At least 2 complex refactorings
(replace conditional with polymorphism, replace inheritance with delegation, extract class/method, extract interface, pull up method)
* [x] Use name scheme of the refactoring cataloques
* [ ] Submit list of commit identifiers for the refactoring commits

### Testing

Pass:
* [x] One test case for each function of the code (intention, test inputs and oracle for function)
* [x] Document intention of each use (comments)
* [x] Document rational of test oracles (comments)
* [x] Automate test execution (setup existing framework or custom scripts)

Checks:
* [x] At least one corresponding test case per function
* [x] Test inputs and oracles correspond to intention
* [x] Test automation scripts or framework

Pass with distinction:
* [x] Multiple test cases for each function for various usage scenarios (nominal/exceptional cases)
* [X] Report of relevance of test cases (appropriate for basic requriements or different execution scenario)

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

## Code Description, Execution, Examples and Testing



The calculations are described in doc/decide.pdf and you can look into the original document the task is based on by looking in doc/nver-tse.pdf .

### Compiling

You can compile decide.c with

```
make decide.o
```

### Example 1

You can execute the example by typing first

```
make example1_decide
```

and then executing

```
./example1_decide
```

This let's you compare the calculations of CMV, PUM, FUV of example 1 described in decide.pdf with the results of the program.
(They are identical)

### Example 2

If you want to experiment on an easy example do the following

```
make example2_decide
./example2_decide
```

By changing a parameter from 1 (in example1_decide.c) to 0.1 (in example2_decide)

```
PARAMETERS.AREA1=0.1;
```

the Launch Interceptor Condition 3 is set to true, which ultimately results in a launch.

The difference of consecutive points (POINTS.X, POINTS.Y) is between 0 and sqrt(2). By changing to a value LENGTH1 over sqrt(2). This Launch Interceptor Condition 1 (LIC_1) can be made false, resulting in an abort of launch.
-> Try it! Feel free to experiment!

### Testing

You can run the unit tests by typing

```
make testing_decide
./testing_decide
```

The intention, the test inputs and the reational of the oracle for function are documented in the appropriate section of the code as comments in testing_decide.c .
The unit tests are nominal cases and cover basic requirements.

The code in Example 1 (and interactive in Example 2) can be interpreted as middle to big test case since the result was analytically derived in decide.pdf . Those can be seen as specific execution scenarios depending on the chosen input PARAMETERS.
