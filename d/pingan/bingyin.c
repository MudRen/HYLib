// Room: /city/bingyin.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Ӫ");
	set("long", @LONG
�����Ǳ�Ӫ���������鵽�����ǹٱ����е����佫��ָ�����жӲ�����
�еĶ������������е����š�����������Ϣ����ǽ��������˧��������ɫ
��Ѱ�������ܡ���˵�������ë����û�������м�����Ѳ��.
LONG );
	set("item_desc", ([
		"men" : "����һ�ȼ�������š�\n",
	]));
	set("exits", ([
		"east" : __DIR__"bei1",
	]));
	set("objects", ([
		__DIR__"npc/wujian" : 1,
		__DIR__"npc/bing" : 3,
	]));
        set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
//	set("no_clean_up", 0);
	setup();
}
