// Room: /d/japan/jiedaos.c

inherit ROOM;

void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
�������ɵĽֵ�,���������ԭ��,�㵱Ȼ֪��,��ˮ����������˵��
ʲô����,���б�ÿӿ�����.�ֵ��Ķ�����һ��Ǯׯ,������һ�亣�ʹ�.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "japan");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jiedaos2",
  "south" : __DIR__"jiedao",
  "east" : __DIR__"qianzhuang",
  "west" : __DIR__"haixian",
]));
        set("objects", ([ /* sizeof() == 1 */
               __DIR__"npc/man" : 2,
            ]));
	setup();
	replace_program(ROOM);
}
