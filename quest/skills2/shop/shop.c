// zhujia.c ���׷�
// ����lywin 2000/9/2 

#include <ansi.h>
inherit ROOM;

 void create()
{
        set("short", "ʥ������");
        set("long", @LONG
������ȫ����õı�����,����ı���ȫ��һ����,Ʒ����ȫ��
�������������ȫ�Ƿ���Ʒ,��˵�Ƿ���Ʒ,��Ҳ�������ߴ�
���������ֵ�.
LONG
        );

        set("exits", ([
                "west" : "d/pingan/dong2",
        ]));
	set("objects", ([
		__DIR__"shopman" : 1,
	])); 

        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        setup();
}

