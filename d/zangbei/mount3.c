 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�����");
        set("long", @LONG
����壬�����˽С���ŵ�༪����ˮ��ʯ���ɽ���Ȼ���ţ������꣬�۽���
�㣬������ȡ�ѩ���±���ֱ����̵�ԭʼɭ�֡�ѩɽ���ͱڡ����¡����ӡ�������
�ݳ���ɭ�֡�Ϫ����һƬ���ס����ꡣ
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"nianqing",
                "northeast":  __DIR__"mugecuo",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
} 
