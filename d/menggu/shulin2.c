// Room: /d/menggu/shulin2.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��Į����Ƭ�ຮ��������,��Ƭ����������ɳĮ�е����ݰ����˾�ϲ.
���Ӳ���,��ľҲ�Ƚϰ�С,���ط��Ĺ�ľ�԰�·��ȫ��ס��,���ϲ���
�ļ�ƬҶ���ڷ�������Ʈ��.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shulin5",
  "south" : __DIR__"shulin1",
]));

	setup();
	replace_program(ROOM);
}
