// Room: /d/sandboy/to_sandboy2.c

inherit ROOM;

void create()
{
	set("short", "��·��");
	set("long", @LONG
�˵���Ϊ�����˶�,�γ���һ����ʮ�ɷ�Բ�ĵ���.������Ƭ������,
ͨ�����ֿ���ֱ�ӵ����䵱ɽ,�������ǽ��ꡣ
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"to_sandboy",
  "south" : __DIR__"trees2",
 // "east" : "/d/suzhou/road4",
"west" : "/d/zhongzhou/dongmeng", 
]));
	set("outdoors", "/d/sandboy");

	setup();
	replace_program(ROOM);
}
