// Room: /d/changan/ca11.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��Ӫ");
	set("long", @LONG
�����ǳ����ؾ�פ���أ�һ�Թٱ����ڲ��������Է�����һЩ��
����ǹ����֮�������������øϽ��߿�����Ȼ����㰲�������ؽ�
���οɲ��Ǻ���ġ�
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ca9",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/weibing" : 4,
]));

	setup();
	replace_program(ROOM);
}
