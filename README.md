# LCSAssignment-2_part-2
Logic in Computer Science Assignment 2-Part-2 along with  Documentation

Project Status-Completed

Collaborators-AjithKanduri,VamsiAdapa.

Documentation of the Project can be viewed in html pages by opening index.html file in Documentation folder in repository's root.

  Project Description:
    Note: This project is done in C++ programming language
    Aim:
    To create a tool for verifying whether a certain proof of a given sequent is valid or not, for a certain set of proof         rules
    These proof rules are listed below
    1.Premise
    2.AND Introduction/Elimination
    3.OR Introduction
    4.IMPLIES Elimination
    5.Modus Tollens(MT)

  Assumptions Made:
    1.Each propositional formula should begin and end with parenthesis
    examples:
      (i) (a^b) is valid
      (ii) a^b is invali
      (iii) ((a^b)^(c^d)) is valid
      (iv) (a^b)^(c^d) is invalid

    2.In case of negation or multiple negations to a literal/formula, each negation is enclosed within set of parenthesis.
     examples:
      (i) ~p is invalid
      (ii) (~p) is valid
      (iii) (~(~p)) is valid
      (iv) (~~p) is invalid

  Procedure:
     1.Each line of proof of the given sequent is sorted into propositional formula, proof rule and line numbers of proof         used to prove the propositional formula.
     2.We then validate propositional formula by passing it to it's proof rule's method.
     3.Step-2 is repeated for all the lines of proof.
     4.If all lines are valid than the proof is considered valid.

  Observations:
    The Given Observation were recorded on a Ubuntu 18.04.1 environment and compiled using g++ compiler, C++14 standard
    The execution time might vary from system to system

