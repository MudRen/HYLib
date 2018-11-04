// Room: /d/hainan/outtree.c

inherit ROOM;

void create()
{
	set("short", "�һ�����");
	set("long", @LONG
��ǰ��һƬ�һ���,��ɫ�Ļ���ʹ��̵���Ҷʹ�˸�������,�߲���
��Ƥ,�������֦,�޲���ʾ����Ƭ���ӵ����,���ֱߵ��Ҳݴ���,�㷢��
һ��츯���˵�ľ��.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("item_desc", ([ /* sizeof() == 1 */
  "ľ��" : "���丯�ó̶�����,�Ѿ�������þ���,������ϡ�ܿ�����ָ������
�ļ�����'����ֹ��,��ֹ����',����һ��,����'л���ι�',ָ���۾�,��
Ȼ��ǰ������ıʷ���ͬ.
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"dtotree",
  "north" : __DIR__"taotree1",
]));

	setup();
	replace_program(ROOM);
}
