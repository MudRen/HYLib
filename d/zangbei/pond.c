 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "���");
        set("long", @LONG
����Ϧ���������Ϧ�����������⡣���Ĳ������������ˣ�������ȷ���㣬
���˺ܶ��㣬�����������ʱ�������ὫС�������Լ��Ȳ�ĸ����С������ʱ��
������������Щ���������һ�𾲾�������ˮ���ԣ�������ױߣ���������������
ˮ��������Ȼ�Եõ���̬��������������ơ�
LONG
        );
        set("exits", ([ 
                "southeast" :   __DIR__"sroad3",
        ]));
        set("objects", ([
                __DIR__"npc/hantang":   1,
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}    
