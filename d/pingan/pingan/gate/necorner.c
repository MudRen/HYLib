inherit ROOM;
void create()
{
	object con,item;
        set("short", "������¥");
        set("long", @LONG
��¥�Ϲ���һ��ͭ�ӣ�ÿ���н���������س������Ǿ�����Ϊ���������ٱ�����
�˽���������¥���м���һ���޴����¯������װ�����Ƿ࣬�Ա�������������¥
�ﻹ��װ��һ�Ż��ڣ�ǽ���ﻹ����һЩ�����衣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ewall2",
  "west"  : __DIR__"nwall10", 
]));
        set("objects", ([
        __DIR__"npc/wall_solider" : 3,
        __DIR__"obj/corner" : 1,
                        ]) );

        set("outdoors", "fengyun");
        set("coor/x",60);
	set("coor/y",60);
	set("coor/z",30);
	set("coor/x",60);
	set("coor/y",60);
	set("coor/z",30);
	setup();
        con = present("corner",this_object());
        item = present("bomb",this_object());
        if( con && item)
        item->move(con);


}
