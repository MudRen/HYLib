//Cracked by Kafei
// Room: /d/xixia/square.c

inherit ROOM;

void create()
{
	set("short", "�ʹ��㳡");
	set("long", @LONG
�����ǻʹ���Ĺ㳡���м���һ����������ʯ��·��·��������
������������ʿ��ʮ��һ�ڣ��岽һ�ڣ������ֳֳ�ǹ��ꪣ��˵���
�ƷǷ������ĵľ����ɴ˿ɼ�һ�ߡ��ϱ��ǻʹ����ţ������������
�����ſ������ڴ�ͭ�ף���������ˮ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
"south"  : __DIR__"gongsquare",
  "north" : __DIR__"ysdian",
]));
	set("objects", ([
		__DIR__"npc/shiwei" : 4,
	]));
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
