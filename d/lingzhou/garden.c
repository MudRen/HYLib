//Cracked by Kafei
// Room: /d/xixia/garden.c

inherit ROOM;

void create()
{
	set("short", "����԰");
	set("long", @LONG
���ǻʹ��������԰�����Ž��أ��ٲ�Ʈ�㣬�䲻�Ƚ���ˮ�����
����ȴҲ����һ���ζ��������ռ԰��һ������Ĵ��ĺ�����������С
·ͨ��һƬ�����֡�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"huilang2",
  "west" : __DIR__"zhulin",
  "east" : __DIR__"piandian",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
