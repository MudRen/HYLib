// myhome
// by steel 
#include "ansi.h"
inherit ROOM;

void create()
{
	set("short", "��Ȼ��");
	set("long", @LONG
        ����һ���С�ķ���,����ļҾ߶��ô�ľ�Ƴ�,ȴ�Եô����쳣��
������һ�������ˣ������������һ�ſ��������ϣ���ǰ����һ�����
¯�����г���һ�����̵ľƱ������ϴ��������ں���Ц�⡣
LONG
	);
      //set("no_fight",1);
      set("exits", ([
		"west" : __DIR__"iceroad5",
			]));
      set("objects",([
          __DIR__"npc/me":1,
    ]) ); 
	setup();
	replace_program(ROOM);
}

