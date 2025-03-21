#include <stdio.h>
#include "SWS/SWS.H"

int main() {
	char *text = SKIP_WHITE_SPACE("{\"userId\": 1,\"id\": 1,\"title\": \"delectus aut autem\",\"completed\": false}");

	printf("%s", text);

}