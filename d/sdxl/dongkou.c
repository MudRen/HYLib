// Room: /u/poq/sdxl/dongkou.c ����
// by poq@jyqx 97/7
// alter dubei
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    set("short", BLU "����"NOR);
    set("long", @LONG
���³�����ϥ��һƬ�ž�������ǰ��һ����ɽ�������Ϸ����İ���
��ȡ�
LONG
    );

    set("exits", ([
        "southeast" : __DIR__"xiaolu3",
        "enter" : __DIR__"shandong",
    ]));

    set("outdoors", "xiangyang");

    set("item_desc", ([
        "dong" : "ɽ�����������ģ��㿴�����κζ�����\n",
	]));

    setup();
   replace_program(ROOM);
}

 
