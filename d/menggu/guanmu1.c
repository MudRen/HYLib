// Room: /d/menggu/guanmu1.c

inherit ROOM;

void create()
{
	set("short", "��ľ��");
	set("long", @LONG
�����߶�ʱ�ӹ�������é��,����Ǹ߸߰����Ĺ�ľ��.��в�����
Ŀ��,Ҳ��������ıߵľ�ɫ,ֻ��һ��С·�ڹ�ľ����ʱ��ʱ�ֵ���
��С�����ɽ��.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"caoyuan",
  "southwest" : __DIR__"guanmu",
]));
	set("outdoors", "menggu");

	setup();
	replace_program(ROOM);
}
