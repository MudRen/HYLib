// Room: /d/yanjing/to_yj.c

inherit ROOM;

void create()
{
	set("short", "�ྩ���");
	set("long", @LONG
������������ֱͨ[��]�Ķ���[�ྩ],�������Ǹ�����·��,�ֱ�ͨ
��Į���ɹź;���,���ϵĻ�ѩ��δ��ȫ�ܻ�,����Ѿ����ɱ���,����ȥ,
֨֨����.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/guanwai/road8",
  "northeast" : __DIR__"to_yj1",
]));
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}
