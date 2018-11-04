// Room: /d/yanjing/room.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�߸ߵ��ݶ�,�ִ������,�ϱ�������ֱͨ�����Ⱦ���.����û����
���˱����ƶ�.ǽ���ϲ�����֦ţ�ͻ��,���ߺ�������,һ����ĺ���
�ӻ����ð����,�Ѹ�����ǽ��Ѭ����һ���.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kanshou.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"gardon2",
  "north" : __DIR__"tianjing1",
]));

	setup();
}

int valid_leave(object me,string dir)
{
	object npc;

	npc=present("kan shou",this_object());
	if(dir=="north" && objectp(npc) && living(npc))
	return notify_fail("���س���һ����ŭ���������ѵģ���ʲô��ɣ�\n");
	return ::valid_leave(me,dir);
}

