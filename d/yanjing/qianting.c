// Room: /d/yanjing/qianting.c

inherit ROOM;

void create()
{
	set("short", "ǰ��");
	set("long", @LONG
����ʯ�ĵ�������һ����Ⱦ,��յ�߽����������Ʒ���,��ľ���Ӽ���
յ������ҡƵ��,�����ͻ���ɽͼ��������.һ����������������Ƿ�����
�Ѱ�����,���߸����Ů����.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wanyankang.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"qianyuan",
  "west" : __DIR__"huilang",
  "north" : __DIR__"zhongyuan",
]));

	setup();
	replace_program(ROOM);
}
