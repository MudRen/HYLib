//jinling  dongjie1.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǽ����򶫱ߵ���Ҫ�ֵ�������ͨ�����������ֵĹ㳡������
��ͨ�����ţ��ֵ�������������һ�ɷ����ľ������������һ�Ҿ�¥��
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "east" : __DIR__"huaihe",
           "west" : __DIR__"zhongxin",
           "south" : __DIR__"jiulou",
            "north" : __DIR__"wuyigang",
]));
set("objects", ([
              __DIR__"npc/rascal" : 1,
			]) );

         set("outdoors", "jinling");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}