 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��ɽ·");
        set("long", @LONG
·��ɽת������ɽ�䣬�����Բһ�����н���Ȫ�ۣ���Ϊ��ҩ�ط�Ȫ������˵
��ͬ��Ȫˮ���в�ͬ����Ч�������˰����Ƿ�Ϊ��ĿȪ����θȪ��ϴ��Ȫ�ȡ�Զ����
�ɼ�������Ұţ��¹���ܡ��ǡ���ȶ��ﾢ�����¾����������������ɼ�����
Ѽ���Ϸˮ���������ˡ�
LONG
        );
        set("exits", ([ 
                "southwest" : __DIR__"mugecuo",
                "northeast":  __DIR__"linchang1",
                "westdown":   __DIR__"river",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
} 
