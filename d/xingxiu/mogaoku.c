// /d/xingxiu/mogaoku.c
// Jay 3/17/96

inherit ROOM;

// can put some book about budism here.

void create()
{
        set("short", "Ī�߿�");
        set("long", @LONG
����ǽ���ϻ�����������صĻ��棬����Ů���죬���з������á�����
���кܶ����;��顣�㱻��Щ�������Ļ�֮�������ˡ�
LONG );
        set("exits", ([ 
             "north" : __DIR__"yueerquan",
        ]));
         set("objects", ([
                "/d/shaolin/obj/fojing11" : 1,
                "/d/shaolin/obj/fojing20" : 1,
                "/d/shaolin/obj/fojing21" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

