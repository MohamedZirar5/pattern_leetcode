# LeetCode Patterns Playground

LeetCode Patterns Playground is a compact DSA repo focused on original explanations, reusable patterns, and a lightweight local workflow for practice.

## What is here

- Five core pattern notes written from scratch: two pointers, sliding window, BFS, DFS, and binary search.
- Example Python solutions that show the shape of each pattern without copying problem statements.
- A small CLI that generates practice sets, tracks completions locally, and stores journal notes.
- Text-based visualizers for sorting and graph traversal so you can inspect how an algorithm moves step by step.

## Why this structure

The goal is to make the repo feel useful on GitHub, not just a folder of solved problems. Every note explains the decision process, the complexity tradeoff, and the edge cases that usually matter.

## Quick start

```bash
python -m pip install -e .
patterns-playground practice --count 3
```

## Pattern notes

## Practice journal

Use `patterns-playground journal add` to record mistakes, fixes, and the pattern you want to revisit. The CLI keeps the data in `~/.leetcode-patterns-playground/` so the history stays on your machine.
