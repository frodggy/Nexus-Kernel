@echo off

IF %~1 = build (
  make clean
  make
)
IF %~1 = run (
  make run
)