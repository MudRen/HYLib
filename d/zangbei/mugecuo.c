 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����");
        set("long", @LONG
�������ֽ�ľ��룬��Բ����ߵ����������ɽɫ���·������������ɾ���
����һ�ն�䣺�峿��̹������ĺ��澲�羵�棬��ӳ��ѩ���Ⱥɽ������ι�
��������������ɽ�ȣ�����Ϧ����б����������ö�Ŀ���������档
LONG
        );
        set("exits", ([ 
                "southwest" : __DIR__"mount3",
                "northeast":  __DIR__"spring",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}        
