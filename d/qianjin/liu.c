inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����������ﲻʤ�ߡ�
����ϴ�������ۣ�����ҡŪ����֫����������ˡ�
���������������ŵ͡�
�߷����˴����������ѩů��ʱ�������������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"yue",
  "west" : __DIR__"xue",
]));
        set("objects", ([
        __DIR__"npc/liu" : 1,
                        ]) );

        set("coor/x",-110);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
