#!/bin/bash
(grep -rn 'DONE' | wc -l | sed 's/^/DONE: /' ) && (grep -rn 'TODO' | wc -l | sed 's/^/TODO: /')