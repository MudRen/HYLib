// Room: /u/poq/sdxl/donghou.c ����
// by poq 97/7
//   alter dubei
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    set("short", BLU "����"NOR);
    set("long", @LONG
���Ų��ߵ�����ֻ����ľ�Դ䣬ɽ����ѡ������Ƕ��͵�ʯ�ڣ�
��������һ��С·��֪ͨ������ȥ��
LONG
    );

    set("outdoors", "shengu");

    set("exits", ([
        "enter" : __DIR__"shandong",
        "north" : __DIR__"qiaobi",
 		"northwest" : __DIR__"baihuagu/ent",
 		"south" : __DIR__"heizhao/shanlu1",
    ]));

    setup();
    replace_program(ROOM);
}
