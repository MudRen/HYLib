// Room: /d/jindezheng/peifang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ӳ���,��ǰ��һ����ש���߷�,�ٽ�ȥ,�����������æ���� 
̥,���ǰ��������������ˮ,������,��,��,��......�ȵ���̥,Ȼ��ŷ� 
��שҤ���ճ���Ʒ. 
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/gongjiang.c" : 2,
]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"shulin2",
]));

	setup();
	replace_program(ROOM);
}
