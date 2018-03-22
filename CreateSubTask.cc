if(!isNull(parent)) {
    description = parent.description;
    reporter = %parent%.reporter;
}

string[][] SUMMARIES = {
    {
       "Tytul",     // tytuł
        "Descriptions",  // opis
        "login_usera_na_ktorego_przypisze"     // przypisany user
    }
};
string[] subtasks = subtasks(key);

for(string[] summ in SUMMARIES) {
    boolean exists = false;
    
    for(string subtask in subtasks) {
        if(%subtask%.summary == summ) {
            autotransition("Reopen Issue", subtask);
            exists = true;
        }      
    }
    if(!exists) {
        createIssue(
            project, //projekt
            key,  //klucz
            "Sub-task",  //issuetype
            summ[0],  //summary
            "", //priority
            description, //description
            {}, //components
            "", //due date
            "", //estimate
            summ[2], //security level
            "assignee|" + summ[2] + "|reporter|" + reporter
            );
    }
}