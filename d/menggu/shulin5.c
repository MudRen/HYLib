// Room: /d/menggu/shulin5.c

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
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"caoyuan1",
  "south" : __DIR__"shulin2",
]));
	set("outdoors", "menggu");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
