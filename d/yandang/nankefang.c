// Room: /d/yandang/nankefang.c

inherit ROOM;

void create()
{
	set("short", "�пͷ�");
	set("long", @LONG
�������п͵ķ���,���ڿ�ջС,ֻ����һ��󷿼�,����һ����ͨ
��,��˯ʮ������ӵ�,���ȥ��ʱ�����м����������������ϵر���
����,�������Ҳû����.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"yuanluo",
]));
	set("no_magic", 1);
	set("no_fight", 1);
	set("sleep_equipment", "ͨ��");
	set("hotel",1);
	set("sleep_room", 1);

	setup();
	replace_program(ROOM);
}
