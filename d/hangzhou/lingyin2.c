//Cracked by Kafei
// ������֮���۱���
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "���۱���");
    set("long", @LONG
������������һ���ߴ���ʮ���׵Ĵ�����д�š����۱����
��ǰ�������˽ǾŲ�ʯ���������ֽ��������
LONG);

   set("exits", ([ /* sizeof() == 2 */ 
                  "enter" : __DIR__"lingyin3", 
		  "south": __DIR__"lingyin1",
                ])
      );
	set("cost", 0);
    setup();
    replace_program(ROOM);
}