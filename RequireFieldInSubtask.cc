string [] subtasks = subtasks(key);
boolean hasField = false;
string errorMsg = "You must have a value for the Fruit field in a subtask entered before this issue can be completed.";

for(string st in subtasks) {
    if(isNotNull(%st%.fruit)) {
        hasField = true;
    }
}

if(hasField == false) {
   return false, "error", errorMsg;
}