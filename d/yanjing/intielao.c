// Room: /d/yanjing/intielao.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ӷֳ�ǰ��������,��һ��������������ɵ�դ������,������
���޵Ĵ�����һ��.�����ڿ�դ���ĵط�������ľ��,���������ִ�ˮ��.
ǽ��һ�Ѹɵ���,����˯���ĵط�.
LONG
	);
//	set("objects", ([ /* sizeof() == 1 */
//  __DIR__"npc/clone/clothyoudeng.c" : 1,
//]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"tianjing1",
]));

	setup();
	replace_program(ROOM);
}
