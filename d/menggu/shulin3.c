// Room: /d/menggu/shulin3.c

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
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"shulin1",
]));
	set("outdoors", "menggu");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
