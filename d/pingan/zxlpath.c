// Room: /city/zxlpath.c
// YZC 1995/12/04 

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "����¥����");
	set("long", @LONG
��������¥���ã������������˿ͺ�����С�������������������
�̶��ĺ����������������������������������ַǷ����������������
ǰ�����Ž��ĸ��ո����֣�����ʳ��
    ������õ���������ϵ���ĵ����������ܽ������
LONG);
	set("exits", ([
		"east"   : __DIR__"meigui",
		"north"  : __DIR__"furong",
		"south"  : __DIR__"mudan",
		"down"   : __DIR__"zuixianlou",
	]));
        set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

