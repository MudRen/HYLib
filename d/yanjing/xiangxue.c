// Room: /d/yanjing/xiangxue.c

inherit ROOM;

void create()
{
	set("short", "��ѩ��");
	set("long", @LONG
��ѩ���ڵ���Իͣ�����һ����ϯ.�������������պ���������
��������.���Է���һ��̫ʦ��,����һ�ź���ձ̺,�������˸�����
������ɫ�����,�Ա߼�������Сͯ�ź���.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wangye.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zhongyuan",
]));

	setup();
	replace_program(ROOM);
}
