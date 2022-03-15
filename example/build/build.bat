@echo off

IF %~1 = build (
  make clean
  make
  make iso
)
IF %~1 = run (
  make run
)