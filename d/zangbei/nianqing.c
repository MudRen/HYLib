 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��ѩɽ");
        set("long", @LONG
��ѩɽ�����ֽС����๱�����ɹ���������������ȫ����������಻Զ����Ʒ
�������е�ѩ����ɡ����������գ��Ϸ������£�������ŵ�༪������ѩ���ף�
�ͰΣ�������ֱ�������������ഫ��ת����������ѩɽ����������ɱ�����������
��תʮ�����ɽ���µĳ���¾��൱����һ�����صĹ��¡�
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"mount1",
                "south":  __DIR__"mount2",
                "east":  __DIR__"mount3",
                "westdown": __DIR__"diyugu2",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}   
