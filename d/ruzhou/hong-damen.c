//Room: /d/ruzhou/hong-damen.c
// by llm 99/06/12

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����ׯ����");
   set("long",
"��ǰ��һ��������ΰ�Ĵ�ׯͥ�����ȸߴ���ǽ���ߣ�����Щ��ʹ�\n"
"���Ƶ�ζ����ֻ�Ǵ����������Ĳ������롢ʨ�ޣ�����Ц���е�ϲ��ͯ��\n"
"ͯŮ�����Ҵ��ų���������������룬��������һ��޴����ľ����\n"
HIR"            ��    ��    ׯ\n"NOR
"\n");
	set("exits", ([
		"west" : __DIR__"ruzhou",
                "east" : __DIR__"hong-zoulang",
   ]) );


   set("objects", ([
//   	__DIR__"npc/meipo" : 1,
      ]) );
   setup();
   replace_program(ROOM);
}

