/*
Conditions - status DONE
*/

for (string sk in subtasks(key)) {

    //if found subtask that has not been closed, return false
    if (%sk%.status != "Done") {
        return false;
    }
}

//otherwise return true
return true;