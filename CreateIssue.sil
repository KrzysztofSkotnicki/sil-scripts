// 

string issue_priority;//Possible values: "Major", "Critical" etc.
string[] custom_fields_mapping;
 
string k = createIssue(
            "TES", //klucz projektu
            "",
            "Task",
            "Summary of the sub task" ,
            issue_priority,
            "opis zgloszenia description",
            {},
            currentDate() + "30d",
            "",
            "",
            custom_fields_mapping
           );
lfDialogMessage("On the project " + project + ", issue " + k + " is created.", "INFO");