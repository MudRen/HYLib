//xshiwu.c Сʯ��
#include <room.h>
inherit ROOM;
void create()
{
         set("short","Сʯ��");
	 set("long",@LONG
����һ��Сʯ�ݣ���Χ���ô�ʯ���������ġ����Ϻ������ż��Ų�ϯ��ǽ
�Ƿ���һ�����ӣ�����ȥ���ò��������Ϸ��ż�ֻ���롣
LONG
);
         set("sleep_room",1);
	 set("no_fight",1); 
	 set("exits",([
               "east": __DIR__"shanding",
         ]));
         
         setup();
	 replace_program(ROOM);
}
