 inherit ROOM;
#include <ansi.h>
void create() 
{
        set("short", "С����ˮ");
        set("long", @LONG
���ɫ�ĳ�������ɽ�ּ䡢Ȫˮ�������ֽ���һ�������Ʈ��Ʈɢ��Զ����
С���Ե����������м������߳���������������Ů�������ߴ��ź�Ƿ���������ŷ�
�ŵ�ս�֡��������㲻��������õ���ľ���õ�Ů�ˣ��������������Լ���
��Ϊ��Զ�޷�ʵ�ֵ����롣ֻҪ�㹻��������������������������˵�����
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"bigtree",
                "west":  __DIR__"happywood",
                "east":  __DIR__"happyroom",
        ]));
        set("objects", ([
                __DIR__"npc/huhua": 1,
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}  
