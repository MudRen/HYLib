// Room: /d/huizhu/xiaoxi1.c

inherit ROOM;

void create()
{
	set("short", "СϪ��");
	set("long", @LONG
�ڲ�̽������ʯ֮�����ʵ�һ��СϪ�����峺�ĺӵ��ǹ⻬�Ķ�
��ʯ.Ϫ�����ߵ���ľ��ʼ����������Ϫˮת���ƹ�һ��ߵأ���Ȼ��
ǰһƬ���٣�ˮ����䲻����ƥ������������������齦�񣬶ٳ���ۡ�
LONG
	);

	set("no_clean_up", 0);
	set("outdoors", "huizhu");
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"xiaoxi",
  "westup" : __DIR__"xiaoxi2",
]));

	setup();
	replace_program(ROOM);
}
