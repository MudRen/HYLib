// Room: /d/menggu/qinwei2.c

inherit ROOM;

void create()
{
	set("short", "������Ӫ��");
	set("long", @LONG
��������������,����Ϊ�ɹ����е�Ӣ��,����ʱ��ͬ��ľ��һ��׷ɱ
���,����Ӫ����ֻ�Ǽ���ձ�����ѷ�,һ�˳�ǹ,һ����̥��,��Ӿź�
����,������������ͨ,�������֮��,���˿ɼ�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/boerhu.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road3",
]));

	setup();
	replace_program(ROOM);
}
