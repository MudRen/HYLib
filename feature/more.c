// more.c

#include <ansi.h>

void more(string cmd, string *text, int line)
{
	int i;

	switch(cmd) {
		case "b":
			line = line - 46;
			if(line<-22) return;
			for(i=line + 23; line < i;line++)
				write(text[line] + "\n");
			break;
		case "q":
			return;
		default:
			for(i=line + 23; line<sizeof(text) && line<i; line++)
				write(text[line] + "\n");
			if( line>=sizeof(text) ) return;
	}
  printf("[1;45m   [0;1m�Ѿ���ʾ[45m " HIY "%d%%"  
   " [1m   (ENTER ������һҳ��q �뿪��b ǰһҳ)[m",
   (line*100/sizeof(text)) );
	input_to("more", text, line);
}

void start_more(string msg)
{
	if (!stringp(msg)) return;
	more("", explode(msg, "\n"), 0);
}
