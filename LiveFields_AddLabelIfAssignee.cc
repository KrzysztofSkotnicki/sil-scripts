string[][] map = {
	{
		"admini-vw", // user
		"admini-vw" // labels
	},
	{
		"admini-opel", // user
		"admini-opel" // labels
	}
};
for (string[] row in map) {
	if (assignee == row[0]) labels += row[1];
}