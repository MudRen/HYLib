 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����ɽ");
        set("long", @LONG
����ָ���Ǹ�ɽ�ϵĺ����������ԭ��ɽ�Ͼ�Ȼ�м��ٸ�����������ղ�����
���µ����ᣬɢ����������ʯ�䡣��������ǵء�ǧ��ٹ�ȴ������汸����Ȼʯ
��������������˿־壬����������Ӱ���ʫ����ǰ����ʯ�ˣ��󲻼����ߣ�����
��֮���ƣ�����Ȼ�����¡���
LONG
        );
        set("exits", ([ 
                "northdown" : __DIR__"valley2",
                "southeast":  __DIR__"lake1",
        ]));
	set("objects", ([
"quest/skills2/wakuang/kuang/kuangmai" : 2,
	])); 
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}   
