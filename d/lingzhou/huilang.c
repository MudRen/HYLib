//Cracked by Kafei
// Room: /d/xixia/huilang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������ǰ��ͺ󹬵Ļ��ȣ������������������ȶ��Ƿ�������
�ߣ��������Ű���ʯ�塣����ͨ����ƫ�������˸���������󹬡�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ysdian",
  "west" : __DIR__"xidian",
  "north" : __DIR__"huilang2",
  "east" : __DIR__"yushanfang",
]));
	set("objects", ([
		__DIR__"npc/shiwei" : 4,
	]));
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
