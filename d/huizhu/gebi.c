// Room: /d/huizhu/gebi.c

inherit ROOM;

void create()
{
	set("short", "���ɳĮ");
	set("long", @LONG
���ȵ�����ɹ��ãã�ĸ�ڣ����֮��ֻʣ�»�ɫ��ɳ���������
��ɳ��һ���������ߡ�ǰ�治Զ��ɳ����΢΢����������ɳĮ�е���
�ݣ��ͺ�����������߳���ƬɳĮ�ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "huizhu");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"xianei",
  "west" : __DIR__"gebi1",
]));

	setup();
	replace_program(ROOM);
}
