inherit ROOM;

void create()
{
        set("short", "�˳�");
        set("long", @LONG
�������������Ĳ˳�������ʪʪ�ĳ���û�иɵ�ʱ����
��С����������ȥ���뾡�������˻ؼҡ������������̯�Ķ�
Ҫ����������Ķ�Խ������ѡ�
LONG);
	set("outdoors", "zhongzhou");

        set("exits", ([                 
                "south" : __DIR__"eba",
                "west" : __DIR__"wendingnan1",
        ]));
        set("objects", ([
                __DIR__"npc/caifan" : 1,
                "/d/city/npc/liumangtou" : 1,
        ]));

        set("coor/x", -220);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
