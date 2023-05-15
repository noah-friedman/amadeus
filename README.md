# The A.M.a.D.E.U.S. (*A*ppropriately *M*enial *a*nd *D*eployable *E*asily *U*nderstandable *S*ample) Project [![CI/CD](https://github.com/noah-friedman/amadeus/actions/workflows/CICD.yml/badge.svg)](https://github.com/noah-friedman/amadeus/actions/workflows/CICD.yml)

Often times I find myself in need of a simple example project to use to test some other external system.
I'm bored of re-writing that project, so I'm just going to put it in a GH repo now.


This project uses CMake in order to provide a two-step build process for slightly more complexity (and thus, testable behaviour).
The actual program is a simple number guessing game. A docker image is built on each commit (after first testing that the project
will build), and is built as a multi-platform image to avoid any errors on `arm64` systems. This makes the integration of the
A.M.a.D.E.U.S. Project into any pipeline/CI-CD environment simple.

The A.M.a.D.E.U.S. Project is programmed using the C language to avoid having to install many external build dependencies 
(almost all modern systems provide a C compiler out of the box, and CMake installation is trivial). No code libraries
are required to build this project. Please [open a ticket on GitHub](https://github.com/noah-friedman/amadeus/issues/new/choose)
if you find any bugs.

<br />

---
© Noah Friedman 2023
