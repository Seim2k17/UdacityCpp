#!/bin/bash
(grep -rn 'DONE' | wc -l | sed 's/^/DONE: /' ) && (grep -rn 'STUDENT' | wc -l | sed 's/^/TODO: /')