//Cracked by Roath
// road: /zhongnan/shulin2.c

inherit ROOM;

void create()
{
        set("short","����");

        set("long",@LONG
��λ�����ɽ���һ��Ƭ���֣�������Ϊï�ܡ�������䣬ֻ���ý�
��ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩��Ũ�ܵ�֦ͷ��Ͷ��
���¡�ż��Զ�������޺�����������һ�����ܸС�����������������һ��
С����
LONG);

        set("exits",([ 
        "south" : __DIR__"shulin3",
        "north" : __DIR__"shulin1",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");

        setup();

}

#include "caiyao.h"

