//Cracked by Roath
// road: /zhongnan/shulin5.c

inherit ROOM;

void create()
{
		  set("short","����");

		  set("long",@LONG
��λ�����ɽ���һ��Ƭ���֣�������Ϊï�ܡ�������䣬ֻ���ý�
��ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩��Ũ�ܵ�֦ͷ��Ͷ��
���¡�ż��Զ�������޺�����������һ�����ܸС��������ϸ���һ��С����
LONG);

		  set("exits",([ "north" : __DIR__"shulin4",
"south" : __DIR__"shulin6",
						  ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");

        setup();

}

#include "caiyao.h"
