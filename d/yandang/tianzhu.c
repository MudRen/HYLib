// Room: /d/yandang/tianzhu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������266��,ɫ����Բ,��������,���ư���.�山���Ħ��'����
ǧ��'��'�첻��,���������',������������ؿ̻����˷�Ķ���,�Ӵ�
����,�͵�������.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 3 */
  "northdown" : __DIR__"shimeng",
  "south" : __DIR__"tieqiao4",
  "westdown" : __DIR__"wulonggu",
]));

	setup();
	replace_program(ROOM);
}
