 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "���ɽ");
        set("long", @LONG
�����ж��ɽ����˼���������ɽ��ɽ��ƽ����������ããԭʼɭ�֣��＾��
�־�Ⱦ����ɽ��飬���������������⡣����ɽ��Զ�������ϵĺ���ɽ����ɽ�彻
�����������ֳ�����ĵ����ȣ����ܵ��ﴫ˵�е���ɽ�������ɹ���ѩ�塣����
ɽ���³����ӵĶ԰����Ǳ߳ǡ�
LONG
        );
        set("exits", ([ 
                "southwest":  __DIR__"valley1",
                "eastdown":             __DIR__"hellvalley1",
                "northdown":            "/d/xinjiang/hongshan",	
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",-1120);
        set("coor/y",2100);
        set("coor/z",20);
        setup(); 
}   
