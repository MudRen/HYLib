 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����������");
        set("long", @LONG
���๱�����ɹ���������ǰ�������㿴��������֦��һ���ޱ��޼ʵ�ɡ����ס
�����⣬��ס����գ����ó�ʪ����Ҷ�ڽ��·�����֨�����������ܵ���֦������
��Ұ�ݲ�ʱ��סȥ·������ÿ��һ��·��Ҫͣ����ЪһЪ����������Ũ�ص���ʪ��
Ϣ������������
LONG
        );
        set("exits", ([ 
                "east":  __DIR__"diyugu2",
        ]));
        set("objects", ([
                __DIR__"npc/wolf":      4,
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
} 
