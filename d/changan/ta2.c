// Room: /u/wsl/changan/ta2.c
// This is a room made by Wsl.

inherit ROOM;

void create()
{
	set("short", "[1;37m������[2;37;0m");
	set("long", @LONG
���������꣬ʥɮ����Ϊ������Ҿ��飬���Ƹ����������ɴ���
�������ط�ʦ���������м��أ�Ħ�ҹ���һ�£�һ����Ⱥ����ˤ��
���ϣ�ɮ��Ϊ�㼴�������������������������
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"ca34",
]));

	setup();
	replace_program(ROOM);
}
