// Room: /d/menggu/chulan.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������ķֳɼ���,�ֱ�Ȧ�˼�ͷţ��,һ�ߵ�ľ׮��,��ϵ����ƥ��,
Ȧ���в�ʱ����ţ��Ľ���,�����˻.һ���Ǽ�����õ�Сé����.
�ſ�,�����ж���ɨ�úܸɾ�.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"byriver",
]));
	set("outdoors", "menggu");

	setup();
	replace_program(ROOM);
}
