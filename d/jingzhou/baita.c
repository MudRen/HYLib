// Room: /d/jingzhou/baita.c
// congw
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
        ������һ������ߵİ���,�ഫ��ǰ��һλ״Ԫ�ɿ�ȡ������������ĸ��
�޽��ı�������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  
  "enter" : __DIR__"baita1",
  "south" : __DIR__"dongdajie1",
]));
	
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
