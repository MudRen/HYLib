//Cracked by Kafei
// Room: /d/xixia/hut.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����ǰ��һ��С�ݡ�С�������������ƣ�һ��С�Ž������ţ���Ϊ
�����������ֻ�Ȼһɫ������ϸ������ѷ�����������涣���Ҷɳɳ��
�����һ����һ������ֱ͸������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"zhulin",
  "enter" : __DIR__"hut2",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
