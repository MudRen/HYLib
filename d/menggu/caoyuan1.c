// Room: /d/menggu/caoyuan1.c

inherit ROOM;

void create()
{
	set("short", "�ɹŲ�ԭ");
	set("long", @LONG
Զ���̳���,һ�Ӷ��ɹ������ж���������.����Ϧ����Ѫ,��Բ��
�������������Ӫ�ʺ�ţ��,�Ǿ�����ľ��Ĳ���.��������ֱ߼���С��
������ˣ,���ֺ���������ɽ.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tujiu.c" : 2,
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shulin",
  "south" : __DIR__"shulin5",
]));
	set("outdoors", "menggu");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
