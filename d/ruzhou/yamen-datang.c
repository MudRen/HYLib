// Room: /d/ruzhou/yamen-datang.c
// llm 1999/07/04

inherit ROOM;

void create()
{
	set("short", "֪������");
	set("long", @LONG
����һ�����������Ĵ��ң��Ǹ��ص����űر��ļҵ������õĵ��ϲ��ó���ȴ
��Լ�ܿ���һ����Ѫ�ۣ������Ǵ�������ʱ���µĺۼ������߸���һЩ�ྲ����
�ܵ����ӣ�����Щ������ŭ�ĸо���
LONG
	);
	set("exits", ([
	   "south" : __DIR__"yamen-damen",
	]));
	set("objects", ([
		__DIR__"npc/jiang-yaoting":1,
      __DIR__"npc/yayi":4,
	]));

	setup();
	replace_program(ROOM);
}

