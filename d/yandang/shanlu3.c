// Room: /d/yandang/shanlu3.c

inherit ROOM;

void create()
{
	set("short", "˫���");
	set("long", @LONG
���������,����εض���,��Լ�߰�ʮ��,�γ�Բ����,��˫��
��,�����'����ǧ����һѿ'��˫���.��ҹĻ����ʱ,Զ��������ɮ��
��,���ƾ���,һʱȴ��������.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"shanlu4",
  "southdown" : __DIR__"shanlu2",
]));
	set("outdoors", "/d/yandang");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
