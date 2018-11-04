// Room: /d/yanjing/street.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����Ĵ�ֵ�,����һ�ߵķ�ǽ,Ȧ���ϴ�һ��յ�,���²���һ�����,
�׵׺컨�����š��������ס��ĸ�����.�ǽ�����˷����Ʈ�����������
���²���һ����ǹ���Ҳ������֦������ꪡ�
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/munianci.c" : 1,
  __DIR__"npc/yangtiexin.c" : 1,
  __DIR__"biwu/mu" : 1,
]));
set("no_get",1);
set("no_drop",1);
	set("no_clean_up", 0);
	set("outdoors", "yanjing");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"street1",
  "south" : __DIR__"street2",
]));

	setup();
	replace_program(ROOM);
}
