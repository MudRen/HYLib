// Room: /d/yandang/luoyan25.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
�����ֳ���,������ǰ����һ������,��ˮ����,ˮ������,��������
���,��ˮ����Ӱ����,�ر���֦��б,���㸡��,������������,�Ծ�ɫ��
��,�˼�����,��������.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"luoyan26",
  "south" : __DIR__"luoyan24",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
