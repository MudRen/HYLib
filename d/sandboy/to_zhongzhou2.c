// Room: /d/sandboy/to_zhongzhou2.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
·�濪ʼ��ò���ôƽ��,�ӿ����ݵ�,���ߵ�ũ���Ϊ�������
����,Ũ�ܵ�������ס���˵���Ұ,ֻ�ܸо�����������.
LONG
	);
set("outdoors","/d/jiangnan");
	set("exits", ([ /* sizeof() == 3 */
//  "east" : "/d/robber/road5",
  "west" : __DIR__"to_zhongzhou",
  "north" : __DIR__"shulin",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
