// Room: /d/yandang/shanlu7.c

inherit ROOM;

void create()
{
	set("short", "�յ�̶");
	set("long", @LONG
����������,�͵����յ�̶,̶ˮ������ɭ,һ�ɺ����������,����
�ĺ�,ˮ��̶�е��ڲ���������,��Ϊ��̶,���絨֭.��������,ˮ��
������ӳ��,�ڸߴ���ȥ,�ɼ��ʺ���.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"shanlu5",
  "west" : __DIR__"shanlu8",
]));

	setup();
	replace_program(ROOM);
}
